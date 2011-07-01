
#include "database.h"
#include "table.h"

#include "recordsupermodel.h"
#include "recorddrag.h"

QModelIndexList RecordDataTranslatorInterface::appendRecordList(RecordList rl, const QModelIndex & parent )
{
	return insertRecordList(model()->rowCount(parent),rl,parent);
}

const char * RecordDataTranslatorInterface::IfaceName = "RecordDataTranslatorInterface";

const void * RecordDataTranslatorInterface::iface( const char * iface ) const
{
	return strcmp(iface,IfaceName) == 0 ? this : 0;
}

const RecordDataTranslatorInterface * RecordDataTranslatorInterface::cast( const ModelDataTranslator * trans )
{ return trans ? (const RecordDataTranslatorInterface*)trans->iface(IfaceName) : 0; }

void RecordDataTranslatorBase::setRecordColumnList( QStringList columns, bool defaultEditable )
{
	mColumnEntries.resize( columns.size() );
	int i = 0;
	foreach( QString col, columns ) {
		ColumnEntry & ce = mColumnEntries[i++];
		ce.columnName = col;
		ce.editable = defaultEditable;
		ce.columnPos = -1;
		ce.foreignKeyTable = false;
	}
}

void RecordDataTranslatorBase::setColumnEditable( int column, bool editable )
{
	if( column >= 0 && mColumnEntries.size() > column )
		mColumnEntries[column].editable = editable;
}

QString RecordDataTranslatorBase::recordColumnName( int column ) const
{
	if( column >= 0 && mColumnEntries.size() > column )
		return mColumnEntries[column].columnName;
	return QString();
}

int RecordDataTranslatorBase::recordColumnPos( int column, const Record & record ) const
{
	if( column >= 0 && mColumnEntries.size() > column ) {
		ColumnEntry & ce = mColumnEntries[column];
		if( ce.columnPos == -1 ) {
			Table * t = record.table();
			if( t && t->schema() ) {
				Field * f = t->schema()->field( ce.columnName );
				if( f ) {
					ce.columnPos = f->pos();
					ce.foreignKeyTable = f->foreignKeyTable();
				}
			}
		}
		return ce.columnPos;
	}
	return -1;
}

bool RecordDataTranslatorBase::columnIsEditable( int column ) const
{
	return column >= 0 && mColumnEntries.size() > column && mColumnEntries[column].editable;
}

TableSchema * RecordDataTranslatorBase::columnForeignKeyTable( int column ) const
{
	if( column >= 0 && mColumnEntries.size() > column )
		return mColumnEntries[column].foreignKeyTable;
	return 0;
}

void RecordItem::setup( const Record & r, const QModelIndex & )
{
	record = r;
}

#include <typeinfo>

QVariant RecordDataTranslatorBase::recordData(const Record & record, const QModelIndex & idx, int role) const
{
	if( role == Qt::DisplayRole || ( role == Qt::EditRole && columnIsEditable(idx.column())) )
	{
		QVariant v = record.getValue( recordColumnPos( idx.column(), record ) );
		TableSchema * fkt = columnForeignKeyTable( idx.column() );
		if( fkt && fkt->field( "name", /*silent=*/true ) ) {
			return fkt->table()->record( v.toInt() ).getValue( "name" );
		} else if( fkt && fkt->field( fkt->tableName(), /*silent=*/true ) ) {
			return fkt->table()->record( v.toInt() ).getValue( fkt->tableName() );
		}
		return v;
	}
	return QVariant();
}

bool RecordDataTranslatorBase::setRecordData(Record record, const QModelIndex & idx, const QVariant & value, int role)
{
	Q_UNUSED(role);
	if( columnIsEditable( idx.column() ) ) {
		record.setValue( recordColumnPos( idx.column(), record ), value );
		return true;
	}
	return false;
}

Qt::ItemFlags RecordDataTranslatorBase::recordFlags(const Record &, const QModelIndex & idx) const
{
	Qt::ItemFlags ret( Qt::ItemIsEnabled | Qt::ItemIsSelectable );
	if( columnIsEditable( idx.column() ) )
		ret = Qt::ItemFlags( ret | Qt::ItemIsEditable );
	return ret;
}

int RecordDataTranslatorBase::recordCompare( const Record &, const Record &, const QModelIndex &, const QModelIndex &, int, bool ) const
{
	return 0;
}

bool RecordTreeBuilder::hasChildren( const QModelIndex & parentIndex, SuperModel * model )
{
	RecordSuperModel * rsm = qobject_cast<RecordSuperModel*>(model);
	const RecordDataTranslatorInterface * rdt = RecordDataTranslatorInterface::cast(rsm->translator(parentIndex));
	if( rdt ) {
		RecordList kids = rdt->children(parentIndex);
		return kids.size();
	}
	return false;
}

void RecordTreeBuilder::loadChildren( const QModelIndex & parentIndex, SuperModel * model )
{
	RecordSuperModel * rsm = qobject_cast<RecordSuperModel*>(model);
	const RecordDataTranslatorInterface * rdt = RecordDataTranslatorInterface::cast(rsm->translator(parentIndex));
	if( rdt && rsm ) {
		RecordList kids = rdt->children(parentIndex);
		if( kids.size() )
			rsm->append( kids, parentIndex );
	}
}

GroupingTreeBuilder::GroupingTreeBuilder( SuperModel * model )
: RecordTreeBuilder( model )
, mStandardTranslator( 0 )
, mCustomTranslator( 0 )
, mGroupColumn( 0 )
, mIsGrouped( false )
{
	connect( model, SIGNAL( rowsInserted(const QModelIndex &, int, int) ), SLOT( slotRowsInserted( const QModelIndex &, int, int) ) );
}

ModelDataTranslator * GroupingTreeBuilder::groupedItemTranslator() const
{
       if( !mCustomTranslator && !mStandardTranslator ) {
               // I could make it mutable, but what fun would that be?
               GroupingTreeBuilder * me = const_cast<GroupingTreeBuilder*>(this);
               me->mStandardTranslator = new StandardTranslator(me);
       }
       return mCustomTranslator ? mCustomTranslator : mStandardTranslator;
}

void GroupingTreeBuilder::setGroupedItemTranslator( ModelDataTranslator * trans )
{
       if( trans == groupedItemTranslator() ) return;
       bool grouped = mIsGrouped;
       if( grouped )
               ungroup();
       // Because all ModelDataTranslators are owned by the treeBuilder(mTranslators list),
       // we don't have to do any memory management here
       mStandardTranslator = 0;
       mCustomTranslator = trans;
       if( grouped )
               groupByColumn(mGroupColumn);
}

void GroupingTreeBuilder::groupByColumn( int column ) {
	// Single level grouping for now
	if( mIsGrouped ) ungroup();
	
	mGroupColumn = column;
	int count = model()->rowCount();
	if( count > 0 )
		groupRowsByColumn( mGroupColumn, 0, count - 1 );
	
	mIsGrouped = true;
}

QModelIndexList fromPersist( QList<QPersistentModelIndex> persist)
{
	QModelIndexList ret;
	foreach( QModelIndex idx, persist ) ret.append(idx);
	return ret;
}

void GroupingTreeBuilder::groupRowsByColumn( int column, int start, int end )
{
	// First group the top level indexes by the desired column
	typedef QMap<QString,QList<QPersistentModelIndex> > GroupMap;
	GroupMap grouped;
	QModelIndexList topLevel;
	for( int i = start; i <= end; ++i ) {
		QModelIndex idx = model()->index( i, column );
		// Double check that this isn't a group item, even though it shouldn't be
		if( model()->translator(idx) != mStandardTranslator ) {
			topLevel += idx;
			grouped[model()->data( idx, Qt::DisplayRole ).toString()] += idx;
		}
	}
	
	// If we are already grouped, we need to insert items into existing groups before creating new ones
	if( mIsGrouped ) {
		for( ModelIter it(model()); it.isValid(); ++it ) {
			// Found a group item
			if( model()->translator(*it) == groupedItemTranslator() ) {
				QModelIndex groupIdx = model()->index( (*it).row(), column );
				QString groupVal = groupIdx.data( Qt::DisplayRole ).toString();
				GroupMap::Iterator mapIt = grouped.find( groupVal );
				if( mapIt != grouped.end() ) {
					model()->move( fromPersist(mapIt.value()), *it );
					grouped.erase( mapIt );
				}
			}
		}
	}
	
	if( grouped.size() ) {
		
		QList<QPersistentModelIndex> persistentGroupIndexes;
		// Append the group items, yet to be filled with data and have the children copied
		{
            mInsertingGroupItems = true;
            QModelIndexList groupIndexes = model()->insert( QModelIndex(), model()->rowCount(), grouped.size(), groupedItemTranslator() );
            mInsertingGroupItems = false;
			foreach( QModelIndex idx, groupIndexes ) persistentGroupIndexes.append(idx);
		}
		
		// Set the group column data, and copy the children
		int i = 0;
        for( QMap<QString, QList<QPersistentModelIndex> >::Iterator it = grouped.begin(); it != grouped.end(); ++it, ++i ) {
            QModelIndex groupIndex = persistentGroupIndexes[i];
            if( mCustomTranslator )
                mCustomTranslator->constructData( mCustomTranslator->dataPtr( groupIndex ) );
			model()->move( fromPersist(it.value()), groupIndex );
		}

        i = 0;
        for( QMap<QString, QList<QPersistentModelIndex> >::Iterator it = grouped.begin(); it != grouped.end(); ++it, ++i ) {
            QModelIndex groupIndex = persistentGroupIndexes[i];
            if( mStandardTranslator )
                mStandardTranslator->data(groupIndex).setModelData( groupIndex.sibling(groupIndex.row(), column), QVariant( it.key() ), Qt::DisplayRole );
            if( mCustomTranslator ) {
                mCustomTranslator->constructData( mCustomTranslator->dataPtr( groupIndex ) );
                model()->setData( groupIndex, QVariant(column), GroupingColumn );
                model()->setData( groupIndex, QVariant(it.key()), GroupingValue );
            }
        }
	}
}

void GroupingTreeBuilder::ungroup()
{
	// If we disable auto sort, we can ensure that the group indexes wont change
	// because the new indexes will be appended
	bool autoSort = model()->autoSort();
	model()->setAutoSort( false );

	// Clear this here so that when we start moving the items back to root level
	// the slotRowsInserted doesn't try to regroup them
	mIsGrouped = false;
	
	// Collect a list the top level(group) items, and the second level items
	QModelIndexList topLevel;
	QModelIndexList children;
	for( ModelIter it(model()); it.isValid(); ++it ) {
        if( model()->translator(*it) == groupedItemTranslator() ) {
			topLevel += *it;
			children += ModelIter::collect( (*it).child(0,0) );
		}
	}
	// Copy the second level items to root level
	model()->move( children, QModelIndex() );
	
	// Remove the group items
	model()->remove( topLevel );

	if( autoSort ) {
		model()->setAutoSort( true );
		model()->resort();
	}

	mGroupColumn = 0;
}

void GroupingTreeBuilder::slotRowsInserted( const QModelIndex & parent, int start, int end )
{
	// Move any new rows into their proper groups
	if( mIsGrouped && !parent.isValid() && !mInsertingGroupItems )
		groupRowsByColumn( mGroupColumn, start, end );
}

RecordSuperModel::RecordSuperModel( QObject * parent )
: SuperModel(parent)
{
	setTreeBuilder( new GroupingTreeBuilder(this) );
}

bool RecordSuperModel::setupIndex( const QModelIndex & i, const Record & r )
{
	RecordDataTranslatorInterface * rdt = recordDataTranslator(i);
	if( rdt ) {
		rdt->setup(i,r);
		return true;
	}
	return false;
}

void RecordSuperModel::updateIndex( const QModelIndex & i )
{
	if( setupIndex(i,getRecord(i)) )
		dataChanged(i,i);
}

Record RecordSuperModel::getRecord(const QModelIndex & i) const
{
	if( !i.isValid() ) return Record();
	RecordDataTranslatorInterface * rdt = recordDataTranslator(i);
	if( rdt )
		return rdt->getRecord(i);
	//LOG_1( "No RecordDataTranslator found for index" );
	return Record();
}

RecordList RecordSuperModel::listFromIS( const QItemSelection & is )
{
	RecordList ret;
	foreach( QItemSelectionRange sr, is ) {
		QModelIndex i = sr.topLeft();
		do {
			ret += getRecord(i);
			i = i.sibling( i.row() + 1, 0 );
		} while( sr.contains(i) );
	}
	return ret;
}

void RecordSuperModel::listen( Table * t )
{
	connect( t, SIGNAL(added(RecordList)), SLOT(append(RecordList)) );
	connect( t, SIGNAL(removed(RecordList)), SLOT(remove(RecordList)) );
	connect( t, SIGNAL(updated(Record,Record)), SLOT(updated(Record)) );
}

QModelIndexList RecordSuperModel::findIndexesHelper( RecordList rl, bool recursive, const QModelIndex & index, bool retAfterOne, bool loadChildren )
{
	QModelIndexList ret;
	for( ModelIter it(index); it.isValid(); ++it ) {
		QModelIndex i = *it;
		Record r = getRecord(i);
		if( rl.contains(r) )
			ret += i;
		if( recursive && (loadChildren || childrenLoaded(i)) ) {
			QModelIndex child = i.child(0,0);
			if( child.isValid() )
				ret += findIndexesHelper( rl, true, child, retAfterOne, loadChildren );
		}
		if( ret.size() && retAfterOne )
			break;
	}
	return ret;
}

QModelIndex RecordSuperModel::findIndex( const Record & r, bool recursive, const QModelIndex & parent, bool loadChildren )
{
//	mDisableChildLoading = true;
	QModelIndexList results = findIndexesHelper( RecordList() += r, recursive, index(0,0,parent), true, loadChildren );
//	mDisableChildLoading = false;
	return results.size() ? results[0] : QModelIndex();
}

QModelIndexList RecordSuperModel::findIndexes( RecordList rl, bool recursive, const QModelIndex & parent, bool loadChildren )
{
//	mDisableChildLoading = true;
	QModelIndexList results = findIndexesHelper( rl, recursive, index(0,0,parent), false, loadChildren  );
//	mDisableChildLoading = false;
	return results;
}

QModelIndex RecordSuperModel::findFirstIndex( RecordList rl, bool recursive, const QModelIndex & parent, bool loadChildren )
{
//	mDisableChildLoading = true;
	QModelIndexList results = findIndexesHelper( rl, recursive, index(0,0,parent), true, loadChildren );
//	mDisableChildLoading = false;
	return results.size() ? results[0] : QModelIndex();
}

RecordList RecordSuperModel::getRecords( const QModelIndexList & list ) const {
	RecordList ret;
	foreach( QModelIndex i, list )
		if( i.isValid() )
			ret += getRecord(i);
	return ret;
}

void RecordSuperModel::setupChildren( const QModelIndex & parent, const RecordList & rl )
{
	// Avoid reentrancy problems
	Database::current()->pushQueueRecordSignals( true );

	clearChildren(parent);
	
	ModelDataTranslator * trans = translator(parent);
	if( !trans ) trans = treeBuilder()->defaultTranslator();

	const RecordDataTranslatorInterface * rdt = RecordDataTranslatorInterface::cast(trans);
	if( rdt )
		const_cast<RecordDataTranslatorInterface*>(rdt)->appendRecordList( rl, parent );
	
	Database::current()->popQueueRecordSignals();
}

void RecordSuperModel::setRootList( const RecordList & rl )
{
	setupChildren(QModelIndex(),rl);
	reset();
	checkAutoSort();
}

RecordList RecordSuperModel::rootList() const
{
	return getRecords( ModelIter::collect(index(0,0)) );
}

QMimeData * RecordSuperModel::mimeData(const QModelIndexList &indexes) const
{
	return RecordDrag::toMimeData( getRecords(indexes) );
}

QStringList RecordSuperModel::mimeTypes() const
{
  return QStringList() << RecordDrag::mimeType;
}

/* subclass this */
bool RecordSuperModel::dropMimeData ( const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent )
{
	RecordList rl;
	if( parent.isValid() && RecordDrag::decode( data, &rl ) ) {
		Record other = getRecord(parent);
		foreach( Record r, rl ) {
			LOG_5( "Dropping record: " + r.table()->tableName() + ":" + QString::number( r.key() ) + " on record: " + other.table()->tableName() + ":" + QString::number( other.key() ) );
		}
		return true;
	}
	return SuperModel::dropMimeData(data,action,row,column,parent);
}

// This function should be O(n * log n)
void RecordSuperModel::updateRecords( RecordList newRecords, const QModelIndex & parent, bool updateRecursive, bool loadChildren )
{
	typedef QMap<Record, QModelIndexList> RecordIndexListMap;
	RecordIndexListMap existingMap;
	QModelIndex startIndex = parent.isValid() ? parent.child(0,0) : index(0,0);
	// O(n) iteration with O(log n) per loop give O(n log n )
	for( ModelIter it( startIndex, updateRecursive ? ModelIter::Recursive : ModelIter::Filter() ); it.isValid(); ++it ) {
		// Constant time
		Record r = getRecord(*it);
		if( r.isRecord() )
			// O(log n)
			existingMap[r] += *it;
	}
	
	QModelIndexList toUpdate;
	RecordList toAdd;
	// O(n) iteration
	foreach( Record n, newRecords ) {
		// O(log n)
		RecordIndexListMap::Iterator it = existingMap.find( n );
		// Constant + allocs
		if( it == existingMap.end() )
			toAdd += n;
		else {
			toUpdate += it.value();
			it.value().clear();
		}
	}
	
	// O(n)
	QModelIndexList toRemove;
	for( RecordIndexListMap::Iterator it = existingMap.begin(); it != existingMap.end(); ++it ) {
		if( it.value().isEmpty() )
			continue;
		// Constant + alloc
		toRemove += it.value();
	}
	
	// O(n)
	foreach( QModelIndex i, toUpdate )
		// Constant
		updateIndex(i);
	
	remove( toRemove );
	append( toAdd, parent );
}

void RecordSuperModel::remove( RecordList rl, bool recursive, const QModelIndex & parent )
{
	QModelIndexList indexes = findIndexes( rl, recursive, parent );
	remove( indexes );
}

QModelIndex RecordSuperModel::append( const Record & r, const QModelIndex & parent, RecordDataTranslatorInterface * trans )
{
	QModelIndexList ret = append( RecordList() += r, parent, trans );
	if( ret.size() == 1 ) return ret[0];
	return QModelIndex();
}

QModelIndexList RecordSuperModel::append( RecordList rl, const QModelIndex & parent, RecordDataTranslatorInterface * trans )
{
	return insert( rl, rowCount(parent), parent, trans );
}

void RecordSuperModel::updated( RecordList rl, bool recursive, const QModelIndex & parentIndex, bool loadChildren )
{
	QModelIndexList indexes = findIndexes( rl, recursive, parentIndex, loadChildren );
	foreach( QModelIndex i, indexes )
		updateIndex( i );
	checkAutoSort(parentIndex);
}

QModelIndexList RecordSuperModel::insert( RecordList rl, int row, const QModelIndex & parent, RecordDataTranslatorInterface * trans )
{
	if( !trans )
		trans = const_cast<RecordDataTranslatorInterface*>(RecordDataTranslatorInterface::cast(treeBuilder()->defaultTranslator()));
	if( trans )
		return trans->insertRecordList( row, rl, parent );
	return QModelIndexList();
}

RecordDataTranslatorInterface * RecordSuperModel::recordDataTranslator( const QModelIndex & i ) const
{
	ModelNode * node = indexToNode(i);
	if( !node ) node = rootNode();
	return const_cast<RecordDataTranslatorInterface*>(RecordDataTranslatorInterface::cast(node->translator(i)));
}

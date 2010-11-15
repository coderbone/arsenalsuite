if [ "v$V" == "v" ]; then
V=`date +%Y%m%d%H%M`
fi

if [ `uname -s` == "Linux" ]; then
ARCH="lin64"
PYPATH="/usr/lib/python2.5/site-packages"
SIPPATH="/usr/share/sip"
else
ARCH="osx"
PYPATH="/Library/Python/2.5/site-packages"
SIPPATH="/System/Library/Frameworks/Python.framework/Versions/2.5/share/sip"
fi

echo '***' release stone libs
STONEDIR=/drd/software/ext/stone/$ARCH/$V
mkdir $STONEDIR
rsync -avc $DESTDIR/usr/local/lib/libass* $STONEDIR/
rsync -avc $DESTDIR/usr/local/lib/libabsubmit* $STONEDIR/
rsync -avc $DESTDIR/usr/local/lib/libstone* $STONEDIR/
rsync -avc $DESTDIR/usr/local/lib/libclasses* $STONEDIR/
rsync -avc $DESTDIR/usr/local/lib/libbrainiac* $STONEDIR/
rsync -rvc --exclude=.svn cpp/lib/stone/include $STONEDIR/
rsync -rvc --exclude=.svn cpp/lib/stone/.out/*.h $STONEDIR/include/
rsync -rvc $DESTDIR/usr/bin/sip $STONEDIR/sip
rsync -rvc --exclude=.svn $SIPPATH/ $STONEDIR/sip.include/
rsync -rvc --exclude=.svn cpp/lib/stonegui/include $STONEDIR/
rsync -rvc --exclude=.svn cpp/lib/stonegui/.out/*.h $STONEDIR/include/

rsync -vc cpp/apps/classmaker/classmaker $STONEDIR/
rsync -vc cpp/apps/classmaker/classmaker.ini $STONEDIR/
mkdir $STONEDIR/templates
rsync -rvc cpp/apps/classmaker/templates/* $STONEDIR/templates/

echo '***' release python libs
rsync -rcv --exclude=wx* $DESTDIR/$PYPATH/blur /drd/software/ext/python/$ARCH/2.5/stone/$V/
rsync -rcv $DESTDIR/$PYPATH/sipconfig.py /drd/software/ext/python/$ARCH/2.5/stone/$V/
rsync -rcv $DESTDIR/$PYPATH/stoneconfig.py /drd/software/ext/python/$ARCH/2.5/stone/$V/

echo '***' release applications
DIR=/drd/software/ext/ab/$ARCH/$V
mkdir $DIR
rsync -cv cpp/apps/assburner_1_3/assburner $DIR/ab
rsync -cv cpp/apps/assburner_1_3/assburner.ini $DIR/ab.ini
rsync -cv cpp/apps/assburner_1_3/ab-offline.py $DIR/
rsync -rvc --exclude=.svn cpp/apps/assburner_1_3/plugins/ $DIR/plugins/
rsync -cv cpp/apps/assfreezer/assfreezer $DIR/af
rsync -cv cpp/apps/assfreezer/assfreezer.ini $DIR/assfreezer.ini
rsync -rvc --exclude=.svn cpp/apps/assfreezer/afplugins/ $DIR/afplugins/

rsync -cv cpp/apps/absubmit/absubmit $DIR/
rsync -cv cpp/apps/absubmit/py2ab.py $DIR/
rsync -cv cpp/apps/absubmit/maya/*py $DIR/
rsync -cv cpp/apps/absubmit/maya/*ui $DIR/
rsync -cv cpp/apps/absubmit/nukesubmit/nuke2AB.py $DIR/nukesubmit/
rsync -cv cpp/apps/absubmit/nukesubmit/*ui $DIR/nukesubmit/

rsync -cv python/scripts/manager.py $DIR/
rsync -cv python/scripts/reaper.py $DIR/
rsync -cv python/scripts/reaper_plugin_factory.py $DIR/
rsync -rcv python/scripts/reaper_plugins/ $DIR/reaper_plugins/
rsync -cv python/scripts/reclaim_tasks.py $DIR/
rsync -cv python/scripts/initab.py $DIR/

ln -s /drd/software/ext/ab/images $DIR/images

echo '***' released $V


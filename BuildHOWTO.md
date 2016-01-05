# Introduction #

These are detailed instruction on how to build and deploy Arsenal on Linux.

Please note you must use the supplied versions of SIP and PyQt. They are patched from the normal distro supplied ones.

# Details #

## Pre-requisites ##
  * Postgresql >= 8.3
  * Qt >= 4.6.2
  * standard gcc make tools
  * python >= 2.5
  * graphviz (development libraries) >= 2.22.0
  * mercurial
  * xmpppy

## Build ##
  1. checkout fresh copy from Subversion:
  1. build SIP
  1. build PyQt
  1. setup your site configuration file, config\_replacements.ini
  1. build Arsenal Freezer, Burner and absubmit tools

Sample build script:
```
# install all files with alternate prefix (optional)
export DESTDIR=~/install_root

export MAKEFLAGS=-j16

# use a non-system default python
export PYTHON=python2.5

export LD_LIBRARY_PATH=$DESTDIR/usr/local/lib
export PATH=$DESTDIR/usr/bin:$DESTDIR/usr/local/bin:/usr/local/Trolltech/Qt-4.6.2/bin:$PATH
export PYTHONVERSION=$($PYTHON -c "import sys; print 'python%s' % sys.version[:3]")
export PYTHONPATH=./python/:$DESTDIR/usr/lib/$PYTHONVERSION/site-packages

cd arsenalsuite

echo ### edit config_replacements.ini

if [ $# -lt 1 ]; then # Build everything if we just invoke the scripts without an argument
    $PYTHON build.py -color -command_only clean build install release sip
    $PYTHON build.py -color -command_only clean build install release sip:skip pyqt
    $PYTHON build.py -color -command_only clean build install release sip:skip pyqt:skip freezer burner pyabsubmit abscripts
elif [ $# -eq 1 -a $1 = "verbose" ]; then # Build everything verbosely if we specify verbose only
    $PYTHON build.py -color -command_only verbose clean build install release sip
    $PYTHON build.py -color -command_only verbose clean build install release sip:skip pyqt
    $PYTHON build.py -color -command_only verbose clean build install release sip:skip pyqt:skip freezer burner pyabsubmit abscripts
elif [ $# -eq 1 -a $1 = "allrpms" ]; then # Build the RPM packages
    $PYTHON build.py -color -command_only verbose build allrpms
else # Build only the modules we specify
    echo "Building modules $@" 
    $PYTHON build.py -color -command_only verbose clean build install release skip-ext-deps $@
fi


```

Sample config\_replacements.ini file
```
[Database]
DatabaseName=blur
Host=your-pgsql-host
User=databaseusername
Password=databasepasswd
SqlErrorEmailList=your.name@example.org

[Email]
Server=smtp.example.org
Domain=@example.org

```

## Troubleshooting FAQ ##

### Qt ###

I download qt-all-opensource-src-4.6.2.tar.gz from [ftp://ftp.trolltech.com/source/](ftp://ftp.trolltech.com/source/) with this configuration:

-qt-sql-psql -fast -no-qt3support

make sure to add -I and -L flags pointing to your postgresql dirs if not in your standard include/lib paths.

### Linux ###

make sure packages are installed:

fedora12:
  * libXScrnSaver-devel.x86\_64 0:1.1.3-2.fc11

fedora14:
  * yum install mercurial gcc gcc-c++ byacc python-devel postgresql-devel libXext-devel
  * build Qt 4.6.2 with ./configure -no-qt3support -qt-sql-psql -ptmalloc -fast -opensource -L /usr/lib/pgsql/ -I /usr/include/pgsql/


Ubuntu 10.04 - from a fresh desktop install
  * apt-get install g++ python2.6-dev qt4-dev-tools x11proto-xext-dev libpq-dev libxext-dev

ArchLinux - from a fresh netinstall
  * pacman -S xorg kde mercurial postgresql python2
  * build Qt 4.7.3 from source (no particular flags really)
  * Python 2.7 will be installed and is invoked by python2. Just 'python' will invoke Python 3. Make sure to set the PYTHON environment variable before attempting to compile arsenal.
  * If you are compiling as root while logged in as a regular user, do an "xhost +" in a terminal or classmaker will fail on compilation.

### Windows ###
  * set QMAKESPEC=win32-msvc2008
  * install nsis from http://nsis.sourceforge.net
    * install plugin http://nsis.sourceforge.net/Processes_plug-in into plugins/
    * put AddToPath.nsh into include/

### OSX ###

classmaker may not run correctly. If your build fails try:
```
cd cpp/apps/classmaker
./classmaker -s ../../lib/classes/schema.xml -o ../../lib/classes/
cd -
```
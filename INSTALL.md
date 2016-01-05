# Introduction #

Arsenal is still a developer release, so installation takes some number of steps.


# Details #

  * First, build Arsenal from source detailed in the [BuildHOWTO](BuildHOWTO.md)
  * Alternatively, download and install the RPM packages if they are available for your platform. The RPMs will install the software into /usr/local/
  * If you don't have a postgresql instance running, get that set up ( http://postgresql.org )
  * Configure and install the starter database
```
*from a fresh postgresql install*
- as user postgres: 
psql -c "create database blur;"
psql -c "create role burner with superuser inherit nocreaterole nocreatedb login password '<yourburnerpassword>';"
psql -c "create role farmer with superuser noinherit nocreaterole createdb login password '<yourfarmerpassword>';"
psql -c "create role farmers with nosuperuser inherit nocreaterole nocreatedb nologin;"
psql -c "create role freezer with nosuperuser inherit nocreaterole nocreatedb login password '<yourfreezerpassword>';"
psql -c "create role submitter with nosuperuser inherit nocreaterole nocreatedb login password '<yoursubmitterpassword>';"

psql blur < sql/blur_starter_db.sql
psql blur < sql/blur_starter_views.sql

If you are doing this remotely, replace the commands with:
psql -U postgres -h <host> etc
```

  * deploy the libraries, binaries, and config files. We use a central directory on shared storage. Every release is versioned, so multiple versions can be in production or testing at once. See bash/drd-release.sh for an example of this.
  * If you are using RPMs, you will need to modify the configuration files in /etc/ab. If you built Arsenal from source, these configuration files will be generated with the overrides specified in your config\_replacements.ini
  * start the server processes, these consist of the manager, reaper and reclaimer. I use daemontool services to run these
example manager script, this is invoked by daemontools via /services/manager/run
```
#!/bin/bash

# this uses an internal tool called the Launcher to get environment variables
OLDPATH=$PATH
for e in `/drd/software/int/bin/launcher.sh -p hf2 -d rnd -e farm --noSystem`; do export $e; done
export PATH=$PATH:$OLDPATH
cd /drd/software/ext/ab/lin64/$ABVERSION

exec /usr/bin/python2.5 manager.py -dbconfig ab.ini
```

example burner script, invoked by daemontools via /services/ab/run
```
cd /drd/software/ext/ab/$DRD_PLATFORM/$ABVERSION
exec nice -n 15 ./ab -nogui -no-psmon -config ./ab.ini -auto-register $*
```

  * create some users. You can use python/scripts/import\_users.py for this. It expects passwd formatted input, so you can do
```
cat /etc/passwd | python2.5 import_users.py

or for LDAP / AD

getent passwd | python2.5 import_users.py

or for NIS

ypcat passwd | python2.5 import_users.py
```
  * set any relevant Config options. There is a database table called config which various runtime config options are pulled from. The easiest way to modify these are by using pgAdmin-III, a very useful postgresql admin tool. Some key ones to set are:
```
jabberDomain
jabberSystemUser
jabberSystemPassword
jabberSystemResource

emailServer
emailSender

assburnerLogRootDir
```
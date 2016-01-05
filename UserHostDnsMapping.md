# Introduction #

For I.T. personnel a common request is "there's something wrong with my machine". Depending on your naming convention, asset management system, inventory tracking or memory - you need to know which machine is theirs.

# Details #

This is a simple database backed DNS system that tracks what machines a user is using for direct VNC, ssh, RDP, etc access.

ex.

```
$ host barry.robison.drd.users
barry.robison.drd.users is an alias for om012223.drd.int.
om012223.drd.int has address 10.19.33.167

$ host windows.barry.robison.drd.users
windows.barry.robison.drd.users is an alias for om012223.drd.int.
om012223.drd.int has address 10.19.33.167

$ host linux.barry.robison.drd.users
linux.barry.robison.drd.users is an alias for om012028.drd.int.
om012028.drd.int has address 10.19.33.3
```

user.name.your.domain will point to the most recent machine they have logged into, while OS.user.name.your.domain points to a specific operating system, which is handy when people have multiple machines.

Login scripts exist for osx, linux, windows which update the dns database. We use the open source "mydns" system running on a Linux host, with a Postgresql backend.

# Install #

  * install mydns http://mydns.bboy.net/ - on CentOS packages are in yum - mydns, mydns-pgsql
  * install CGI script and Apache config into conf.d/
  * install login scripts for each platform you want tracked


updateDaNS.cgi
```
#!/usr/bin/perl

use strict;
use CGI qw/:standard/;
use DBI;
use DBD::Pg;

print header, start_html('daNS 1.0');

my $hostname = param('hostname') || (print 'hostname required',br && exit );
my $username = param('username') || (print 'username required',br && exit );
my $os = param('os') || (print 'os required',br && exit );

my $dbh = DBI->connect("dbi:Pg:dbname=mydns;host=sql01.drd.int", "mydns", "Dns1", {AutoCommit => 1, RaiseError => 1});

# first delete the two rows we care about, then insert them.
# we do this so we don't have to select and then update..

my $deleteSql = qq|DELETE FROM rr WHERE name = ?|;
my $sth = $dbh->prepare($deleteSql);
$sth->execute( "$os.$username" );
$sth->execute( "$username" );

# make sure the hostname is properly formatted
if ($hostname !~ /.drd.int$/) { $hostname .= ".drd.int" }
$hostname .= ".";

my $insertSql = qq|INSERT INTO rr (zone, name, type, data, ttl) VALUES (?,?,?,?,?)|;
$sth = $dbh->prepare($insertSql);
$sth->execute( 2, $username, "CNAME", $hostname, 60 );
$sth->execute( 2, "$os.$username", "CNAME", $hostname, 60 );

print "database update successful for $username, $hostname, $os\n", br;
```

mydns.conf
```
NameVirtualHost *:80

<VirtualHost *:80>
    ServerName dns01.drd.int 
    ServerAdmin helpdesk@drdstudios.com
    DocumentRoot /var/www/html/
    ScriptAlias /cgi-bin/ /drd/software/int/sys/daNS/
<Location /cgi-bin>
    SetHandler cgi-script
    Options +ExecCGI
</Location>
    <Directory /var/www/html/>
        Options Indexes FollowSymLinks
    </Directory>
    ErrorLog logs/dns01.drd.int-error_log
    CustomLog logs/dns01.drd.int-access_log combined
</VirtualHost>
```

Linux
/etc/gdm/PostLogin/Default
```
#!/bin/sh

# DRD
echo "$0: recording login to this host"
wget "http://dns01.drd.int/cgi-bin/updateDaNS.cgi?username=$USER&hostname=$HOSTNAME&os=linux" -O /dev/null -q

/usr/bin/xhost +

exit 0
```

Windows
login.vbs
```
Dim objNetwork, ie
Dim strwho, strcomp

Set objNetwork = CreateObject("WScript.Network")
Set ie = CreateObject("InternetExplorer.Application")

strwho = objNetwork.username
strcomp = objNetwork.ComputerName
ie.Navigate "http://userdns01.fsm.int/cgi-bin/updateDaNS.cgi?username="&strwho&"&hostname="&strcomp&"&os=windows"
ie.Visible=False
```

OSX - install script
/usr/local/bin/installDaNS.sh
```
#!/bin/sh

/usr/bin/defaults write /Library/Preferences/loginwindow AutoLaunchedApplicationDictionary -array-add '{ "Path" = "/usr/local/bin/updateDaNS.command"; "Hide" = "1"; }'
```

OSX
/usr/local/bin/updateDaNS.command
```
#!/bin/bash
curl "http://dns01/cgi-bin/updateDaNS.cgi?username=$USER&hostname=$HOSTNAME&os=osx" &> /dev/null
killall Terminal
```
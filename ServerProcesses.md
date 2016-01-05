# Server Processes #

The following are all Python processes that run on your farm server.

## Verifier ##

The verifier makes sure jobs enter the queue healthy, and via various plug-ins controls initial priority.

Responsible for:
  * verifying Jobs after submission
  * this includes running through all plug-ins

Logs to:
  * /var/log/ab/verifier.log

## Reaper ##

The reaper examines running jobs generally makes sure the queue is healthy.

Responsible for:
  * processing dependencies for running jobs
  * suspending jobs raising errors
  * sending notifications
  * marking jobs "done"

Logs to:
  * /var/log/ab/reaper.log

## Manager ##

The managers primary purpose is to sort the queue according to various priorities and dispatch tasks to hosts.

Responsible for:
  * sorts Job list according to a sort key. Various sort key algorithms are available depending on your preference.
  * create JobAssignment records, this is what Hosts look for to start Burning a Task

Logs to:
  * /var/log/ab/manager.log

## Reclaimer ##

The reclaimer makes sure hosts are healthy and doing what they claim.

Responsible for:
  * finding Hosts that are not pulsing or not pingable
  * finding JobAssignments that have been dispatched to Hosts that are offline

Logs to:
  * /var/log/ab/reclaimer.log
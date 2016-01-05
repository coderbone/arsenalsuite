# Introduction #

Add your content here.


# Details #

When a job runs on the farm, the Burner processes everything it sends to stdout/stderr. This is interleaved using QProcess:MergedChannels.

Each line of output is passed to a function - slotProcessOutputLine - which examines it to see it it should be ignored or indicates that the task is complete, or an error has happened.


### Log file location ###

Log file lines ( which aren't ignored ) are streamed to a file. The file location is deterministic - /farm/logs/<last 3 digits of job key>/<job key>/

The Burner will buffer all output and flush to disk once every 30 seconds and when the task completes.

Housekeeping policies for how long we keep these files have not been established yet.
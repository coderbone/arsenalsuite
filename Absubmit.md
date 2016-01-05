# Introduction #

`absubmit` is the old style submitter. You should probably use or write python submitters instead. This page is for the "legacy" users.


# Details #

## Required keys ##
  * **user** - user submitting the job
  * **job** - the name of the job in the queue
  * **fileName** - path to the file to be ran
  * **jobType** - Maya7, Maya85, MentalRay85, AfterEffects7, Shake, Batch
  * **frameStart** - the # of the first task
  * **frameEnd** - the # of the last task

## Optional Keys ##
  * **outputPath** - the path to rendered frames, ie /mnt/projects/test/images/test\_layer1\_v001..sgi
  * **packetType** - random, sequential, continuous. What frame ranges will be allowed; random - any order (23,19,56); sequential - start at zero, but allow gaps (1-6,7,10); continuous - in order, no gaps (15-25)
  * **packetSize** - how many tasks to assign to a host at once. The longer running a task, the lower the packet size should be. The longer a packet takes to load, vs run each task, the higher this should be.
  * **host** - hostname of submitting machine
  * **deleteOnComplete** - 0,1; 1 means delete the job from the queue when it has sucessfully completed.
  * **notifyOnComplete** - a comma delimited list of users, and how to notify them. ie "todd:j,barry:e". This will notify todd via jabber, and barry via email when a job has completed.
  * **hostList** - a comma delimited list of hosts allowed to run the job.
  * **priority** - an int between 1-100, lower being more urgent. defaults to 50
  * **maxTaskTime** - how many seconds a job is allowed to run for, if it goes over this it will be cancelled. default 60 minutes
  * **maxLoadTime** - how many seconds a host is allowed to spend loading FileName, ie the time between when it is assigned and starts it's first task. default 0 (infinite)
  * **noCopy** - true,false; set to true if you aren't using the distributed FTP/BitTorrent method of submitting and distributing jobs.
  * **service** - a comma delimited list of additional Services this job requires to run. Useful for jobs that require multiple plugin licenses.
  * **projectName** - name of the show this job is for (i.e. smallville)
  * **deps** - key # of job this job will depend on

### Optional Keys per job type ###
#### Batch ####
  * **cmd** - the command string to execute
  * **passSlavesFramesAsParam** - true,false; useful if you want the range of tasks assigned to a host passed to the batch script.
#### Maya ####
  * **frameNth** - render every Nth frame only (byFrame in Maya)
  * **renderer** - Which renderer to use (MentalRay, MayaSW)
  * **camera** - name of the camera to render with
  * **projectPath** - path to the project settings to use
  * **width** - width in pixels
  * **height** - height in pixels
  * **append** - a string to append to the Render command executed
#### Shake ####
  * **frameRange** - if there's a single output (ie .mov, .avi), this is the frame range you wnat rendered.
  * **codec** - name of the codec if rendering a Quicktime
#### After Effects ####
  * **comp** - name of the composition to render
  * **width** - width of output in pixels
  * **height** - height of output in pixels
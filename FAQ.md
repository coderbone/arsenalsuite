# Introduction #

Frequently asked questions by developers and administrators.

### Which user does arsenal run the commands as? ###

As the user that the "ab" process is run under.

Some job type's support the "runasSubmitter" flag, which will use "su" under Linux / OSX. This wraps the command in a sub-shell to run with the permissions of the user who submitted the job.

### How is the farm log directory meant to be created? ###

If you're logging job results to disk by setting "assburnerLogRootDir" in the Config table, you'll need a directory prepared.

```
cd $abLogRoot
for d in `seq -w 0 999` do; mkdir $d; done
```

### How do dependencies work? ###

There are two types of dependencies supported by Arsenal.
  * soft - aka frame-level, task-level, or linked jobs. When a task from job A is complete, the same task # from the child job is free to run. Parent and children jobs need to have the same number of tasks for this to work. Parent and child jobs can use different packet sizes. ( aka "chunk size" )

  * hard - The parent job must be complete before any task in the child can run. Useful for movie generation, clean-up jobs, etc.


### If I need to add a custom job how do I add it? ###

Short answer: use Batch jobs to execute a shell, Python script or whatever that does what you want.

Long answer: write a custom Burner. Look at the Nuke, 3Delight, or other Burner plug-ins for examples. Adding a new jobType requires generating the database table, C++ and Python code templates and objects too. Meaning this requires an even longer tutorial...
# Introduction #

This section will introduce the farm user interface and will explain the different views and tools available to gain information about your renders.


## Cross Platform Status ##

Works on:
  * Linux
  * Windows
  * Mac OS X


## Introduction to Arsenal ##

### What is Arsenal? ###

Arsenal is the program we use to monitor all the work the artists need rendered on the farm.

### GUI Overview ###

This manual will go over each button, its functions and all the windows in Arsenal. This will be just a quick overview of the GUI, each part will have a detailed description in specified chapter in the manual as seen in the contents above.

Arsenal has two views, **Job View** and **Host View**.

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Overview_EDITED.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Overview_EDITED.jpg)

The above screenshot is in **Job View**, which has 3 main windows.
  1. Job list Window - This lists all the jobs going on the farm in rows with details listed in columns.
  1. Specific Job Window - Shows details of the job which is currently selected in the job list window (1.) This window has 5 tabs.
  1. Freezer - This displays the frame currently selected in the Specific Job Window (2.) This window does not show frames all the time, depends on what the selected job is. **EDIT** This window now has tabs, one for the image viewer and the other is for graphs that display frame render times, memory used and disk read and write speeds.

Here is the **Host List\*Overview:**

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_HostView_Overview.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_HostView_Overview.png)

### Tools ###

#### Overview ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Drop_Down_Menu_Tools.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Drop_Down_Menu_Tools.jpg)

| **Menu Option** | **Description** |
|:----------------|:----------------|
| **Host Service Matrix** | A list of all hosts, their current status and the services that can be run on them. |
| **User Service Matrix** | Lists all users on the far left column and what services have been allowed for that persons use. |
| **Project Weighting** | Lists the weights for projects. |
| **Project Reserve** | Lists the slot reserves for projects. |

#### Host Service Matrix ####

Lists all of the nodes (farm blades, users machines, ...), their current status and the services that can be run on them.

![http://wiki.arsenalsuite.googlecode.com/hg/images/Host_Service_Matrix.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Host_Service_Matrix.jpg)

The host is listed on the far left column with its current status. The following columns are the services which are either Enabled, Disabled or No Service for that specific computer. Above are 2 filters you can use to find a Host or Service quickly. The above image has an example of how the filter works.


#### User Service Matrix ####

Lists all users on the far left column and what services have been allowed for that persons use.

![http://wiki.arsenalsuite.googlecode.com/hg/images/User_Service_Matrix.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/User_Service_Matrix.jpg)

The limit is given as a number and determines the maximum number of slots that are allowed for use in the farm.

### Options ###

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Drop_Down_Menu_Options.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Drop_Down_Menu_Options.jpg)

| **Auto refresh Toggle** | Toggles the list refreshing automatically. The list will refresh every time you switch tabs and every 5 minutes by default. The settings of the auto refresh can be changed in the settings part of the options drop down menu. |
|:------------------------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Show Dependency Tree** | Toggles displaying the dependant jobs in a tree. This is also accessible on the toolbar.                                                                                                                                        |
| **New View From Selection** | This function is currently broken. It is suppose to create a new tab with the job(s) currently selected, so they are displayed on their own in a separate tab.                                                                  |
| **View My Jobs**        | Filters the list to display jobs owned by you. This option is also on the toolbar.                                                                                                                                              |
| **Filter**              | Toggles the Filter fields located above the main window. Shift+F is the shortcut.                                                                                                                                               |
| **Clear Filter**        | A set of options to specify which projects, job status and job types are displayed in the current view. These supersede any currently applied filter fields. It is recommended to filter out done jobs since there are quite a lot of done jobs. |
| **Job Filters**         | A set of options to specify which projects, job status and job types are displayed in the current view. These supersede any currently applied filter fields. It is recommended to filter out done jobs since there are quite a lot of done jobs. |
| **Display Preferences** | Change font and colour of the text for the jobs displayed. Purely for personal taste. Wrangler POV: Could help to quickly differentiate failing jobs.                                                                           |
| **Settings**            | Option to change the job display limit and to configure the Auto Refresh. Having a higher display limit increases time the refresh takes to load. The Auto refresh interval is by default 5 minutes. The other two auto refresh options are self explanatory. |

### View ###

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Drop_Down_Menu_View.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Drop_Down_Menu_View.jpg)

| **View Jobs** | Switches the current tab to the next **Job View** tab. Ctrl+J is the shortcut. |
|:--------------|:-------------------------------------------------------------------------------|
| **View Hosts** | Switches the current tab to the next **Hosts View** tab. Ctrl+H is the shortcut. |
| **New Job View** | Creates a new **Job View** tab, displaying all the jobs with default settings. |
| **New Host View** | Creates a new **Host View** tab, displaying all the Hosts (Farm Blades, User Machines...). |
| **Restore View** | This is not working.                                                           |
| **Clone Current View As** | Creates a copy of the current tab, including filter fields.                    |
| **Close Current View** | Closes the currently viewed tab. Ctrl+W is the shortcut.                       |
| **Rename Current View** | Renames the currently viewed tab.                                              |
| **Move Current View Left** | Moves the currently viewed tab to the left one place. Use this to rearrange tabs. Ctrl + Shift + Left is the shortcut. |
| **Move Current View Right** | Moves the the currently viewed tab to the right one place. Use this to rearrange tabs. Ctrl + Shift + Right is the shortcut. |
| **Save View To File** | Saves the current tabs and their filters to a file. Ctrl+S is the shortcut.    |
| **Load View From File** | Used to load a previously saved view file. Ctrl+O is the shortcut.             |

## Toolbar ##

![http://wiki.arsenalsuite.googlecode.com/hg/images/Freezertoolbarcrop.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Freezertoolbarcrop.png)

In order, the toolbar icons above represent:

| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Auto-Refresh.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Auto-Refresh.png) | Auto Refresh - The refresh rate can be changed in the Settings option of the Option Menu. The default is 5 minutes. |
|:------------------------------------------------------------------------------------------------------------------------------------------|:--------------------------------------------------------------------------------------------------------------------|
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Refresh.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Refresh.png)           | Refresh - Manually refresh the job list.                                                                            |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/04_-_Toolbar_-_Resume.png](http://wiki.arsenalsuite.googlecode.com/hg/images/04_-_Toolbar_-_Resume.png) | Resume - Resume the selected job(s).                                                                                |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Suspend.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Suspend.png)           | Pause - Pause the selected job(s).                                                                                  |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Remove.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Remove.png)             | Remove - Remove the selected job(s).                                                                                |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Restart.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Restart.png)           | Restart - Restart the selected job(s).                                                                              |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Toolbar_Filter.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Toolbar_Filter.png) | Filter - Toggle the filter fields in the current view.                                                              |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Clear_Filter.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Clear_Filter.png) | Clear Filters - Clear any data in the filters of the current view.                                                  |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/View_My_Jobs.png](http://wiki.arsenalsuite.googlecode.com/hg/images/View_My_Jobs.png) | View My Jobs - View all jobs created by you.                                                                        |
| ![http://wiki.arsenalsuite.googlecode.com/hg/images/Show_Dependecy_Tree.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Show_Dependecy_Tree.png) | Show Dependency Tree - Lists job in the current view in trees to show dependency between them.                      |

## Main Job View Window ##

### Job List View ###

The Main window of the Farm User Interface is broken up into many rows and columns which display various bits of information relating to a job that has been submitted to the farm for rendering. ![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window.jpg)

Jobs in the main window all have a colour applied to them, which relates to the current status of the job.

These are customizable by the individual user, but by default are:

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Colours.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Colours.jpg)


**EDIT** A recent update to Arsenal now shows the status of frames in colour and their location on the progress bar itself.

![http://wiki.arsenalsuite.googlecode.com/hg/images/Progress_bar_1.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Progress_bar_1.jpg)

The Columns of the main window break down into the following:

| **Key** | The key asigned to a farm job when it is submitted to the farm. |
|:--------|:----------------------------------------------------------------|
| **Job Name** | The Name given to a job on the Farm, usually containing the shot in which the job relates to, which version and other relevant information. |
| **Job Type** | Displays what type of job a farm job is, be it 3Delight, Batch, etc. |
| **Status** | The current status of a job running on the farm, which can be started, ready, holding, suspended, done, etc. |
| **Slots** | Displays how many slots a given job is using on the farm, 8 slots relates to being 1 computer or farmblade. |
| **Progress** | The current progress of a job displayed as a bar, with text containing how many frame's have been completed and the total to be processed. |
| **CPU Time** | The amount of time CPU's have spent working on frames for the listed job. |
| **Done, Total** | Displays the number of frames currently completed and the total to be processed. |
| **Avg. Time** | Displays the Average time it is taking to render each frame of a job based on frames that have completed. This Displays in CPU&nbsp;time, so how long it takes 1 core to complete a frame. For example it takes 1 minute for 8 cores to finish a frame, the CPU time is 8 minutes. |
| **Owner** | Shows the Owner of a job in the farm, being the User whom submitted the job to be rendered. |
| **Project** | The current project the current job falls under.                |
| **Priority** | The current priority applied to the job, which usually starts at 50 and goes lower (49,48,47 etc). |
| **Errors** | Displays the number of errors a job has, if any. See the error tab for a job specific error information (see section 1.5.2.2) |
| **Avg. Memory** | Shows the Average amount of memory used by frames in a job to render on the farm. |
| **Time in Queue** | A timer of how long a job has been in the farm que since it was originally submitted. |
| **Submitted** | Displays the date in which a job was submitted to the farm.     |
| **Ended** | Displays the date in which the job was completed on the farm.   |
| **Services** | Shows which services a job on the farm will use. eg. 3Delight, Batch, GPU, etc. |
| **Efficiency** | Percentage of resources actually used by a job on the farm (low efficiency if close to 0%, high efficiency if close to 100%), based on CPU&nbsp;and memory usage. |
| **Disk Write** | Shows how much data a job has written to storage.               |
| **Disk Read** | Shows how much data a job has read from storage.                |
| **Disk Ops** | Shows how many times or operations a job has written or read data. |
| **CPU Time** | Time a job spends rendering multiply by the number of CPUs it uses (1 min to render on 8 CPU&nbsp;means 8 min CPU&nbsp;Time). |
| **Queue Order** | Jobs place in a queue based on there Darwin's scores.           |

#### Right-Click Contextual Menu ####

By right clicking on a job, another menu will appear:

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu.jpg)

| **Refresh Job(s)** | Updates the entire job list with current information about the jobs. |
|:-------------------|:---------------------------------------------------------------------|
| **View Filters**   | Gives a list of different filters to use in the currently open tab (see section below). |
| **Open with..**    | See section 1.5.1.1.2 below.                                         |
| **Show Output Directory** | Shows the directory where the job is output to.                      |
| **Job Info**       | Displays all information in a window related to the job and is also editable. |
| **Job Statistics** | Shows statistics such as Total Job time, average time to complete task, error count, successful task time and error time. |
| **Job History**    | Shows all the frames or sections (Depending on packet size) and the status of each. Also displays which Hosts the job was allocated to. |
| **Modify frame range...** | Change the range of frames to be rendered for the selected job.      |
| **Set Job(s) Priority** | Change the Priority of the Job. Currently you can only lower priority so contact render operations to increase priority. |
| **Clear Jobs Errors** | Removes all errors from the error tab and column. Use show cleared errors to view all errors that were previously cleared. |
| **Remove&nbsp;Dependency** | Remove any job dependant on the currently selected job.              |
| **Resume Selected Jobs** | Resumes a suspended job from where it was stopped.                   |
| **Pause Selected Jobs** | Suspends a job.                                                      |
| **Remove Selected Jobs** | Deletes a job from the farm.                                         |
| **Restart Job(s)** | Starts the job from the beginning. Completely restarting the whole job. |


##### View Filters #####

This menu is divided in 5 sub-menus:

  * View My Jobs: View all jobs created by you.
  * Project Filter: Filter by project (anim, light, crowd...)

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Project_Filter.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Project_Filter.jpg)

  * Status Filter:&nbsp;Filter by job status.

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Status_Filter.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Status_Filter.jpg)

  * Job Type Filter: Filter by job type (3Delight, Maya, Mantra, Batch...)

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Job_Type_Filter.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Job_Type_Filter.jpg)

  * Set Limit: Allows you to set the number of job you want to display in Arsenal (1500 is recommended)

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Set_Job_Limit.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_View_Filters_Set_Job_Limit.png)

##### Open With #####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_Open_With.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Job_View_Contextual_Menu_Open_With.jpg)

| **Copy job info**| Copies Job Key, Owners Name and Job Name. Allows you to paste (Ctrl+V). |
|:-----------------|:------------------------------------------------------------------------|
| **[Shotgun](Shotgun.md) Support ticket** | Use this plugin on a job to notify the owner of a failed job or any other relevant issue. |
| **Toggle wrangle status** | Displays a lock icon to notify users and other wranglers that this job is currently being wrangled. |
| **rv**           | Use this plugin to see the actual frames and to play them in sequence.  |
| **shell**        | A shortcut to the Linux shell.                                          |

### Jobs Tabs Overview ###

#### Frames ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Tabs_For_Main_Window_Frames.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_Tabs_For_Main_Window_Frames.png)

| **Frame** | The Frame Number of a job. |
|:----------|:---------------------------|
| **Status** | The current Status of the frame on the farm (assigned, new, holding, done, canceled). |
| **Host**  | Which host has been assigned to render the frame. |
| **Time**  | Time the frame has been rendering for or how long it took to render on the farm. |
| **Loaded** | If you click a frame, it will attempt to load the output in the window next to frames tab, if it manages to load an image, this will display green, Otherwise it will display Red if it fails. |
| **Memory** | Tells you how much memory a frame is using or the max it used while rendering. |

##### Right-Click Menu #####

###### Default Menu ######

Right-clicking on a frame gives access to another bunch of options:

![http://wiki.arsenalsuite.googlecode.com/hg/images/Job_Window_Tab_Overview_Frames_Contextual_Menu.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Job_Window_Tab_Overview_Frames_Contextual_Menu.jpg)

| **Open output with** | See above section '1.5.1.1.2 Open With' |
|:---------------------|:----------------------------------------|
| **Connect to host**  | Access the host through SSH via a shell window |
| **Task Info...**     | Displays information about the frame.   |
| **Show Log...**      | Displays a log of all activity related to the frame, useful for when an error occurs on a frame. |
| **Show Log With...** | See below                               |
| **Show History**     | Displays the execution history of the task. |
| **Copy Command**     | Copies to the clipboard the command used to run the job. |
| **Select Host(s)**   | Select the hosts you want the frame to be run on. |
| **Rerender Frame**   | Rerenders the frame, if a problem has occurred rerendering on another host may solve the problem. |
| **Suspend Selected Frames** | Suspend the selected frames from being processed temporarily. |
| **Cancel Selected Frames** | Stop the frames from being processed.   |

###### 'Show Log With' Menu ######

![http://wiki.arsenalsuite.googlecode.com/hg/images/Job_Window_Tab_Overview_Frames_Contextual_Menu_Show_Log_With.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Job_Window_Tab_Overview_Frames_Contextual_Menu_Show_Log_With.jpg)

| **Firefox** | Displays the log file in Firefox. |
|:------------|:----------------------------------|

#### Errors ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Job_Window_Tab_Overview_Errors_Contextual_Menu.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Job_Window_Tab_Overview_Errors_Contextual_Menu.jpg)

| **Show Log** | Displays a log of all activity related to the frame, useful for when an error occurs on a frame. |
|:-------------|:-------------------------------------------------------------------------------------------------|
| **Show Log With...** | See above section 1.5.2.1                                                                        |
| **Copy Test of Selected Errors** | Copies the Error Message field of selected errors.                                               |
| **Show Cleared Errors** | Shows errors that has been previously cleared.                                                   |
| **Clear Selected Errors** | Clears the selected error(s) for the selected job.                                               |
| **Clear All Errors** | Clears all errors for the specified job.                                                         |
| **Error Info** | Displays the basic details of the error.                                                         |
| **Select Host(s)** | Allows you to select hosts for the error (will open a new host window on the selected host).     |
| **Exclude Selected Hosts From This Job** | Excludes the selected hosts from processing the job.                                             |
| **Clear All Errors From Host** | Clear all errors for a specific host.                                                            |
| **Clear All Errors From Host and Set It Offline** | Clears all errors for a host and sets it to offline so no jobs can be assigned to it.            |

#### History ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Tabs_For_Main_Window_History.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Tabs_For_Main_Window_History.png)

This tab relates everything that has happened to the selected job.

#### Notes ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Tabs_For_Main_Window_Notes.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Tabs_For_Main_Window_Notes.png)

Use to put a note on the selected job.

#### Jobs Settings ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Tabs_For_Main_Window_Job_Settings.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Tabs_For_Main_Window_Job_Settings.png)

##### General #####

| **Priority** | Priority on the farm (50 is default, 29 is department/project priority and 19 is urgent). |
|:-------------|:------------------------------------------------------------------------------------------|
| **Personal Priority** | No longer in use.                                                                         |
| **Delete On Completion** | Job is deleted from the farm when done.                                                   |
| **Prioritize Outer Tasks** | &nbsp;??????????????????????????????????????                                              |
| **All Hosts** | By default, all hosts will be selected to render the job.                                 |
| **Host List** | Gives a list of all the available hosts (in case you want to render on a specific host(s)). |
| **Environment** | Shows the render environment for a job.                                                   |

##### Notification #####

| **Email** | Tick the relevant boxes to be notified by an email when your job errored out or is finished |
|:----------|:--------------------------------------------------------------------------------------------|
| **Jabber** | Tick the relevant boxes to be notified by a jabber/pidgin message when your job errored out or is finished |

##### Packets #####

###### Packet Type: ######

There are 4 kind of packet type:

  * **Random:**

Frames are picked up randomly by the farm to be rendered.

<u>Example</u>: For a job with 200 frames, the farm will start rendering frame #145, then #2, etc...



  * **Continuous:**

Each set of frames (as per packet size) is rendered once at a time in an orderly manner.

<u>Example</u>: for a job with 20 frames with a packet size set to 5. Frame #1 to #5 will be rendered on a machine each at a time while frame #6 to #10 will be rendered on another machine each at a time as well.



  * **Sequential:**

This is a mix between random and continuous. It will take #number of frames randomly according to packet size to render them.

<u>Example</u>: if a job has 20 frames to render and a packet size set to 5, frames #10, #7, #19, #3 and #11 will be assigned to one machine, frames #12, #17, #1, #9 and #13 to another machine etc...



  * **Iterative:**

Frames are picked up every 10 frames.

This way, it helps having a quicker overview of the job rendered.

In this case, the packet size will always set to 1.

<u>Example</u>: if a job contains 30 frames, frames #1, #10, #20 and #30 will first be rendered, then frames #2, #11, #21 and so on so forth.

###### Packet Size ######

Number of frames send to 1 machine.

<u>Example</u>: job had 200 frame, if packet size=200 all the frame will be render on 1 machine.

###### Slots ######

A slot is a CPU core on a blade. Each blade has a 8 or 12 core CPU.

Rendering usually uses 8 slots (so 8 CPU cores) so there are 4 CPU that aren’t normally used. However, those left-overs can be used to render low priority jobs such as a still frame.

This field is related to the memory field under “Health Checks” part of the Job Settings tab.

Usually, a rendering job on 8 slots can use up to 16Gb of memory. A rendering job on 4 slots will use 8Gb.

##### Heath Checks #####

| **Max Task Minutes** | Max time allocated to render a single frame. |
|:---------------------|:---------------------------------------------|
| **Max Load Minutes** | Max load time allowed before suspension by the farm. |
| **Max Quiet Minutes** | Max quiet time allowed before suspension by the farm. |
| **Min Memory (MB)**  | Min amount of memory to render a frame.      |
| **Max Memory (MB)**  | Max amount of memory allowed to render a frame on the farm. |
| **Max Errors**       | Max numbers of allowed errors before suspension by the farm. |

##### Services #####

Name of the job type.

#### Graphs ####

Once you select a job in the main job view, two windows open, the bottom right window has two tabs. The first tab is the Image viewer, which shows the finished frame once completed, the other tab displays 4 useful graphs. The frame numbers are displayed on the X axis of each graph, with each colour coded bars representing a single frame. Hovering your mouse over these individual bars displays more accurate information about the frame.

![http://wiki.arsenalsuite.googlecode.com/hg/images/Graphs.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Graphs.jpg)

(These graphs indicate this job has completed its 10's without any failed frames and now has begun rendering all the frames. The concentrated areas of yellow bars are completed sections of the scene while the green section is currently rendering )

##### Frame Times (minutes) #####

This graph displays the amount of time the frame has taken/taking to render. It shows both CPU time (lighter coloured bar) and Wallclock time (darker coloured bar).

##### Frame Memory (MB) #####

This graph displays the amount of memory (RAM) the frame used when rendering.

##### Disk Read/Write (Ops and MB) #####

These 2 graphs display the read/write. Ops is Opererations the blade made for that frame, such as retrieving files. MB just shows how much was read/written to the disk. The bars going up (lighter colour) display how much was read and going down (darker colour) display how much was written. &nbsp;

##### Bars #####

Each bar in the graphs represents one frame, these bars are also colour coded based on status.

> Yellow is done

> Green is busy

> Blue is cancelled

> Red is suspended

> Frames that are new/holding are not displayed

## Main Host View Window ##

### Overview ###

![http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_HostView_Overview.png](http://wiki.arsenalsuite.googlecode.com/hg/images/Arsenal_HostView_Overview.png)

| **Host** | The Name of the Host |
|:---------|:---------------------|
| **Current Jobs** | The amount of jobs the host is involved in. |
| **Status** | Host status which can either be ready, offline, no-ping, no pulse, restart when done or reboot when done. |
| **Frames** | This column is not working!!! |
| **OS**   | The Operating System of the host machine, nearly all of them are Linux. |
| **Memory** | The total amount of RAM the Host Computer has. |
| **Mhz**  | The speed the host computer works at. (Calculated by Num Cores\*Core Mhz) |
| **User** | What user is logged in. |
| **Description** | Important information about the host, such as support ticket number if the host is having problems. |
| **Pulse** | The last time the Host sent a ping, just to check if it is still responsive. |
| **OS Version** | Host's Operating System Version. |
| **CPU Name** | Describes the type of computer. x86\_64 is the type of processor and means its a PC. i386 is a Mac. |
| **Arch** | Describes the type of operating system. x86\_64 means its a PC 64 bit operating system. i386 is a Mac 64 bit. |
| **Available Memory** | Available RAM for use for other jobs. |
| **Puppet Pulse** | Last time a blade software version were checked. |

### Right Click Contextual Menu Host View ###

#### Default Menu ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu.jpg)

| **Refresh Hosts** | Updates the entire job list with current information about the jobs. |
|:------------------|:---------------------------------------------------------------------|
| **ssh**           | Opens a Shell console ready to ssh into a Host.                      |
| **Set Host(s) Status to Online** | Changes the Hosts status to Online.                                  |
| **Set Host(s) Status to Offline** | Changes the Hosts status to Offline.                                 |
| **Restart Host(s) Now** | Restarts the Host Computer.                                          |
| **Restart Host(s) When Done** | Restarts the Hosts Computer when finished with current job.          |
| **Reboot Host(s) Now** | Hard reboot the Host Computer?                                       |
| **Reboot Host(s) When Done** | Hard reboot the Host Computer when finished with the current job?    |
| **Show Assigned Jobs** | This does not work, use Show history to view the assigned jobs.      |
| **Show Host Errors** | Show a list of errors that Host had.                                 |
| **Clear All Errors From Host** | Clears all errors associated with that host on all the jobs.         |
| **Clear All Errors From Host and Set it Offline** | Clears all errors associated with that host on all jobs and sets status to offline to prevent further use of the host. |
| **Assign Batch Job** | Assign a batch job to a specific host.                               |
| **Canned Batch Jobs** | Not used. See section 1.6.2.2 below.                                 |
| **Host Info**     | A list of properties and values of the host.                         |
| **Show History**  | Shows all the jobs that host was involved in and the statuses of those jobs. its a good way to see if that host is responsible for creating errors. |
| **Host Service Filter** | Allows you to narrow down what Hosts are enabled to use specific services, just like the Host Service Matrix in the tools drop down menu. |

#### Canned Batch Jobs ####

##### Admin #####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu_Canned_Batch_Job_Admin.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu_Canned_Batch_Job_Admin.jpg)

| **puppet** | Not used. |
|:-----------|:----------|
| **yum-update** | Not used. |
| **Tank Fuse restart** | Not used. |
| **Hyper Off** | Not used. |

##### DualBoot #####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu_Canned_Batch_Job_DualBoot.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu_Canned_Batch_Job_DualBoot.jpg)

| **Switch2Mac** | Not used. |
|:---------------|:----------|
| **Switch2Linux** | Not used. |
| **Switch to Mac** | Not used. |
| **Switch to Linux** | Not used. |

#### Host Service Filter ####

![http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu_Host_Service_Filters.jpg](http://wiki.arsenalsuite.googlecode.com/hg/images/Main_Window_Host_View_Contextual_Menu_Host_Service_Filters.jpg)

Allows to filter hosts by job type.
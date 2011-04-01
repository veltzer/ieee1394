This is the old firewire stack for new linux kernels
====================================================
* Why should you want this?
You may have some hardware and software (like audio recording software) that wants
the old firewire stack.

* What do you need to compile this?
make, gcc, kernel headers

* How do you build and install this?
- compile:
make modules
- install: 
sudo make modules_install
- load the modules:
sudo modprobe raw1394
sudo modprobe ohci1394
- now see that ffado-diag works...

* On which kernels should this work on?
You only need it for 2.6.37 and later kernels since it was only in the 37 cycle that
the old stack was removed. At the time of writing this it means that it is only applicable
for kernels 2.6.37 and 2.6.38. I see no reason that this should also work in the future
(meaning for 2.6.39 and later kernels).

* What is the output of all of this?
Three kernel modules which are installed in /lib/modules/`unamr -r`/extra
and are called ieee1394.ko ohci1394.ko and raw1394.ko.
You only need to load ohci1394.ko and raw1394.ko since they both depend on ieee1394.ko and will
trigger it's loading. For most application raw1394.ko will suffice.

* To which kernel am I compiling the modules if I follow the instructions above?
To the kernel you are running on the version of which you can find out using 'uname -r'

* What if I want to run on one kernel and compile to another?
Run the make commands above with KVER=[the version of the kernel you want the modules for].
For example:
mark@cantor:~/ieee1394$ make KVER=2.6.38.1-generic
OR
Edit the file 'Makefile', find the line that says 'KVER?=$(shell uname -r)'
and change it. For the same kernel as before it would become:
KVER?=2.6.38.1-generic
In this case no command line KVER is needed and it is actually counter productive
since it will override the version you put into the Makefile.

* How do I make this happen automatically on boot ?
- black list the new firewire stack
edit /etc/modprobe.d/blacklist-firewire.conf and turn it into:
=================================
# Select the legacy firewire stack over the new CONFIG_FIREWIRE one.

#blacklist ohci1394
#blacklist sbp2
#blacklist dv1394
#blacklist raw1394
#blacklist video1394

blacklist firewire-ohci
blacklist firewire-sbp2
=================================
Now rebuild the default collection of modules to be loaded...
TBD
- make the new stack load automatically on boot
TBD
- control the permission on the /dev/raw1394 file using udev
TBD
- run jack on boot
TBD

* Why did you do this? Are you insane?
Well - I saw a post on a patch for the old stack at
https://sicnarf.com/2011/running-the-old-firewire-stack-on-linux-2-6-38-rc3/ and after reviewing the patch
it occured to me that the patch is quite non intrusive and could easily be made into a standalone piece of
software which will ease it's use for many people since it will not require a kernel recompile (which a lot
of people are not that adapt at and which is turning a little bit harder with each passing day).
Half an hour later I had the patch ready with minimal edits to the code.

			Mark Veltzer, 2011
			mark.veltzer@gmail.com

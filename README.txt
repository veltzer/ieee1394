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
- make the new stack load automatically on boot
- control the permission on the /dev/raw1394 file using udev
- run jack on boot

			Mark Veltzer
			mark.veltzer@gmail.com

# CMPE283_Assignment2: Instrumentation via hypercall

In this assignments we will modify processor instruction behavior inside the KVM hypervisor. 

## Functionality to Implement
* To modify the CPUID emulation code in KVM to report back additional information 
when special CPUID leaf nodes are requested.

1.For CPUID leaf node %eax=0x4FFFFFFC:

*Return the total number of exits (all types) in %eax

2.For CPUID leaf node %eax=0x4FFFFFFD:

*Return the high 32 bits of the total time spent processing all exits in %ebx

*Return the low 32 bits of the total time spent processing all exits in %ecx

*%ebx and %ecx return values are measured in processor cycles, across all VCPUs


## Team of 2
## Aditya Kumar(016009968)
## Utkarsh Pant(015999321)

### Answer to Questions mentioned in the Assignment:
1. Parts of the Assignment performed by each member is as follows :
  * Aditya Kumar : Started with working on Assignmetn 1 environment on GCP VM, forked linux kernel source code and configured and build all the modules and kernel itself. Modified the kernel code as per the assignment 2 functionality. Reserached on how to interactc with nested VM. Finally decided on chrome remote desktop for interactione and configured the remote desktop to connect with the already created VM.
  
  * Utkarsh Pant : Worked on Virtual Manager installation and configuration using chrome remote desktop. Created GUI ubuntu VM using chrome remote desktop and developed a program to test the assignment 2 changes on the nested VM and executed the same.
  
2. Steps taken to complete the assignment are as follows:
<ol type="a">
<li>Created a Google Cloud(GC) account using credit vouchers available and configured VM instance with nested virtualization</li>
<li>Cloned the github repo of Assignment 1 on the VM</li>
<li>Installed necessary tools such as gcc, make,flex,bison,libssl-dev and libelf-dev. Install Linux header using sudo apt-get install linux-headers-$(uname -r)</li>
<li>Check if nested virtualization functionalities is there on the VM using cat /proc/cpuinfo. Screenshot present in the screenshot folder</li>
<li>Download and build the Linux kernel source code by going to https://github.com/torvalds/linux, fork the repo to your account, and clone it on the VM</li>
<li>Find the corresponding configuration file for the linux kernel to build it</li>
<li>Install build-essential,kernel-package,ccache.Build the linux kernel using the .config file using command make oldconfig</li>
<li>Prepare the linux kernel. make prepare command. Build all the modules into the linux kernel and then the kernel itself using make command.</li>
<li>After the build, package the modules and kernel into a format suitable for booting inside the VM. using INSTALL_MOD_STRIP=1 modules_install command</li>
<li>Install built Linux kernel on VM. Reboot and check the kernel loaded.</li>
<li>Make appropriate changes as per the requirement in the kvm hypervisor files: cpuid.c(~/linux/arch/x86/kvm/cpuid.c) and vmx.c(~/linux/arch/x86/kvm/vmx/vmx.c) </li>
<li>Build  and install modules and kernel again as done earlier. run sudo apt-get install cpu-checker, sudo apt-get install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils and reboot</li>
<li>Authorize a VM user for the inner VM and check the status using sudo systemctl status libvirtd. It should return an active status.</li>
<li>Install  GUI functionalities on our VM for inner-vm interaction.</li>
<li>Connect using chrome remote to the VM . Create a nested VM by installing Ubuntu. Create the test.c file . make and run it to test the nested functionality</li>
</ol>




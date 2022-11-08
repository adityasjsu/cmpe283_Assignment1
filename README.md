# cmpe283_Assignment1
In this assignment we will discover VMX features present in the processor by writing a Linux kernel module that queries these features.

# Functionality to Implement
* Read the VMX configuration MSRs to ascertain support capabilities
* For each group of controls interpret and output the values read from the MSR.

Answer to Questions mentioned in the Assignment:
1. I did this assignment alone.
2. Steps taken to complete the assignment are as follows:
a> Created a Google Cloud(GC) account using credit vouchers available.
b> Created a new project in GC with the billing account.
c> Enabled Compute engine api.
d> Created new vm insatnce in the project created in step b and enabled nested virtualization using command line.
e> Connected to the vm instance using SSH connect.
f> Cloned the github repo created for the assignment which contains the make and C file with initial code.
g> Installed gcc , make in the vm instance.
h> Ran sudo apt-get linux-header-(version of kernel) in the vm instance.
i> Compiled and ran the initial code using make and insmode. Checked the output using dmesg.
j> Referred Intel® 64 and IA-32 Architectures Software Developer Manuals to find the capabilities with Bit Position(s) of the remaining MSRs.
k> Made code changes to the initial C file to read the configurations of the remaining MSRs and to print the output of the values read.
l> Compiled and ran the modified C file and validated the output. Used make, insmod, rmmod, dmesg to do this step.

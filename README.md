# CMPE283_Assignment1
In this assignment we will discover VMX features present in the processor by writing a Linux kernel module that queries these features.

## Functionality to Implement
* Read the VMX configuration MSRs to ascertain support capabilities
* For each group of controls interpret and output the values read from the MSR.

Answer to Questions mentioned in the Assignment:
1. I did this assignment alone.
2. Steps taken to complete the assignment are as follows:
<ol type="a">
<li>Created a Google Cloud(GC) account using credit vouchers available.</li>
<li>Created a new project in GC with the billing account.</li>
<li>Enabled Compute engine api.</li>
<li>Created new vm insatnce in the project created in step b and enabled nested virtualization using command line.</li>
<li>Connected to the vm instance using SSH connect.</li>
<li>Cloned the github repo created for the assignment which contains the make and C file with initial code.</li>
<li>Installed gcc , make in the vm instance.</li>
<li>Ran sudo apt-get linux-header-(version of kernel) in the vm instance.</li>
<li>Compiled and ran the initial code using make and insmode. Checked the output using dmesg.</li>
<li>Referred Intel® 64 and IA-32 Architectures Software Developer Manuals to find the capabilities with Bit Position(s) of the remaining MSRs.</li>
<li>Made code changes to the initial C file to read the configurations of the remaining MSRs and to print the output of the values read.</li>
<li>Compiled and ran the modified C file and validated the output. Used make, insmod, rmmod, dmesg to do this step.</li>
</ol>

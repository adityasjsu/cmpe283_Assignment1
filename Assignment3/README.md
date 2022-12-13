# CMPE283_Assignment3: Instrumentation via hypercall (cont’d)

In this assignments we will modify processor instruction behavior inside the KVM hypervisor. 

## Functionality to Implement
* To modify the CPUID emulation code in KVM to report back additional information 
when special CPUID leaf nodes are requested.

1.For CPUID leaf node %eax=0x4FFFFFFE:

*Return the number of exits for the exit number provided (on input) in %ecx. This value should be returned in %eax

2.For CPUID leaf node %eax=0x4FFFFFFF:

*Return the time spent processing the exit number provided (on input) in %ecx

*Return the high 32 bits of the total time spent for that exit in %ebx

*Return the low 32 bits of the total time spent for that exit in %ecx

For leaf nodes 0x4FFFFFFE and 0x4FFFFFFF, if %ecx (on input) contains a value not defined by the 
SDM, return 0 in all %eax, %ebx, %ecx registers and return 0xFFFFFFFF in %edx. For exit types not 
enabled in KVM, return 0s in all four registers.


## Team of 2
## Aditya Kumar(016009968)
## Utkarsh Pant(015999321)

### Answer to Questions mentioned in the Assignment:
Ans 1. Parts of the Assignment performed by each member is as follows :
  * Aditya Kumar : Started with re-using the environment created for Assignmetn 2 on GCP VM, researched in Intel SDM and torvalds/linux for VMX exit reasons being defined and enabled or not. Modified the kernel code as per the assignment 3 functionality. Analyzed the result of testing with teammate to answer questions asked for Assignment 3.
  
  * Utkarsh Pant : Used GUI ubuntu VM created for Assignment 2 using chrome remote desktop and developed a program to test the assignment 3 changes on the nested VM and executed the same. Analyzed the result of testing with teammate to answer the Assignment 3 questions
  
Ans 2. Steps taken to complete the assignment are as follows:
<ol type="a">
<li>Start by re-using the environment created for Assignment 3</li>
<li>Check the Intel SDM and files in torvalds/linux(github used last time for kernel) for the VMX exit reasons and whether they are defined and enabled or not</li>
<li>Make appropriate changes as per the requirement in the kvm hypervisor files: cpuid.c(~/linux/arch/x86/kvm/cpuid.c), vmx.c(~/linux/arch/x86/kvm/vmx/vmx.c) and ~/linux/arch/x86/kvm/cpuid.h </li>
<li>Build  and install modules and kernel again as done earlier. Execute the following commands to eventually reboot the VM : 
        sudo lsmod | grep kvm
        sudo rmmod kvm_intel
        sudo rmmod kvm
        sudo modprobe kvm
        sudo modprobe kvm_intel
        sudo lsmod | grep kvm
        sudo kvm-ok
        sudo reboot</li>
<li>Connect using chrome remote to the VM as done earlier in the Assignment 2 steps . Create the test.c file in the nested VM to test the changes . Make and run it to test the nested functionality. Record the result and wait for a while and run the test again and record the result again. Compare the two results to answer the questions.</li>
</ol>

Q3. Comment on the frequency of exits – does the number of exits increase at a stable rate? Or are there 
more exits performed during certain VM operations? Approximately how many exits does a full VM 
boot entail?

Ans - Number of exits doesn't increase at a stable rate. For some the number of exits remain same and for some it increases(e.g. EXIT_REASON_CPUID(10),  EXIT_REASON_MSR_READ(31),EXIT_REASON_IO_INSTRUCTION(30), EXIT_REASON_VMCALL (18) and EXIT_REASON_EPT_VIOLATION(48) in increasing order of there number of increase) but rate of increase is not same.

Approximately,full VM boot had total 879724 number of exits  with total 9929774372 cpu cycle times.

Q4. Of the exit types defined in the SDM, which are the most frequent? Least?

Ans- EXIT_REASON_EPT_VIOLATION(48) was the most frequent, EXIT_REASON_DR_ACCESS(29) was the least frequent. Also EXIT_REASON_MSR_READ(31) had the highest number of exit increment over time, EXIT_REASON_EPT_VIOLATION(48) had the lowest number of exit increment over time.


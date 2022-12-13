#include <stdio.h>
#include <sys/types.h>

unsigned int type_no_of_exits[75];
unsigned long long type_exit_cpu_cycle_time[75];

static inline void
__cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx,
unsigned int *edx)
{
    asm volatile("cpuid"
    : "=a" (*eax),"=b" (*ebx),"=c" (*ecx),"=d" (*edx)
    : "0" (*eax), "1" (*ebx), "2" (*ecx), "3" (*edx));
}

int
main(int argc, char **argv)
{
    unsigned int eax, ebx, ecx, edx;
    unsigned long long cycle_time;
    unsigned int ecx_2;
    int i;
    
printf("\n--Testing CPUID(0x4FFFFFFC)--\n\n");
        eax = 0x4FFFFFFC;
        __cpuid(&eax, &ebx, &ecx, &edx);
        printf("CPUID(0x4FFFFFFC), (All Type)Total no of exits = %u \n", eax);
        printf("EAX = %u  EBX = %u ECX = %u EDX = %u \n", eax, ebx, ecx, edx);


        printf("\n--Testing CPUID(0x4FFFFFFD)--\n\n");
        eax = 0x4FFFFFFD;
        __cpuid(&eax, &ebx, &ecx, &edx);
        cycle_time = (unsigned long long) ebx << 32 | ecx;
        printf("CPUID(0x4FFFFFFD), (All Type) Total cpu exit cycles = %llu \n", cycle_time);
        printf("EAX = %u  EBX = %u ECX = %u EDX = %u \n", eax, ebx, ecx, edx);


        printf("\n--Testing CPUID(0x4FFFFFFE)--\n\n");
        for(i = 0; i < 75; i++) {
            eax = 0x4FFFFFFE;
            ecx = i;
            ecx_2 = ecx;
            __cpuid(&eax, &ebx, &ecx, &edx);
            printf("CPUID(0x4FFFFFFE), Type %u Total no of exits = %u \n", ecx_2, eax);
            printf("EAX = %u  EBX = %u ECX = %u EDX = %u \n", eax, ebx, ecx, edx);
			type_no_of_exits[i] = eax;
        }

        printf("\n--Test Leaf Node CPUID(0x4FFFFFFF)--\n\n");
        for(i = 0; i < 75; i++) {
            eax = 0x4FFFFFFF;
            ecx = i;
            ecx_2 = ecx;
            __cpuid(&eax, &ebx, &ecx, &edx);
                cycle_time = (unsigned long long) ebx << 32 | ecx;
            printf("CPUID(0x4FFFFFFF), Type %u Total cpu exit cycles = %llu \n", ecx_2, cycle_time);
            printf("EAX = %u  EBX = %u ECX = %u EDX = %u \n", eax, ebx, ecx, edx);
			type_exit_cpu_cycle_time[i] = cycle_time;
        }
		
    printf("\n--Overview For Each Exit--\n\n");
    printf("Exit Type %-3s No Of Exit %-3s No Of Exit CPU Cycles %-5s Cycles/Exit \n", " ", " ", " ");
    for (i = 0; i < 75; i++) {
        printf("%-13d %-16u %-17llu %-17llu \n", i, type_no_of_exits[i], type_exit_cpu_cycle_time[i], type_no_of_exits[i] != 0 ? (type_exit_cpu_cycle_time[i]/type_no_of_exits[i]) : 0);
    }

}
#include "./CONFIG/types.h"
#include <stdio.h>

extern CONFIG config;

int main(void){
    for(int i=0; i<config.process_count; i++){
        PROCESS p = config.processes[i];
        printf("Process ID: %s\n", p.ID);
        printf("  Coming Time: %d\n", p.arrival_time);
        printf("  Execution Time: %d\n", p.execution_time);
        printf("  Priority: %d\n", p.priority);
        printf("  %s has %d IO Operations;\n",p.ID, p.io_count);
        for(int j=0; j<p.io_count; j++){
            IO_OPERATION io = p.io_operations[j];
            printf("    IO Operation %d: Start Time = %d, Duration = %d\n", j+1, io.start_time, io.duration);
        }
    }
    return 0;
}
#ifndef PROCESSUS_H
#define PROCESSUS_H

#define MAX_IO 20
#define MAX_PROC 100

typedef struct {
    int io_start_time;
    int io_duration;
} IO_OPERATION;

typedef struct {
    char ID[4];
    int arrival_time;
    int execution_time;
    int priority;
    IO_OPERATION io_operations[MAX_IO];
    int io_count;
} PROCESS;

extern PROCESS processus[MAX_PROC];
extern int nb_processus;

void lire_processus(const char *nom_fichier);

#endif
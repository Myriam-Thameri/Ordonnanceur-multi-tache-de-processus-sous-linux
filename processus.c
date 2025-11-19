#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processus.h"

PROCESS processus[MAX_PROC];
int nb_processus = 0;

void lire_processus(const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        exit(1);
    }

    char ligne[256];
    PROCESS temp = {0};

    while (fgets(ligne, sizeof(ligne), f)) {
        ligne[strcspn(ligne, "\n")] = 0;
        if (strlen(ligne) == 0) continue;

        if (strncmp(ligne, "IO ", 3) == 0) {
            int start, dur;
            if (sscanf(ligne + 3, "%d %d", &start, &dur) == 2 && temp.io_count < MAX_IO) {
                temp.io_operations[temp.io_count].io_start_time = start;
                temp.io_operations[temp.io_count].io_duration = dur;
                temp.io_count++;
            }
        } else {
            if (sscanf(ligne, "%3s %d %d %d", temp.ID, &temp.arrival_time,
                       &temp.execution_time, &temp.priority) == 4) {
                processus[nb_processus++] = temp;
                temp.io_count = 0;
            }
        }
    }
    fclose(f);
}
/*
MIT License

Copyright (c) 2025 [Ton Nom ou Nom du Groupe]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>

#define MAX 20

typedef struct {
    char name[20];
    int arrival;
    int burst;
    int start_time;
    int finish_time;
    int waiting_time;
    int done;
} Process;

int main() {
    int n;
    Process p[MAX];
    int completed = 0, t = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Process %d name: ", i+1);
        scanf("%s", p[i].name);

        printf("Arrival time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst time: ");
        scanf("%d", &p[i].burst);

        p[i].done = 0;
    }

    printf("\n--- SJF Scheduling (MIT Licensed Code) ---\n");

    while(completed < n){
        int idx = -1;
        int min_burst = 999999;

        // Chercher le processus le plus court arrivé
        for(int i = 0; i < n; i++){
            if(p[i].arrival <= t && p[i].done == 0){
                if(p[i].burst < min_burst){
                    min_burst = p[i].burst;
                    idx = i;
                }
            }
        }

        // Aucun processus disponible → avancer le temps
        if(idx == -1){
            t++;
            continue;
        }

        // Exécution du processus sélectionné
        p[idx].start_time = t;
        p[idx].finish_time = t + p[idx].burst;
        p[idx].waiting_time = p[idx].start_time - p[idx].arrival;

        t += p[idx].burst;
        p[idx].done = 1;
        completed++;

        printf("%s | Start: %d | End: %d | Waiting: %d\n",
            p[idx].name,
            p[idx].start_time,
            p[idx].finish_time,
            p[idx].waiting_time
        );
    }

    return 0;
}

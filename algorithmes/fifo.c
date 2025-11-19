#include <stdio.h>
#include <stdlib.h>
#include "../processus.h"

typedef struct Node {
    PROCESS *p;
    int cpu_used;
    struct Node *next;
} Node;

static Node *ready_queue = NULL;
static Node *io_queue = NULL;
static PROCESS *running = NULL;
static int running_cpu_used = 0;
static int current_time = 0;

static void enqueue(Node **q, PROCESS *p, int used) {
    Node *n = malloc(sizeof(Node));
    n->p = p; n->cpu_used = used; n->next = NULL;
    if (!*q) *q = n;
    else { Node *t = *q; while (t->next) t = t->next; t->next = n; }
}

static Node* dequeue(Node **q) {
    if (!*q) return NULL;
    Node *n = *q; *q = n->next; return n;
}

void simuler_fifo(void) {
    int termine = 0;
    int total_attente = 0, total_sejour = 0;

    printf("Temps | Evenement\n");
    printf("------|----------------------------------------------------\n");

    while (termine < nb_processus) {
        for (int i = 0; i < nb_processus; i++) {
            if (processus[i].arrival_time == current_time) {
                enqueue(&ready_queue, &processus[i], 0);
                printf("%5d | %s arrive -> file prete\n", current_time, processus[i].ID);
            }
        }

        Node *prev = NULL, *cur = io_queue;
        while (cur) {
            cur->p->io_operations[cur->p->io_count - 1].io_duration--;
            if (cur->p->io_operations[cur->p->io_count - 1].io_duration <= 0) {
                printf("%5d | %s termine E/S -> file prete\n", current_time, cur->p->ID);
                enqueue(&ready_queue, cur->p, cur->cpu_used);
                if (!prev) io_queue = cur->next;
                else prev->next = cur->next;
                Node *del = cur; cur = cur->next; free(del);
            } else {
                prev = cur; cur = cur->next;
            }
        }

        if (!running && ready_queue) {
            Node *n = dequeue(&ready_queue);
            running = n->p;
            running_cpu_used = n->cpu_used;
            free(n);
            printf("%5d | %s commence CPU\n", current_time, running->ID);
        }

        if (running) {
            running_cpu_used++;
            running->execution_time--;

            for (int i = 0; i < running->io_count; i++) {
                if (running_cpu_used == running->io_operations[i].io_start_time) {
                    printf("%5d | %s -> E/S (%d ms)\n", current_time, running->ID,
                           running->io_operations[i].io_duration);
                    enqueue(&io_queue, running, running_cpu_used);
                    running = NULL;
                    running_cpu_used = 0;
                    break;
                }
            }

            if (running && running->execution_time == 0) {
                int fin = current_time + 1;
                int sejour = fin - running->arrival_time;
                int attente = sejour - running_cpu_used;
                total_attente += attente;
                total_sejour += sejour;
                printf("%5d | %s TERMINE\n", fin, running->ID);
                running = NULL;
                running_cpu_used = 0;
                termine++;
            }
        }
        current_time++;
    }

    printf("\n=== RESULTATS ===\n");
    printf("Temps total           : %d\n", current_time - 1);
    printf("Attente moyenne       : %.2f\n", (float)total_attente / nb_processus);
    printf("Temps de sejour moyen : %.2f\n", (float)total_sejour / nb_processus);
}
#include <stdio.h>
#include "processus.h"
#include "algorithmes/fifo.h"

int main() {
    lire_processus("config/processus.txt");
    printf("Debut de la simulation FIFO avec operations E/S\n\n");
    simuler_fifo();
    return 0;
}
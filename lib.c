#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

    void teste (int argc, char *argv[]) {
        for (int i = 1; i < argc; i++){
            printf("%s ", argv[i]);
        }
    }

    tConversion *verificacaoBasica (int argc, char *argv[]) {
        tConversion *t = NULL;

        if (argc != 1 && argc >= 4) {
            t = (tConversion*) calloc(1, sizeof(tConversion));
            t->baseAtual = atoi(argv[2]);
            t->baseFutura = atoi(argv[3]);
            t->numero = argv[1];
        }
        return t;
    }

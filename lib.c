#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

#include "lib.h"

    void teste (tConversion *t) {
            printf("%s ", t->numero);
            printf("%d ", t->baseAtual);
            printf("%d ", t->baseFutura);
            printf("%d ", t->lengthNumero);
    }

    tConversion *verificacaoBasica (int argc, char *argv[]) {
        tConversion *t = NULL;

        if (argc != 1 && argc >= 4) {
            t = (tConversion*) calloc(1, sizeof(tConversion));
            t->numero = argv[1];
            t->baseAtual = atoi(argv[2]);
            t->baseFutura = atoi(argv[3]);
            t->lengthNumero = strlen(argv[1]);
        }
        if (t->baseAtual < 2 || t->baseAtual > 36 || t->baseFutura < 2 || t->baseFutura > 36)
            t = NULL;
        return t;
    }

    void removePunctuation (tConversion *t) {
        for (int i = 0; i < t->lengthNumero; i++) {
            if ((t->numero[i] >= 32 && t->numero[i] <= 47) ||
                (t->numero[i] >= 58 && t->numero[i] <= 64) ||
                (t->numero[i] >= 92 && t->numero[i] <= 96) ||
                (t->numero[i] >= 123 && t->numero[i] <= 126)) {
                    for (int j = i; j < t->lengthNumero; j++)
                        t->numero[j] = t->numero[j+1];
                }
        }
    }

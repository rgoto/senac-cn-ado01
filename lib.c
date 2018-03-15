#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
        } if (t->baseAtual < 2 || t->baseFutura < 2 || t->baseAtual > 36 || t->baseFutura > 36) t = NULL;
        return t;
    }

    void isHexa(tConversion *t) {
        if(isxdigit(*t->numero))
            printf("hexadecimal: %s\n", t->numero);
        else
            printf("nao e hexa\n");
    }

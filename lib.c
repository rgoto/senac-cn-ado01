#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "lib.h"

    tConversion *verificacaoBasica (int argc, char *argv[]) {
        tConversion *t = NULL;

        if (argc != 1 && argc >= 4) {
            t = (tConversion*) calloc(1, sizeof(tConversion));
            t->numero = argv[1];
            t->baseAtual = atoi(argv[2]);
            t->baseFutura = atoi(argv[3]);
            t->lengthNumero = strlen(argv[1]);
        }
        if (t->baseAtual < 2 || t->baseAtual > 36 || t->baseFutura < 2 || t->baseFutura > 36 || parametrization(t))
            t = NULL;
        else
            for (int i = 0; i < t->lengthNumero; i++)
                t->numero[i] = toupper(t->numero[i]);

        return t;
    }

    int parametrization (tConversion *t) {
        int x = 0;
        for (int i = 0; i < t->lengthNumero; i++) {
            if ((t->numero[i] >= 32 && t->numero[i] <= 47) || (t->numero[i] >= 58 && t->numero[i] <= 64) ||
                (t->numero[i] >= 91 && t->numero[i] <= 96) || (t->numero[i] >= 123 && t->numero[i] <= 126) ||
                (t->numero[i] >= 127))
                    x = 1;
        }
        return x;
    }

    int verificacaoBase (tConversion *t) {
        int num = 0;

        if (t->baseAtual > 10) {
            t->numBaseRef = A + (t->baseAtual - 11);
                for (int i = 0; i < t->lengthNumero; i++)
                    if ((int)t->numero[i] > t->numBaseRef)
                        num = 1;
        }
        else {
            t->numBaseRef = 58;
            for (int i = 0; i < t->lengthNumero; i++)
                if ((int) t->numero[i] > t->numBaseRef)
                    num = 1;
        }

    return num;
    }

    void convesaoBaseDec (tConversion *t) {
        for (int character = 0; character < t->lengthNumero; character++) {
            int mulp;

            if (isdigit(t->numero[character])){
                mulp = 0;
                for (int numeros = ZERO; numeros <= TEN; numeros++) {
                    if ((int)t->numero[character] == numeros) {
                        t->numDec  += mulp * pow(t->baseAtual,(t->lengthNumero - character - 1));
                        break;
                    }
                    else mulp++;
                }
            } else {
                mulp = 10;
                for (int numeros = A; numeros <= Z; numeros++) {
                    if ((int)t->numero[character] == numeros) {
                        t->numDec += mulp * pow(t->baseAtual,(t->lengthNumero - character - 1));
                        break;
                    }
                    else mulp++;
                }
            }
        }
    }

    void conversionBaseN (tConversion *t) {
        int resto = (t->numDec % t->baseFutura),
            divisor = (t->numDec / t->baseFutura),
            controller = 0;

        char alfa[36];
            for (int i = 0; i < 36; i++) {
               alfa[i] = (char) i < 10 ? i + '0' : (i-10) + 'A';
        }

        while (divisor > t->baseFutura) {
            t->resultConversion[controller++] = alfa[resto];

            resto = divisor % t->baseFutura;
            divisor = divisor / t->baseFutura;
        }

        t->resultConversion[controller++] = alfa[resto];
        t->resultConversion[controller++] = alfa[divisor];
        t->lengthResult = controller;
    }

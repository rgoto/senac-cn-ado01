#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

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

    void parametrization (tConversion *t) {
        for (int i = 0; i < t->lengthNumero; i++) {
            if ((t->numero[i] >= 32 && t->numero[i] <= 47) ||
                (t->numero[i] >= 58 && t->numero[i] <= 64) ||
                (t->numero[i] >= 91 && t->numero[i] <= 96) ||
                (t->numero[i] >= 123 && t->numero[i] <= 126) ||
                (t->numero[i] >= 127)) {
                    for (int j = i; j < t->lengthNumero; j++)
                        t->numero[j] = t->numero[j+1];

                    t->lengthNumero = strlen(t->numero);
                    i = -1;
                }
        }

        for (int i = 0; i < t->lengthNumero; i++)
            t->numero[i] = toupper(t->numero[i]);
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
        int resto = t->numDec % t->baseFutura,
            divisor = t->numDec / t->baseFutura,
            controller = 0;

        while (resto >= 0) {
            if (resto == 0) {
                t->resultConversion[controller] = charIdentify(divisor);
                break;
            }
            else
                t->resultConversion[controller] = charIdentify(resto);

            printf("%s\n", t->numero);

            resto = divisor % t->baseFutura;
            divisor = divisor / t->baseFutura;
            controller++;
        }

        printf("%d  %d  %s\n", resto, divisor, t->numero);
    }

    char charIdentify (int resto) {
        char numbers[36];
        for (int i = 0; i < 36; i++)
            numbers[i] = (char) i < 10 ? i + '0' : (i-10) + 'A';

        return numbers[resto-1];
    }

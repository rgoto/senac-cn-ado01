#ifndef LIB_H
#define LIB_H

typedef struct {
    int baseAtual, baseFutura, lengthNumero, numBaseRef, lengthResult;
    unsigned int numDec;
    char *numero, resultConversion[36];
} tConversion;

enum numeros_alfabeto {
    A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, X, W, Y, Z
} numAlfabeto;

enum numeros {
    ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN
} numeros;

void teste (tConversion *t);
tConversion *verificacaoBasica (int argc, char *argv[]);
int verificacaoBase (tConversion *t);
void convesaoBaseDec (tConversion *t);
void conversionBaseN (tConversion *t);
int parametrization(tConversion *t);

#endif

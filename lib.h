#ifndef LIB_H
#define LIB_H

typedef struct {
    int baseAtual, baseFutura, lengthNumero, numBaseRef;
    char *numero;
} tConversion;

enum numeros_alfabeto {
    A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, X, W, Y, Z
} numAlfabeto;

void teste (tConversion *t);
tConversion *verificacaoBasica (int argc, char *argv[]);
void parametrization (tConversion *t);
int verificacaoBase (tConversion *t);

#endif

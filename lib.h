#ifndef LIB_H
#define LIB_H

typedef struct {
    int baseAtual, baseFutura;
    char *numero;
} tConversion;

void teste (int argc, char *argv[]);
tConversion *verificacaoBasica (int argc, char *argv[]);

#endif

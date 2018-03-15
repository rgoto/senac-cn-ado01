#ifndef LIB_H
#define LIB_H

typedef struct {
    int baseAtual, baseFutura, lengthNumero;
    char *numero;
} tConversion;

void teste (tConversion *t);
tConversion *verificacaoBasica (int argc, char *argv[]);
void removePunctuation (tConversion *t);

#endif

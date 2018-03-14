#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lib.h"

int main (int argc, char* argv[]) {
    tConversion *t = verificacaoBasica(argc, argv);

    printf("%s\n%d\n%d", t->numero, t->baseAtual, t->baseFutura);

}

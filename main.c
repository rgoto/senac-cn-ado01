#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lib.h"

int main (int argc, char* argv[]) {
    tConversion *t = verificacaoBasica(argc, argv);

    if(t == NULL) exit(-1);
    else {
        printf("%s\n%d\n%d\n", t->numero, t->baseAtual, t->baseFutura);
        isHexa(t);
    }
}

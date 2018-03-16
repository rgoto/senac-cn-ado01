#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lib.h"

int main (int argc, char* argv[]) {
    tConversion *t = verificacaoBasica(argc, argv);

    if (t == NULL) exit(1);
    else {
        parametrization(t);

        if (verificacaoBase(t)) exit(1);

        teste(t);
    }
    return 0;
}

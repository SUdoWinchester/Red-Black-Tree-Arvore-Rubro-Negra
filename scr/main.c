#include <stdio.h>
#include <stdlib.h>
#include "Red-Black.h"

int main()
{
    no *T = NULL;
    no *pai = NULL;

    T = insere(&T, 5, pai);
    T = insere(&T, 4, pai);
    T = insere(&T, 6, pai);
    T = insere(&T, 3, pai);
    T = insere(&T, 7, pai);
    T = insere(&T, 2, pai);
    T = insere(&T, 8, pai);
    T = insere(&T, 1, pai);
    T = insere(&T, 9, pai);

    preOrdem(T);
}

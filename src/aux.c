#include "aux.h"

#include <stdio.h>

void limpar_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void limpar_user_input()
{
    printf("\033[A\33[2K\n");
}

void ler_input(char* formato, void* var)
{
    scanf(formato, var);
}

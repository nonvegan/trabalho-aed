#include "aux.h"

#include <stdio.h>
#include <time.h>

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

int ler_input(char* formato, void* var)
{
    return scanf(formato, var);
}

Data data_hoje()
{
    time_t s = time(NULL);
    struct tm* current_time;
    current_time = localtime(&s);
    Data data = {current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday};
    return data;
}

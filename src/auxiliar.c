#include "auxiliar.h"

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

int criar_data(Data* data)
{
    printf("Porfavor insira o dia... ");
    if(!scanf("%d", &data->dia) || data->dia < 1 || data->dia > 31) { /* Erro ao ler */
        limpar_stdin();
        printf("\nErro de leitura, porfavor insira um dia válido...\n");
        return 1;
    }
    putchar('\n');

    printf("Porfavor insira o mês... ");
    if(!scanf("%d", &data->mes) || data->mes < 1 || data->mes > 12) { /* Erro ao ler */
        limpar_stdin();
        printf("\nErro de leitura, porfavor insira uma mês válido...\n");
        return 1;
    }
    putchar('\n');

    printf("Porfavor insira o ano... ");
    if(!scanf("%d", &data->ano ) || data->ano < 1970) { /* Erro ao ler */
        limpar_stdin();
        printf("\nErro de leitura, porfavor insira um ano válido...\n");
        return 1;
    }
    putchar('\n');

    return 0;
}

time_t data_epoch_segs(Data data) /* https://stackoverflow.com/a/9542298 */
{
    struct tm ti={0};
    ti.tm_year = data.ano;
    ti.tm_mon = data.mes;
    ti.tm_mday = data.dia;

    ti.tm_year-=1900;
    ti.tm_mon-=1;
    return mktime(&ti);
}

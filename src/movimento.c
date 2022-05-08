#include "movimento.h"

#include <stdio.h>

void print_movimento(Movimento* mov)
{
    Data data = mov->data;
    printf("id -> %u,  %u-%u-%u: id_produto -> %u, %s de %u produtos\n", mov->id, data.ano,
        data.mes, data.dia, mov->id_produto, mov->tipo ? "Saída" : "Entrada", mov->quantidade);
}


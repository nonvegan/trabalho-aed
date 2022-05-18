#include "movimento.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aux.h"

void print_movimento(Movimento* mov)
{
    Data data = mov->data;
    printf("id -> %u,  %u-%u-%u: id_produto -> %u, %s de %u produtos\n", mov->id, data.ano,
            data.mes, data.dia, mov->id_produto, mov->tipo ? "Saída" : "Entrada", mov->quantidade);
}

int criar_novo_movimento(Movimento *novo_mov)
{
    static int x = 0;
    novo_mov->id=x++;
    novo_mov->data=data_hoje();
    return 0;
}

node_t* criar_elemento(Movimento mov)
{
    node_t* node = malloc(sizeof(node_t));
    node->mov=mov;
    node->next = NULL;
    return node;
}

void inserir_node_fim(node_t **lista, node_t *elemento)
{
    node_t *aux = *lista;
    if(*lista == NULL)
        *lista = elemento;
    else {
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = elemento;
    }
}

void print_lista_movs(node_t *lista_movs)
{
    node_t* aux=lista_movs;
    while(aux != NULL) {
        print_movimento(&aux->mov);
        aux = aux->next;
    }
}

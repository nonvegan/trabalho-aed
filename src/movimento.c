#include "movimento.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aux.h"
#include "produto.h"

int criar_novo_movimento(Movimento *novo_mov)
{
    int tipo_mov;
    novo_mov->data=data_hoje();

    printf("Porfavor insira o tipo de movimento:\n");
    printf("1 - Entrada\n");
    printf("2 - Saída\n");

    if(!scanf("%d", &tipo_mov)) { /* Erro ao ler */
        limpar_user_input();
        limpar_stdin();
        printf("Erro de leitura, porfavor insira uma das opções disponíveis...\n\n");
        return 1;
    }
    limpar_user_input();

    switch(tipo_mov) {
        case 1:
            novo_mov->tipo=ENTRADA_PRODUTO;
            break;
        case 2:
            novo_mov->tipo=SAIDA_PRODUTO;
            break;
        default:
            printf("Esta opção não existe -> %d\n", tipo_mov);
            return 1;
    }


    printf("\nPorfavor insira a quantidade movimenta... ");
    ler_input("%d", &novo_mov->quantidade);
    limpar_stdin();

    putchar('\n');
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

void print_lista_movs(node_t *lista_movs, Produto* lista_produtos)
{
    int x = 91;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s | %*s | %*s #\n",
            -10, "Data",
            -50, "Produto",
            -8, "Tipo",
            -10, "Quantidade");

    node_t* aux=lista_movs;
    while(aux != NULL) {
        printf("# %d-%d-%d%*s | %*s | %*s | %*d #\n",
                aux->mov.data.ano, aux->mov.data.mes, aux->mov.data.dia, 1, "",
                -50, lista_produtos[aux->mov.id_produto].nome,
                -8, (aux->mov.tipo == ENTRADA_PRODUTO ? "Entrada" : "Saída   "),
                -10, aux->mov.quantidade);
        aux = aux->next;
    }

    x = 91;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}

void print_lista_movs_intervalo(node_t *lista_movs, Produto* lista_produtos, Data d1, Data d2)
{
    int x = 91;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s | %*s | %*s #\n",
            -10, "Data",
            -50, "Produto",
            -8, "Tipo",
            -10, "Quantidade");

    node_t* aux=lista_movs;
    while(aux != NULL) {
        if(data_epoch_segs(d1) <= data_epoch_segs(aux->mov.data) && data_epoch_segs(aux->mov.data) <= data_epoch_segs(d2))
            printf("# %d-%d-%d%*s | %*s | %*s | %*d #\n",
                    aux->mov.data.ano, aux->mov.data.mes, aux->mov.data.dia, 1, "",
                    -50, lista_produtos[aux->mov.id_produto].nome,
                    -8, (aux->mov.tipo == ENTRADA_PRODUTO ? "Entrada" : "Saída   "),
                    -10, aux->mov.quantidade);
        aux = aux->next;
    }

    x = 91;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}

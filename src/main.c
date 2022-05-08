#include <stdio.h>
#include <string.h>

#include "aux.h"
#include "fornecedor.h"
#include "movimento.h"
#include "produto.h"

int main()
{
    /* Data data = {2022, 3, 28}; */
    /* Movimento mov = {1, 5, ENTRADA_PRODUTO, 6, data}; */

    Produto lista_produtos[100] = { 0 };
    int contador_produtos = 0;

    int quit = 0;
    while (!quit) {

        printf("Selecione a operação que pretende executar\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Editar produto\n");
        printf("3 - Consultar produto\n");
        printf("4 - Remover produto\n");
        printf("5 - Adicionar produto\n");
        printf("6 - Listar produtos\n");
        printf("0 - Sair\n");

        int input_menu;
        ler_input("%d", &input_menu);
        limpar_user_input();

        switch (input_menu) {
        case 0:
            quit = 1;
            break;
        case 1:
            Produto novo_produto = { 0 };

            if (criar_novo_produto(&novo_produto))
                printf("Ocorreu um erro ao adicionar o produto, porfavor tente novamente\n\n");
            else {
                unsigned int id = contador_produtos++;
                novo_produto.id = id;
                lista_produtos[id] = novo_produto;
                printf("Novo produto adicionado com sucesso:\n");
            }
            print_lista_produtos(lista_produtos, contador_produtos);
            break;
        case 4:
            printf("Porfavor insira o código do produto que pretende remover...");

            int input_codigo;
            ler_input("%d", &input_codigo);
            limpar_user_input();

            if(input_codigo < 0 || input_codigo >= contador_produtos) {
                printf("Erro: Este produto não existe\n\n");
            } else {
                lista_produtos[input_codigo].ativo = 0;
                printf("Produto removido com sucesso!\n\n");
            }
            break;

        case 6:
            if (contador_produtos == 0) {
                printf("Não existem produtos\n");
                break;
            }
            print_lista_produtos(lista_produtos, contador_produtos);
            break;
        default:
            printf("Não implementado\n");
        }
    }

    printf("Até sempre!\n");
    return 0;
}

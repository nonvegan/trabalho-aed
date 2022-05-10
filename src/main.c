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
        printf("3 - Remover produto\n");
        printf("4 - Listar produtos\n");
        printf("5 - Consultar produto\n");
        printf("6 - Adicionar Fornecedor\n");
        printf("7 - Adicionar Movimento\n");
        printf("8 - Consultar Movimentos\n");
        printf("0 - Sair\n");

        int input_menu;
        ler_input("%d", &input_menu);
        limpar_user_input();

        switch (input_menu) {
            case 0:
                quit = 1;
                break;

            case 1:
                {
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
                }
                break;

            case 2:
                if (contador_produtos == 0) {
                    printf("Não existem produtos\n\n");
                    break;
                }

                printf("Porfavor insira o código do produto que editar... ");

                int input_codigo_editar;
                ler_input("%d", &input_codigo_editar);
                putchar('\n');

                if(input_codigo_editar < 0 || input_codigo_editar >= contador_produtos) {
                    printf("Erro: Este produto não existe\n\n");
                } else if(lista_produtos[input_codigo_editar].removido) {
                    printf("Erro: Este produto já se encontra removido\n\n");
                } else if(!editar_produto(lista_produtos + input_codigo_editar))
                    printf("Produto editado com sucesso!\n\n");
                break;

            case 3:
                if (contador_produtos == 0) {
                    printf("Não existem produtos\n\n");
                    break;
                }
                printf("Porfavor insira o código do produto que pretende remover... ");

                int input_codigo_remover;
                ler_input("%d", &input_codigo_remover);

                if(input_codigo_remover < 0 || input_codigo_remover >= contador_produtos) {
                    printf("Erro: Este produto não existe\n\n");
                } else if(lista_produtos[input_codigo_remover].removido) {
                    printf("Erro: Este produto já se encontra removido\n\n");
                } else {
                    lista_produtos[input_codigo_remover].removido = 1;
                    printf("Produto removido com sucesso!\n\n");
                }
                break;

            case 4:
                if (contador_produtos == 0) {
                    printf("Não existem produtos\n\n");
                    break;
                }
                print_lista_produtos(lista_produtos, contador_produtos);
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                printf("Esta função ainda não está implementada --> %d\n\n", input_menu);
                break;

            default:
                printf("Esta opção náo é válida --> %d\n\n", input_menu);
        }
    }

    printf("Até sempre!\n");
    return 0;
}

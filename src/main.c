#include <stdio.h>
#include <string.h>

#include "aux.h"
#include "fornecedor.h"
#include "movimento.h"
#include "produto.h"

int main()
{
    Produto lista_produtos[100] = { 0 };
    int contador_produtos = 0;

    Fornecedor lista_fornecedores[100] = { 0 };
    int contador_fornecedores = 0;

    node_t* lista_movs = NULL;

    int quit = 0;
    while (!quit) {
        int input_menu;

        printf("Selecione a operação que pretende executar:\n");
        printf(" 0 - Sair\n");
        printf(" 1 - Adicionar produto\n");
        printf(" 2 - Editar produto\n");
        printf(" 3 - Remover produto\n");
        printf(" 4 - Listar produtos\n");
        printf(" 5 - Listar Produtos por fornecedor\n");
        printf(" 6 - Listar Produtos com falta de stock\n");
        printf(" 7 - Adicionar Fornecedor\n");
        printf(" 8 - Listar Fornecedores\n");
        printf(" 9 - Adicionar Movimento\n");
        printf("10 - Listar Movimentos\n");
        printf("11 - Listar Movimentos por intervalo de tempo\n");

        if(!scanf("%d", &input_menu)) { /* Erro ao ler */
            limpar_user_input();
            limpar_stdin();
            printf("Erro de leitura, porfavor insira uma das opções disponíveis...\n\n");
            continue;
        }
        limpar_user_input();

        switch (input_menu) {
            case 0:
                quit = 1;
                break;

            case 1: /* Adicionar produto */
                {
                    Produto novo_produto = {0};
                    if (contador_fornecedores == 0) {
                        printf("Ainda não existem fornecedores registados, porfavor adicione um antes de adicionar um produto.\n\n");
                        break;
                    }

                    if (criar_novo_produto(&novo_produto, contador_fornecedores))
                        printf("Ocorreu um erro ao adicionar o produto, porfavor tente novamente.\n\n");
                    else {
                        int id = contador_produtos++;
                        novo_produto.id = id;
                        lista_produtos[id] = novo_produto;
                        printf("Novo produto adicionado com sucesso:\n");
                        print_lista_produtos(lista_produtos, contador_produtos, lista_fornecedores);
                    }
                }
                break;

            case 2: /* Editar produto */
                {
                    int input_codigo_editar;

                    if (contador_produtos == 0) {
                        printf("Não existem produtos, porfavor adicione um primeiro.\n\n");
                        break;
                    }

                    printf("Porfavor insira o código do produto que pretende editar... ");
                    ler_input("%d", &input_codigo_editar);
                    putchar('\n');

                    if(input_codigo_editar < 0 || input_codigo_editar >= contador_produtos) {
                        printf("Erro: Este produto não existe --> %d \n\n", input_codigo_editar);
                    } else if(lista_produtos[input_codigo_editar].removido) {
                        printf("Erro: Este produto já se encontra removido\n\n");
                    } else if(!editar_produto(lista_produtos + input_codigo_editar, contador_fornecedores))
                        printf("Produto editado com sucesso!\n\n");
                }
                break;

            case 3: /* Remover produto */
                {
                    int input_codigo_remover;

                    if (contador_produtos == 0) {
                        printf("Não existem produtos, porfavor adicione um primeiro.\n\n");
                        break;
                    }

                    printf("Porfavor insira o código do produto que pretende remover... ");
                    ler_input("%d", &input_codigo_remover);
                    putchar('\n');

                    if(input_codigo_remover < 0 || input_codigo_remover >= contador_produtos) {
                        printf("Erro: Este produto não existe --> %d\n\n", input_codigo_remover);
                    } else if(lista_produtos[input_codigo_remover].removido) {
                        printf("Erro: Este produto já se encontra removido\n\n");
                    } else {
                        lista_produtos[input_codigo_remover].removido = 1;
                        printf("Produto removido com sucesso!\n\n");
                    }
                }
                break;

            case 4: /* Listar produtos */
                if (contador_produtos == 0) {
                    printf("Não existem produtos, porfavor adicione um primeiro.\n\n");
                    break;
                }
                printf("Lista de produtos:\n");
                print_lista_produtos(lista_produtos, contador_produtos, lista_fornecedores);
                break;

            case 5: /* Listar Produtos por fornecedor */
                {
                    int id_fornecedor;

                    if (contador_produtos == 0) {
                        printf("Ainda não existem produtos registados, porfavor adicione um.\n\n");
                        break;
                    }

                    printf("Porfavor insira o codigo do fornecedor... ");
                    if(!ler_input("%u", &id_fornecedor)) {
                        printf("\nErro na leitura de dados, porfavor insira uma das opções disponíveis\n");
                        limpar_stdin();
                        break;
                    }
                    limpar_stdin();

                    if(id_fornecedor < 0 || id_fornecedor >= contador_fornecedores) {
                        printf("\n\nEste fornecedor não existe --> %d\n", id_fornecedor);
                        break;
                    }

                    printf("\nLista de produtos do fornecedor %s:\n", lista_fornecedores[id_fornecedor].nome);
                    print_lista_produtos_fornecedor(lista_produtos, contador_produtos, lista_fornecedores, id_fornecedor);
                }
                break;

            case 6: /* Listar produtos com falta de stock*/
                if (contador_produtos == 0) {
                    printf("Não existem produtos, porfavor adicione um primeiro.\n\n");
                    break;
                }

                printf("Lista de produtos com falta de stock:\n");
                print_lista_produtos_falta_stock(lista_produtos, contador_produtos, lista_fornecedores);
                break;

            case 7: /* Adicionar fornecedor */
                {
                    Fornecedor novo_fornecedor = {0};
                    if (criar_novo_fornecedor(&novo_fornecedor))
                        printf("Ocorreu um erro ao adicionar o fornecedor, porfavor tente novamente.\n\n");
                    else {
                        int id = contador_fornecedores++;
                        novo_fornecedor.id = id;
                        lista_fornecedores[id] = novo_fornecedor;
                        printf("\nNovo fornecedor adicionado com sucesso:\n");
                    }
                    print_lista_fornecedores(lista_fornecedores, contador_fornecedores);
                    putchar('\n');
                }
                break;
            case 8: /* Listar fornecedores */
                if (contador_fornecedores == 0) {
                    printf("Não existem fornecedores, porfavor adicione um primeiro.\n\n");
                    break;
                }

                puts("Lista de Fornecedores:");
                print_lista_fornecedores(lista_fornecedores, contador_fornecedores);
                putchar('\n');
                break;
            case 9: /* Adicionar movimento */
                {
                    Movimento novo_movimento = {0};
                    int input_codigo_produto;

                    if (contador_produtos == 0) {
                        printf("Não existem produtos, porfavor adicione um primeiro antes de adicionar um movimento.\n\n");
                        break;
                    }

                    printf("Porfavor insira o código do produto que pretende registar um movimento... ");
                    ler_input("%d", &input_codigo_produto);
                    putchar('\n');

                    if(input_codigo_produto < 0 || input_codigo_produto >= contador_produtos) {
                        printf("Erro: Este produto não existe --> %d \n\n", input_codigo_produto);
                    } else if(lista_produtos[input_codigo_produto].removido) {
                        printf("Erro: Este produto já se encontra removido\n\n");
                    } else {
                        novo_movimento.id_produto = input_codigo_produto;
                        if (criar_novo_movimento(&novo_movimento))
                            printf("Ocorreu um erro ao adicionar o movimento, porfavor tente novamente.\n\n");
                        else {
                            if(novo_movimento.tipo == ENTRADA_PRODUTO) {
                                lista_produtos[input_codigo_produto].quantidade_stock += novo_movimento.quantidade;
                            } else if (novo_movimento.tipo == SAIDA_PRODUTO) {
                                lista_produtos[input_codigo_produto].quantidade_stock -= novo_movimento.quantidade;
                            }

                            node_t * novo_node = criar_elemento(novo_movimento);
                            inserir_node_fim(&lista_movs, novo_node);
                        }
                    }
                }
                break;

            case 10: /* Listar movimentos */
                if (lista_movs == NULL) {
                    printf("Não existem movimentos, porfavor adicione um primeiro.\n\n");
                    break;
                }

                puts("Lista de Movimentos:");
                print_lista_movs(lista_movs, lista_produtos);
                break;
            case 11: /* Listar movimentos por intervalo de tempo*/
                {
                    Data d1, d2;
                    if (lista_movs == NULL) {
                        printf("Não existem movimentos, porfavor adicione um primeiro.\n\n");
                        break;
                    }

                    printf("Porfavor insira a data de início:\n");
                    if(criar_data(&d1))
                        break;

                    printf("Porfavor insira a data de fim:\n");
                    if(criar_data(&d2))
                        break;

                    printf("Lista de Movimentos desde %d-%d-%d até %d-%d-%d:\n",d1.dia, d1.mes, d1.ano, d2.dia, d2.mes, d2.ano);
                    print_lista_movs_intervalo(lista_movs, lista_produtos, d1, d2);
                }
                break;

            default:
                printf("Esta opção náo é válida. --> %d\n\n", input_menu);
        }
    }

    printf("Até sempre!\n");
    return 0;
}

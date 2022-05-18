#include "produto.h"

#include "aux.h"
#include <stdio.h>
#include <string.h>

int criar_novo_produto(Produto* produto, const int contador_fornecedores)
{
    printf("Porfavor insira o nome do produto... ");
    limpar_stdin();
    fgets(produto->nome, 50, stdin);
    produto->nome[strcspn(produto->nome, "\n")] = 0; /* Remover newline */

    printf("\nPorfavor insira o preço do produto... ");
    ler_input("%f", &produto->preco_unitario);
    limpar_stdin();

    printf("\nPorfavor insira o codigo do fornecedor... ");
    ler_input("%u", &produto->id_fornecedor);
    limpar_stdin();

    if(produto->id_fornecedor < 0 || produto->id_fornecedor >= contador_fornecedores) {
        printf("\nEste fornecedor não existe --> %d \n", produto->id_fornecedor);
        return -1;
    }

    printf("\nPorfavor insira a quantidade de stock minimo... ");
    ler_input("%d", &produto->quantidade_minima_stock);
    limpar_stdin();
    putchar('\n');

    produto->removido = 0;

    return 0;
}

int editar_produto(Produto *produto, const int contador_fornecedores)
{
    int input_menu;

    printf("Porfavor insira o campo que pretende editar\n");
    printf("1 - Nome\n");
    printf("2 - Preço Unitário\n");
    printf("3 - Fornecedor\n");
    printf("4 - Stock minímo\n");
    printf("0 - Cancelar\n");

    if(!scanf("%d", &input_menu)) { /* Erro ao ler */
        limpar_user_input();
        limpar_stdin();
        printf("Erro de leitura, porfavor insira uma das opções disponíveis...\n\n");
        return 1;
    }
    limpar_user_input();

    switch(input_menu) {
        case 0:
            printf("Edição cancelada\n\n");
            return 1;
        case 1:
            printf("Porfavor insira o nome do produto... ");
            limpar_stdin();
            fgets(produto->nome, 50, stdin);
            produto->nome[strcspn(produto->nome, "\n")] = 0; /* Remover newline */
            break;
        case 2:
            printf("Porfavor insira o preço do produto... ");
            ler_input("%f", &produto->preco_unitario);
            limpar_stdin();
            break;
        case 3:
            {
                int id_fornecedor_temp;

                printf("Porfavor insira o codigo do fornecedor... ");
                if(!ler_input("%u", &id_fornecedor_temp)) {
                    printf("Erro na leitura de dados, porfavor insira uma das opções disponíveis\n");
                    limpar_stdin();
                    return -1;
                }
                limpar_stdin();

                if(id_fornecedor_temp < 0 || id_fornecedor_temp >= contador_fornecedores) {
                    printf("\nEste fornecedor não existe --> %d\n", id_fornecedor_temp);
                    return -1;
                }

                produto->id_fornecedor=id_fornecedor_temp;
            }
            break;
        case 4:
            printf("Porfavor insira a quantidade de stock minimo... ");
            ler_input("%d", &produto->quantidade_minima_stock);
            limpar_stdin();
            break;
        default:
            printf("Esta opção não é válida --> %d\n\n", input_menu);
            return 1;
    }

    putchar('\n');
    return 0;
}

void print_lista_produtos(Produto* lista_produtos, int size, Fornecedor* lista_fornecedores)
{
    int x = 116, i;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s | %*s | %*s | %*s | %*s #\n",
            -6, "Código",
            -50, "Nome",
            -10, "Fornecedor",
            -14, "Preço Unitário",
            -5, "Stock",
            -10, "Stock Minímo");

    for (i = 0; i < size; i++) {
        Produto* produto = lista_produtos + i;
        if (!produto->removido)
            printf("# %*u | %*s | %*s | %*.3f€ | %*d | %*d #\n",
                    -6,  produto->id,
                    -50, produto->nome,
                    -10, lista_fornecedores[produto->id_fornecedor].nome,
                    -13, produto->preco_unitario,
                    -5,  produto->quantidade_stock,
                    -12, produto->quantidade_minima_stock);
    }
    x = 116;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}

void print_lista_produtos_fornecedor(Produto* lista_produtos, int size,
        Fornecedor* lista_fornecedores, int id_fornecedor)
{
    int x = 116, i;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s | %*s | %*s | %*s | %*s #\n",
            -6, "Código",
            -50, "Nome",
            -10, "Fornecedor",
            -14, "Preço Unitário",
            -5, "Stock",
            -10, "Stock Minímo");

    for (i = 0; i < size; i++) {
        Produto* produto = lista_produtos + i;
        if (!produto->removido && produto->id_fornecedor == id_fornecedor)
            printf("# %*u | %*s | %*s | %*.3f€ | %*d | %*d #\n",
                    -6,  produto->id,
                    -50, produto->nome,
                    -10, lista_fornecedores[produto->id_fornecedor].nome,
                    -13, produto->preco_unitario,
                    -5,  produto->quantidade_stock,
                    -12, produto->quantidade_minima_stock);
    }
    x = 116;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}

void print_lista_produtos_falta_stock(Produto* lista_produtos, int size, Fornecedor* lista_fornecedores)
{
    int x = 116, i;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s | %*s | %*s | %*s | %*s #\n",
            -6, "Código",
            -50, "Nome",
            -10, "Fornecedor",
            -14, "Preço Unitário",
            -5, "Stock",
            -10, "Stock Minímo");

    for (i = 0; i < size; i++) {
        Produto* produto = lista_produtos + i;
        if (!produto->removido && produto->quantidade_stock < produto->quantidade_minima_stock)
            printf("# %*u | %*s | %*s | %*.3f€ | %*d | %*d #\n",
                    -6,  produto->id,
                    -50, produto->nome,
                    -10, lista_fornecedores[produto->id_fornecedor].nome,
                    -13, produto->preco_unitario,
                    -5,  produto->quantidade_stock,
                    -12, produto->quantidade_minima_stock);
    }
    x = 116;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}

#include <stdio.h>
#include <string.h>

#define ENTRADA_PRODUTO 0
#define SAIDA_PRODUTO 1

typedef struct {
    unsigned int ano;
    unsigned int mes;
    unsigned int dia;
} Data;

typedef struct {
    unsigned int id;
    char nome[50];
} Fornecedor;

typedef struct {
    unsigned int id;
    unsigned int id_fornecedor;
    char nome[50];
    float preco_unitario;
    int quantidade_stock;
    int quantidade_minima_stock;
} Produto;

typedef struct {
    unsigned int id;
    unsigned int id_produto;
    unsigned int tipo;
    unsigned int quantidade;
    Data data;
} Movimento;

void print_movimento(Movimento* mov)
{
    Data data = mov->data;
    printf("id -> %u,  %u-%u-%u: id_produto -> %u, %s de %u produtos\n", mov->id, data.ano,
        data.mes, data.dia, mov->id_produto, mov->tipo ? "Saída" : "Entrada", mov->quantidade);
}

void print_lista_produtos(Produto* lista_produtos, int n)
{
    int x = 116;
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

    for (int i = 0; i < n; i++)
        printf("# %*u | %*s | %*u | %*.3f€ | %*d | %*d #\n",
            -6, lista_produtos[i].id,
            -50, lista_produtos[i].nome,
            -10, lista_produtos[i].id_fornecedor,
            -13, lista_produtos[i].preco_unitario,
            -5, lista_produtos[i].quantidade_stock,
            -12, lista_produtos[i].quantidade_minima_stock);
    x = 116;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}

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

int criar_novo_produto(Produto* produto, int* numero_total_produtos)
{
    printf("Porfavor insira o nome do produto... ");
    limpar_stdin();
    fgets(produto->nome, 50, stdin);
    produto->nome[strcspn(produto->nome, "\n")] = 0; /* Remover newline */

    printf("\nPorfavor insira o preço do produto... ");
    scanf("%f", &produto->preco_unitario);

    printf("\nPorfavor insira o codigo do fornecedor... ");
    scanf("%u", &produto->id_fornecedor);

    printf("\nPorfavor insira a quantidade de stock minimo... ");
    scanf("%d", &produto->quantidade_minima_stock);

    if (0) { /* Validação de input */
        return -1;
    };
    return 0;
}

int main()
{
    /* Data data = {2022, 3, 28}; */
    /* Movimento mov = {1, 5, ENTRADA_PRODUTO, 6, data}; */

    Produto lista_produtos[100] = {0};
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

        int input;
        scanf("%d", &input);
        limpar_user_input();

        switch (input) {
        case 0:
            quit = 1;
            break;
        case 1:
            Produto novo_produto = { 0 };
            if (criar_novo_produto(&novo_produto, &contador_produtos))
                printf("\nOcorreu um erro ao adicionar o produto, porfavor tente novamente\n\n");
            else {
                unsigned int id = contador_produtos++;
                novo_produto.id = id;
                lista_produtos[id] = novo_produto;
                printf("\nNovo produto adicionado com sucesso\n\n");
            }
            print_lista_produtos(lista_produtos, 1);
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

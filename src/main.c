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
    char* nome;
} Fornecedor;

typedef struct {
    unsigned int id;
    char nome[50];
    float preco_unitario;
    int quantidade_stock;
    int quantidade_minima;
} Produto;

typedef struct {
    unsigned int id;
    unsigned int id_produto;
    unsigned int tipo;
    unsigned int quantidade;
    Data data;
} Movimento;

typedef struct {
    Movimento *movs;
    unsigned tamanho;
    unsigned tamanho_maximo;
} Lista_Movimentos;

void print_movimento(Movimento* mov)
{
    Data data = mov->data;
    printf("id -> %u,  %u-%u-%u: id_produto -> %u, %s de %u produtos\n", mov->id, data.ano, data.mes, data.dia, mov->id_produto, mov->tipo ? "Saída" : "Entrada", mov->quantidade);
}

void print_produto(Produto *prod)
{
    printf("%u | %s | %f | %i | %i\n", prod->id, prod->nome, prod->preco_unitario, prod->quantidade_stock, prod->quantidade_minima);
}

void limpar_stdin(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    /* Lista_Movimentos lista_movs; */
    /* Movimento movs[10]; */
    /* lista_movs.tamanho_maximo = 10; */
    /* lista_movs.tamanho = 0; */

    /* Fornecedor fornecedor = { .nome = "Olá" }; */
    /* fornecedor.id = 2; */

    /* Produto produto = { 5, "Gelado", 1.2, 10, 5 }; */

    /* Data data = {2022, 3, 28}; */
    /* Movimento mov = {1, 5, ENTRADA_PRODUTO, 6, data}; */


    /* lista_movs.movs = movs; */ 
    /* lista_movs.movs[2] = mov; */
    /* lista_movs.tamanho++; */
     
    /* print_movimento(lista_movs.movs +2); */

    Produto lista_produtos[100] = {0};
    int contador_produtos = 0;

    int quit = 0;
    while(!quit) {
        printf("Selecione a operação que pretende executar\n");

        printf("1 - Adicionar produto\n");
        printf("2 - Editar produto\n");
        printf("3 - Consultar produto\n");
        printf("4 - Remover produto\n");
        printf("5 - Adicionar produto\n");
        printf("6 - Listar produtos\n");
        printf("0 - Sair\n");

        char input = '9';
        scanf("%c", &input);
        limpar_stdin();

        switch(input) {
            case '0':
                quit = 1;
                break;
            case '1':
                Produto novo_produto = {contador_produtos++};
                printf("Porfavor insira o nome do produto...\n");
                fgets(novo_produto.nome, 50, stdin);
                novo_produto.nome[strcspn(novo_produto.nome, "\n")] = 0;
                lista_produtos[contador_produtos - 1] = novo_produto;
                printf("Novo produto criado com sucesso\n");
                break;
            case '6':
                if(contador_produtos == 0) {
                    printf("Não existem produtos\n");
                    break;
                }
                printf("Codigo\tNome\tPreço\tStock\tStock minímo\n");
                printf("contador-> %i\n", contador_produtos);

                for(int i = 0; i < contador_produtos; i++) {
                    print_produto(&lista_produtos[i]);
                }
                break;
            default :
                printf("Não implementado\n");
                break;
        }
    }

    printf("Até sempre!\n");
    return 0;
}

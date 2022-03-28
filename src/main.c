#include <stdio.h>

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
    char* nome;
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

int main()
{
    printf("Hello world!\n");

    Lista_Movimentos lista_movs;
    Movimento movs[10];
    lista_movs.tamanho_maximo = 10;
    lista_movs.tamanho = 0;

    Fornecedor fornecedor = { .nome = "Olá" };
    fornecedor.id = 2;

    Produto produto = { 5, "Gelado", 1.2, 10, 5 };

    Data data = {2022, 3, 28};
    Movimento mov = {1, 5, ENTRADA_PRODUTO, 6, data};


    lista_movs.movs = movs; 
    lista_movs.movs[2] = mov;
    lista_movs.tamanho++;
     
    print_movimento(lista_movs.movs +2);

    return 0;
}

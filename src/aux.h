#ifndef AUX_H_
#define AUX_H_

#include "aux.h"

typedef struct {
    unsigned int ano;
    unsigned int mes;
    unsigned int dia;
} Data;

void limpar_stdin();

void limpar_user_input();

void ler_input(char* formato, int* var);

#endif /* AUX_H_ */

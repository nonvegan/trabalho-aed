#ifndef AUX_H_
#define AUX_H_

#include "aux.h"

#include <time.h>

typedef struct {
    unsigned int ano;
    unsigned int mes;
    unsigned int dia;
} Data;

void limpar_stdin();

void limpar_user_input();

int ler_input(char* formato, void* var);

Data data_hoje();

int criar_data(Data* data);

time_t data_epoch_segs(Data data);

#endif /* AUX_H_ */

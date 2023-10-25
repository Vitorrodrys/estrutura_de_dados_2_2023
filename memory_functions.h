//
// Created by vitor on 06/10/23.
//

#ifndef UNTITLED68_MEMORY_FUNCTIONS_H
#define UNTITLED68_MEMORY_FUNCTIONS_H
#include <stdlib.h>
#include "string.h"
void free_several_pointers(int qtd, ...);
void free_memory(void **ptr);
void *aloca_memoria(void *ptr, size_t tam);
#endif //UNTITLED68_MEMORY_FUNCTIONS_H

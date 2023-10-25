#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "memory_functions.h"
void *aloca_memoria(void *ptr, size_t tam){

    void *ptr_reall = realloc(ptr, tam);

    if(!ptr_reall && tam){
        fprintf(stderr, "ERRO: cannot alocate memory!");
        exit(1);
    }
    return ptr_reall;
}
void free_memory(void **ptr){
    free(*ptr);
    *ptr = NULL;
}
void free_several_pointers(int qtd, ...){

    va_list p;
    va_start(p, qtd);
    for(int i = 0; i<qtd; i++){
        free_memory(va_arg(p, void *));
    }
    va_end(p);
}

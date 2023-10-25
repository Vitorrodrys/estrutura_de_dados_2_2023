#include <stdarg.h>
#include <stdio.h>
#include "memory_functions.h"

void verificaNumero(char *controle, void *ptr){
    int digCert = 0;
    do {

        digCert = 0;
        scanf(controle, ptr);

        while(fgetc(stdin)!= '\n')
            digCert++;
        if(digCert){
            printf("digite somente numeros!\n");
        }
    }while(digCert);
}
char *digText(FILE *f, char parar){




    int tamanho = 1;
    char *texto = (char *)aloca_memoria(NULL,sizeof(char));
    do{
        texto[tamanho-1] = fgetc(f);
        tamanho++;
        if(texto[tamanho-2] != parar){

            texto = (char *)aloca_memoria(texto, sizeof(char)*tamanho);

        }



    }while(texto[tamanho-2] != parar);
    texto[tamanho-2] = '\0';
    return texto;
}

void menu(int quantidade, char *frase, ...){
    va_list p;
    va_start(p, quantidade);

    char *fraseat;

    printf("\t%s\n", frase);
    for (int i = 0; i<quantidade; i++){
        fraseat = va_arg(p, char *);
        printf("%d-%s\n", i+1, fraseat);

    }
    va_end(p);
}
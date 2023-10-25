//
// Created by vitor on 06/10/23.
//

#include "no_vertex.h"
#include "../memory_functions.h"

no_vertex *create_no_vertex(int number, no_vertex *prox){

    no_vertex *new = aloca_memoria(NULL, sizeof(no_vertex));
    new->number = number;
    new->prox = prox;
    return new;
}
int get_number(no_vertex *self){
    return self->number;
}
void set_number(no_vertex * self, int number){
    self->number = number;
}

no_vertex *get_prox(no_vertex *self){
    return self->prox;
}

no_vertex *add_vertex(no_vertex *self, int number){

    if ( !self ){
        return create_no_vertex(number, NULL);
    }
    if ( self->number > number ){
        return create_no_vertex(number, self);
    }
    no_vertex *aux = self;
    while ( self->prox && self->prox->number < number){
        self = self->prox;
    }
    self->prox = create_no_vertex(number, self->prox);
    return aux;

}
no_vertex* remove_vertex(no_vertex *self, int number){

    if ( self->number == number ){
        no_vertex *aux = self->prox;
        free_memory((void *)&self);
        return aux;
    }
    no_vertex *init = self;
    while ( self->prox && self->prox->number != number ){
        self = self->prox;
    }
    if ( !self->prox ){
        return self;
    }
    no_vertex *aux = self->prox;
    self->prox = self->prox->prox;
    free_memory((void *)&aux);
    return init;
}

no_vertex *destroy_no(no_vertex *self){
    if (self){
        self->prox = destroy_no(self->prox);
        self->number=0;
        free_memory((void *)&self);
        return NULL;
    }
    return NULL;
}
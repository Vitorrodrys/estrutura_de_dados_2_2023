//
// Created by vitor on 25/10/23.
//

#include "queue.h"
#include "../memory_functions.h"
typedef struct queue{

    int *queue;
    int ult;
    int ind;
    int tam;
    int qt_elem;
}queue;

int prox(queue *self, int elem){

    return (elem+1)%self->tam;
}
int is_full(queue *self){
    return prox(self, self->ult) == self->ind;
}
queue *create_queue(int tam){

    queue *new = aloca_memoria(NULL, sizeof (queue));
    new->queue = aloca_memoria(NULL, sizeof (int)*tam);
    new->tam = tam;
    new->ind = 0;
    new->ult = 0;
    new->qt_elem = 0;
    memset(new->queue, 0, sizeof (int)*tam);
    return new;
}

queue *destroy_queue(queue *self){

    free_memory((void *)&self->queue);
    self->tam = 0;
    self->ind = 0;
    free_memory((void *)&self);
    return NULL;
}

int enqueue(queue *self, int elem){

    if (is_full(self) ){
        return 0;
    }
    self->queue[self->ult] = elem;
    self->ult = prox(self, self->ult);
    self->qt_elem++;
    return 1;
}

int dequeue(queue *self){

    if ( self->qt_elem == 0 ){
        return -1;
    }
    int elem = self->queue[self->ind];
    self->ind = prox(self, self->ind);
    self->qt_elem--;
    return elem;

}
int is_void(queue *self){
    return !self->qt_elem;
}

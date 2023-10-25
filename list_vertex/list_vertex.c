//
// Created by vitor on 06/10/23.
//

#include "no_vertex.h"
#include "../memory_functions.h"
typedef struct ListVertex{
    no_vertex *first;
    int quantity;
}ListVertex;
int has_edge_to_vertex(const ListVertex *self, int vertex);
no_vertex *get_first(const ListVertex *self);

ListVertex *create_list_vertex(){

    ListVertex *new = aloca_memoria(NULL, sizeof(ListVertex));
    new->quantity = 0;
    new->first=NULL;
    return new;
}
ListVertex *destroy_list_vertex(ListVertex *self){
    self->first = destroy_no(self->first);
    self->quantity = 0;
    free_memory((void *)&self);
    return NULL;
}

void add_new_edge_vertex(ListVertex *self, int number){
    self->first =  add_vertex(self->first, number);
    self->quantity++;
}
void remove_edge_vertex(ListVertex *self, int remove){
    self->first = remove_vertex(self->first, remove);
    self->quantity--;
}

int have_ties_in_vertex(const ListVertex *self, int number_vertex){
    no_vertex *vertex = get_first(self);

    while (vertex && get_number(vertex) < number_vertex){
        vertex = get_prox(vertex);
    }
    return vertex && get_number(vertex) == number_vertex;
}

int is_complete_vertex(const ListVertex *self, int number_vertex){

    return number_vertex-1 == self->quantity;
}
no_vertex *get_first(const ListVertex *self){
    return self->first;
}
int has_edge_to_vertex(const ListVertex *self, int vertex){
    no_vertex *no = get_first(self);
    while (no){
        if ( no->number == vertex ){
            return 1;
        }
        no = get_prox(no);

    }
    return 0;
}
#include "memory_functions.h"
#include "list_vertex/list_vertex.h"
#include <stdio.h>




typedef struct graph{

    ListVertex **vertex;
    int quantity_vertex;
    int is_targeted;

}graph;


graph *create_graph(int is_targeted){

    graph *new = aloca_memoria(NULL, sizeof(graph));
    new->quantity_vertex=0;
    new->vertex = NULL;
    new->is_targeted = is_targeted;
    return new;
}
graph *destroy_graph_list(graph *self){
    for (int i = 0; i < self->quantity_vertex; ++i) {

        self->vertex[i] = destroy_list_vertex(self->vertex[i]);
    }
    self->quantity_vertex = 0;
    self->is_targeted = 0;
    free_memory((void *)&self);
    return NULL;
}
void add_new_vertex(graph *self){

    self->vertex = aloca_memoria(self->vertex, ++self->quantity_vertex*sizeof (ListVertex*));
    self->vertex[self->quantity_vertex-1] = create_list_vertex();
}
void remove_vertex_graph(graph *self, int index){

    self->vertex[index] = destroy_list_vertex(self->vertex[index]);
    for (index = index+1; index < self->quantity_vertex; ++index) {
        self->vertex[index-1] = self->vertex[index];
    }

}
void add_edge_on_vertex(graph *self, int vertex,int number){
    if ( !self->is_targeted && has_edge_to_vertex(self->vertex[vertex], number) ){
        return;
    }
    add_new_edge_vertex(self->vertex[vertex], number);
    if ( !self->is_targeted ){
        if ( vertex == number ){
            return;
        }
        add_new_edge_vertex(self->vertex[number], vertex);
    }
}
void remove_edge_on_vertex(graph *self, int vertex, int remove){
    remove_edge_vertex(self->vertex[vertex], remove);
    if ( self->is_targeted ){
        remove_edge_vertex(self->vertex[remove], vertex);
    }
}
int graph_have_ties(graph *self){
    for (int i = 0; i < self->quantity_vertex; ++i) {

        if ( have_ties_in_vertex( self->vertex[i], i) ){
            return 1;
        }
    }
    return 0;
}
int is_complete_graph_list_adj(graph *self){

    if ( graph_have_ties(self) ){
        return 0;
    }
    for (int i = 0; i < self->quantity_vertex; ++i) {

        if ( ! is_complete_vertex(self->vertex[i], self->quantity_vertex) ){

            return 0;
        }
    }
    return 1;
}
int vertex_has_cicles(graph *self, int vertex, ListVertex *list_vertex_visited){

    if ( !has_edge_to_vertex(list_vertex_visited, vertex) ){
        add_new_edge_vertex(list_vertex_visited, vertex);
    }else{
        return 1;
    }
    no_vertex *no = get_first(self->vertex[vertex]);

    while (no){
        if ( vertex_has_cicles( self, get_number(no), list_vertex_visited ) ){
            return 1;
        }
        no = get_prox(no);

    }
    remove_edge_vertex(list_vertex_visited, vertex);
    return 0;

}
int has_cicles_list_adj(graph *self){

    ListVertex * list_vertex = create_list_vertex();

    for (int i = 0; i < self->quantity_vertex; ++i) {

        if ( vertex_has_cicles(self, i, list_vertex) ){
            return 1;
        }
    }
    list_vertex = destroy_list_vertex(list_vertex);
    return 0;


}
void show_graph_list(graph *self){

    no_vertex *current_vertex;
    for (int i = 0; i < self->quantity_vertex; ++i) {

        printf("%d: ", i);
        current_vertex = get_first(self->vertex[i]);
        while (current_vertex){
            printf( get_prox(current_vertex)?"%d, ":"%d.", get_number(current_vertex));
            current_vertex = get_prox(current_vertex);
        }
        printf("\n");

    }
}
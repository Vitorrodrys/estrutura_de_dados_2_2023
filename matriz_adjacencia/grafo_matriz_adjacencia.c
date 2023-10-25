#include "grafo_matriz_adjacencia.h"
#include "../memory_functions.h"
#include "../list_vertex/list_vertex.h"
#include <stdio.h>
typedef struct graphAdj{

    int **matriz;
    int quantity_vertex;
    int quantity_arest;
    int _is_direct;
}graphAdj;

graphAdj *create_graph_adj(int quantity_vertex, int is_direct){

    graphAdj *new = aloca_memoria(NULL, sizeof(graphAdj));
    *new = (graphAdj){
        .matriz = aloca_memoria(NULL, sizeof(int*)*quantity_vertex),
        .quantity_arest = 0,
        .quantity_vertex = quantity_vertex,
        ._is_direct = is_direct
    };
    for (int i = 0; i < quantity_vertex; ++i) {
        new->matriz[i] = aloca_memoria(NULL, sizeof (int)*quantity_vertex);
        memset(new->matriz[i], 0, sizeof(int)*quantity_vertex);
    }

    return new;
}

graphAdj  *destroy_graph(graphAdj *self){

    for (int i = 0; i < self->quantity_vertex; ++i) {
        free_memory((void *)(self->matriz+i));
    }
    free_memory((void *)&self->matriz);
    self->_is_direct = 0;
    self->quantity_vertex = 0;
    self->quantity_arest = 0;
    free_memory((void *)&self);
    return NULL;
}
void add_new_edge(graphAdj *self, int from, int to){

    self->matriz[from][to] = self->_is_direct?self->matriz[from][to]+1:1;
    if ( !self->_is_direct ){
        self->matriz[to][from] = 1;
    }
}
void remove_edge_adj(graphAdj *self, int from, int to){

    if ( self->_is_direct ){
        self->matriz[from][to]--;
    }else{
        self->matriz[from][to] = 0;
        self->matriz[to][from] = 0;
    }
}

int __has_multiples_edges_when_is_t(graphAdj *self){
    int sum = 0;
    for (int i = 0; i<self->quantity_vertex; i++){
        for (int j = 0; j < self->quantity_vertex; ++j) {
            if ( self->matriz[i][j] > 1 ){
                return 1;
            }
            sum+=self->matriz[j][i];
            if (sum > 1){
                return 1;
            }

        }
    }
    return 0;
}
int __has_multiples_edges_when_is_nt(graphAdj *self){
    int sum = 0;
    for (int i = 0; i < self->quantity_vertex; ++i) {

        for (int j = 0; j < i+1; ++j) {

            sum+=self->matriz[j][i];
            if ( sum > 1 ){
                return 1;
            }
        }
    }
    return 0;
}

int has_multiples_edges(graphAdj *self){
    return self->_is_direct? __has_multiples_edges_when_is_t(self): __has_multiples_edges_when_is_nt(self);
}

int has_ties(graphAdj *self){

    for (int i = 0; i < self->quantity_vertex; ++i) {

        if( self->matriz[i][i] ){
            return 1;
        }
    }
    return 0;
}
int is_simple_graph(graphAdj *self){
    return !self->_is_direct && !has_multiples_edges(self) && !has_ties(self);
}
int is_multigraph(graphAdj *self){
    return !self->_is_direct && has_multiples_edges(self) && has_ties(self);
}
int is_pseudograph(graphAdj *self){
    return !self->_is_direct && has_multiples_edges(self);
}
int is_graph_targeted(graphAdj *self){
    return self->_is_direct && !has_multiples_edges(self);
}
int is_multigraph_targeted(graphAdj *self){
    return self->_is_direct && has_multiples_edges(self);
}

int is_complete_graph(graphAdj *self){

    if (has_ties(self) ){
        return 0;
    }
    for (int i = 0; i < self->quantity_vertex; ++i) {

        for (int j = 0; j < self->quantity_vertex; ++j) {

            if ( i!=j && !self->matriz[i][j] ){
                return 0;
            }
        }
    }
    return 1;
}
int has_cicles_in_vertex(graphAdj *self, int vertex, ListVertex *list){
    if (has_edge_to_vertex(list, vertex)){
        return 1;
    }
    add_new_edge_vertex(list, vertex);
    for (int i = 0; i < self->quantity_vertex; ++i) {

        if ( self->matriz[vertex][i] ){
            if (has_cicles_in_vertex(self, i, list) ){
                return 1;
            }
        }
    }
    remove_edge_vertex(list, vertex);
    return 0;
}
int has_cicles(graphAdj *self){


    ListVertex *list = create_list_vertex();

    for (int i = 0; i < self->quantity_vertex; ++i) {

        if (has_cicles_in_vertex(self, i, list) ){
            return 1;
        }
    }
    list = destroy_list_vertex(list);
    return 0;
}

void show_graph(graphAdj *self){

    for (int i = 0; i < self->quantity_vertex; ++i) {

        for (int j = 0; j < self->quantity_vertex-1; ++j) {

            printf("%d, ", self->matriz[i][j]);
        }
        printf("%d.\n", self->matriz[i][self->quantity_vertex-1]);
    }
}

respost_search *bfs(graphAdj *self, int what_vertex){
    if ( what_vertex >= self->quantity_vertex ){
        return NULL;
    }

    respost_search *search = create_respost(self->quantity_vertex, what_vertex);
    int elem;
    while ( !queue_is_void(search) ){

        elem = get_next_vertex_queue(search);

        for ( int i = 0; i < self->quantity_vertex ; i++ ) {

            if ( !self->matriz[elem][i] ){
                continue;
            }

            if (elem_still_not_visited(search, i)) {
                to_visite_element(search, elem, i, self->matriz[elem][i]);
            }
        }
    }
    return search;
}

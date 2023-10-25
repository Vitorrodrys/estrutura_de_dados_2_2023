//
// Created by vitor on 25/10/23.
//

#include "RespostSearch.h"
#include "queue.h"
#include "../memory_functions.h"
#include "limits.h"
#include <stdio.h>
typedef enum mark_visiteds{
    already_visited, no_visited, visiting
}mark_visiteds;



typedef struct RespostSearch{
    int tam_graph;
    int which_vertex;
    int *dists;
    int *pass_by;
    mark_visiteds *visitados;
    queue *queue_vertex;
}RespostSearch;

RespostSearch * create_respost(int tam_graph, int which_vertex){

    RespostSearch *new = aloca_memoria(NULL, sizeof(RespostSearch));

    new->tam_graph = tam_graph;
    new->which_vertex = which_vertex;

    //alocated dists, mark all dist for all vertex as infinity, and after mark the dist to it self how 0
    new->dists = aloca_memoria(NULL, sizeof(int)*tam_graph);
    memset(new->dists, 0, sizeof (int)*tam_graph);
    new->dists[which_vertex] = 0;

    new->pass_by = aloca_memoria(NULL, sizeof (int)*tam_graph);
    //define that I didn't go through any
    memset(new->pass_by, -1, sizeof (int)*tam_graph);
    new->pass_by[which_vertex] = which_vertex;


    //set that I don't visited any unless the I self
    new->visitados = aloca_memoria(NULL, sizeof (mark_visiteds)*tam_graph);
    for (int i = 0; i < tam_graph; ++i) {
        new->visitados[i] = no_visited;
    }
    new->visitados[which_vertex] = visiting;

    //create the queue
    new->queue_vertex = create_queue(tam_graph);
    enqueue(new->queue_vertex, which_vertex);

    return new;
}

RespostSearch *destroy_respost(RespostSearch *self){

    free_several_pointers(3, &self->dists, &self->visitados, &self->pass_by);
    self->queue_vertex = destroy_queue(self->queue_vertex);
    self->tam_graph = 0;
    self->which_vertex = 0;
    free_memory((void*)&self);
    return NULL;
}

int to_visite_element(RespostSearch *self, int from, int to, int dist){

    if ( from >= self->tam_graph  || to >= self->tam_graph ){
        return 0;
    }

    self->pass_by[to] = from;
    self->visitados[to] = visiting;
    self->dists[to] = self->dists[from] + dist;
    enqueue(self->queue_vertex, to);
    return 1;
}

int get_next_vertex_queue(RespostSearch *self){

    int elem = dequeue(self->queue_vertex);
    self->visitados[elem] = already_visited;
    return elem;
}

int queue_is_void(RespostSearch *self){
    return is_void(self->queue_vertex);
}
int elem_still_not_visited(RespostSearch *self, int elem){
    return self->visitados[elem] == no_visited;
}
void print_respost(RespostSearch *self){

    printf("by %d vertex: \n", self->which_vertex);
    printf("array of dists:\n\t");
    for (int i = 0; i < self->tam_graph-1; ++i) {
        printf("%d, ", self->dists[i]);
    }
    printf("%d.\npass by:\n\t", self->dists[self->tam_graph-1]);
    for (int i = 0; i < self->tam_graph-1; ++i) {

        printf("%d, ", self->pass_by[i]);
    }
    printf("%d.\n", self->pass_by[self->tam_graph-1]);
}
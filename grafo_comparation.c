
#include "grafo_comparation.h"
#include "graph.h"
#include "matriz_adjacencia/grafo_matriz_adjacencia.h"
#include "memory_functions.h"
#include <stdio.h>

typedef struct GraphComparation{

    graph *list_adj_graph;
    graphAdj *matrix_adj_graph;
    int n_edges;
    int n_vertex;
}GraphComparation;

GraphComparation *create_graph_c(int is_direct, int n_vertices){

    GraphComparation *new = aloca_memoria(NULL, sizeof(GraphComparation));
    *new = (GraphComparation){
        .list_adj_graph = create_graph(is_direct),
        .matrix_adj_graph = create_graph_adj(n_vertices, is_direct),
        .n_edges = 0,
        .n_vertex = n_vertices
    };
    for (int i = 0; i < n_vertices; ++i) {
        add_new_vertex(new->list_adj_graph);
    }
    return new;
}
GraphComparation *destroy_graph_c(GraphComparation *self){

    self->list_adj_graph = destroy_graph_list(self->list_adj_graph);
    self->matrix_adj_graph = destroy_graph(self->matrix_adj_graph);
    self->n_edges = 0;
    self->n_vertex = 0;
    free_memory((void *)&self);
    return NULL;
}

betterGraph what_is_better(GraphComparation *self){
    float n_edges = (float)self->n_edges;
    float n_vertex = (float)self->n_vertex;
    return 2.0*n_edges/(n_vertex*(n_vertex-1))>0.5?graphMtxAdj:graphListAdj;
}
void insert_new_edge(GraphComparation *self, int from, int to){
    add_edge_on_vertex(self->list_adj_graph, from, to);
    add_new_edge(self->matrix_adj_graph, from, to);
    self->n_edges++;

}
void retire_edge(GraphComparation *self, int from, int to){

    remove_edge_adj(self->matrix_adj_graph, from ,to);
    remove_edge_on_vertex(self->list_adj_graph, from, to);
    self->n_edges--;
}

void verify_resposts(int r1, int r2){
    if (r1 != r2){
        fprintf(stderr, "ANSWERS SHOULD BE EQUALITY, HOWEVER, DON'T IS: %d, %d", r1, r2);
        exit(1);
    }
}
int is_complete(GraphComparation *self){
    int graph_list_respost = is_complete_graph_list_adj(self->list_adj_graph);
    int graph_matrix_respost = is_complete_graph(self->matrix_adj_graph);
    verify_resposts(graph_list_respost, graph_matrix_respost);
    return graph_list_respost;
}
int have_cicles_in_graph(GraphComparation *self){

    int r1 = has_cicles_list_adj(self->list_adj_graph);
    int r2 = has_cicles(self->matrix_adj_graph);
    verify_resposts(r1, r2);
    return r1;
}
void show_graphs(GraphComparation *self){
    printf("graph with adjacences list:\n");
    show_graph_list(self->list_adj_graph);
    printf("######################################################################################\n");
    printf("graph with adjacences matrix:\n");
    show_graph(self->matrix_adj_graph);
    printf("#######################################################################################\n");
}

respost_search *bfs_in_graph(GraphComparation *self, int elem){
    return bfs(self->matrix_adj_graph, elem);
}
//
// Created by vitor on 09/10/23.
//

#ifndef UNTITLED68_GRAFO_COMPARATION_H
#define UNTITLED68_GRAFO_COMPARATION_H
#include "respost_search/respost_search.h"
typedef enum betterGraph{
    graphListAdj, graphMtxAdj
}betterGraph;
typedef struct GraphComparation GraphComparation;
GraphComparation *create_graph_c(int is_direct, int n_vertices);
betterGraph what_is_better(GraphComparation *self);
void insert_new_edge(GraphComparation *self, int from, int to);
void retire_edge(GraphComparation *self, int from, int to);
int is_complete(GraphComparation *self);
int have_cicles_in_graph(GraphComparation *self);
void show_graphs(GraphComparation *self);
GraphComparation *destroy_graph_c(GraphComparation *self);
respost_search *bfs_in_graph(GraphComparation *self, int elem);
#endif //UNTITLED68_GRAFO_COMPARATION_H

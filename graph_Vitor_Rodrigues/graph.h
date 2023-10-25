//
// Created by vitor on 06/10/23.
//

#ifndef UNTITLED68_GRAPH_H
#define UNTITLED68_GRAPH_H

#define base_graph_targeted( name, more_fields ) \
typedef struct graph{ \
ListVertex **vertex; \
int quantity_vertex; \
}graph;

typedef struct graph graph;
graph *create_graph(int is_targeted);
void show_graph_list(graph *self);
void add_new_vertex(graph *self);
void add_edge_on_vertex(graph *self, int vertex,int number);
void remove_edge_on_vertex(graph *self, int vertex, int remove);
int graph_have_ties(graph *self);
int is_complete_graph_list_adj(graph *self);
int has_cicles_list_adj(graph *self);
graph *destroy_graph_list(graph *self);
#endif //UNTITLED68_GRAPH_H

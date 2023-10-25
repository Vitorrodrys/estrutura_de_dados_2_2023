
#ifndef UNTITLED68_GRAFO_MATRIZ_ADJACENCIA_H
#define UNTITLED68_GRAFO_MATRIZ_ADJACENCIA_H


typedef struct graphAdj graphAdj;

graphAdj *create_graph_adj(int quantity_vertex, int is_direct);
graphAdj  *destroy_graph(graphAdj *self);
void add_new_edge(graphAdj *self, int from, int to);
void remove_edge_adj(graphAdj *self, int from, int to);
int has_multiples_edges(graphAdj *self);
int has_ties(graphAdj *self);
int is_simple_graph(graphAdj *self);
int is_multigraph(graphAdj *self);
int is_pseudograph(graphAdj *self);
int is_graph_targeted(graphAdj *self);
int is_multigraph_targeted(graphAdj *self);
int is_complete_graph(graphAdj *self);
int has_cicles(graphAdj *self);
void show_graph(graphAdj *self);

#endif //UNTITLED68_GRAFO_MATRIZ_ADJACENCIA_H

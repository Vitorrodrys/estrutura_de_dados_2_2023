//
// Created by vitor on 06/10/23.
//

#ifndef UNTITLED68_LIST_VERTEX_H
#define UNTITLED68_LIST_VERTEX_H
//API for acess of the vertex
typedef struct no_vertex no_vertex;

no_vertex *create_no_vertex(int number, no_vertex *prox);
int get_number(no_vertex *self);
void set_number(no_vertex * self, int number);
void add_vertex(no_vertex *self, int number);
int have_ties(no_vertex *self, int number);
no_vertex *get_prox(no_vertex *self);
no_vertex* remove_vertex(no_vertex *self, int number);



//API for acess the list of vertex

typedef struct ListVertex ListVertex;
no_vertex *get_first(const ListVertex *self);
ListVertex *create_list_vertex();
ListVertex *destroy_list_vertex(ListVertex *self);
void add_new_edge_vertex(ListVertex *self, int number);
void remove_edge_vertex(ListVertex *self, int remove);
int have_ties_in_vertex(const ListVertex *self, int number_vertex);
int has_edge_to_vertex(const ListVertex *self, int vertex);
int is_complete_vertex(const ListVertex *self, int number_vertex);
#endif //UNTITLED68_LIST_VERTEX_H

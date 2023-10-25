//
// Created by vitor on 06/10/23.
//

#ifndef UNTITLED68_NO_VERTEX_H
#define UNTITLED68_NO_VERTEX_H


typedef struct no_vertex{
    int number;
    struct no_vertex *prox;
}no_vertex;

no_vertex *create_no_vertex(int number, no_vertex *prox);
int get_number(no_vertex *self);
void set_number(no_vertex * self, int number);
no_vertex *add_vertex(no_vertex *self, int number);
no_vertex *get_prox(no_vertex *self);
no_vertex* remove_vertex(no_vertex *self, int number);
no_vertex *destroy_no(no_vertex *self);
#endif //UNTITLED68_NO_VERTEX_H

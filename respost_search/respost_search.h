//
// Created by vitor on 25/10/23.
//

#ifndef UNTITLED68_RESPOST_SEARCH_H
#define UNTITLED68_RESPOST_SEARCH_H

typedef struct RespostSearch RespostSearch;

RespostSearch * create_respost(int tam_graph, int which_vertex);
RespostSearch *destroy_respost(RespostSearch *self);
int to_visite_element(RespostSearch *self, int from, int to, int dist);
int get_next_vertex_queue(RespostSearch *self);
int queue_is_void(RespostSearch *self);
int elem_still_not_visited(RespostSearch *self, int elem);
void print_respost(RespostSearch *self);
#endif //UNTITLED68_RESPOST_SEARCH_H

//
// Created by vitor on 25/10/23.
//

#ifndef UNTITLED68_QUEUE_H
#define UNTITLED68_QUEUE_H
typedef struct queue queue;

int is_full(queue *self);
queue *create_queue(int tam);
queue *destroy_queue(queue *self);
int enqueue(queue *self, int elem);
int dequeue(queue *self);
int is_void(queue *self);
#endif //UNTITLED68_QUEUE_H

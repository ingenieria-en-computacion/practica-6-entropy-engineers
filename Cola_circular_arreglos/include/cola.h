#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#include <stdbool.h>

typedef struct {
    int *array;
    int frente;
    int final;
    int tamaño;
    int capacidad;
} CQueue;

CQueue* cqueue_create(int capacidad);
void cqueue_destroy(CQueue* queue);
void cqueue_print(CQueue* queue);
void cqueue_enqueue(CQueue* queue, int elemento);
void cqueue_dequeue(CQueue* queue);
int cqueue_first(CQueue* queue);
int cqueue_last(CQueue* queue);
bool cqueue_is_empty(CQueue* queue);
bool cqueue_is_full(CQueue* queue);

#endif
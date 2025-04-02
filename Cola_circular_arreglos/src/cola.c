#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

CQueue* cqueue_create(int capacidad) {
    CQueue* queue = (CQueue*)malloc(sizeof(CQueue));
    queue->capacidad = capacidad;
    queue->array = (int*)malloc(queue->capacidad * sizeof(int));
    queue->frente = -1;
    queue->final = -1;
    queue->tamaño = 0;
    return queue;
}

void cqueue_destroy(CQueue* queue) {
    free(queue->array);
    free(queue);
}

bool cqueue_is_empty(CQueue* queue) {
    return queue->tamaño == 0;
}

bool cqueue_is_full(CQueue* queue) {
    return queue->tamaño == queue->capacidad;
}

void cqueue_enqueue(CQueue* queue, int elemento) {
    if (cqueue_is_full(queue)) {
        printf("La cola está llena\n");
        return;
    }
    if (queue->frente == -1) {
        queue->frente = 0;
    }
    queue->final = (queue->final + 1) % queue->capacidad;
    queue->array[queue->final] = elemento;
    queue->tamaño++;
}

void cqueue_dequeue(CQueue* queue) {
    if (cqueue_is_empty(queue)) {
        printf("La cola está vacía\n");
        return;
    }
    if (queue->frente == queue->final) {
        queue->frente = -1;
        queue->final = -1;
    } else {
        queue->frente = (queue->frente + 1) % queue->capacidad;
    }
    queue->tamaño--;
}

int cqueue_first(CQueue* queue) {
    if (cqueue_is_empty(queue)) {
        printf("La cola está vacía\n");
        return -1;
    }
    return queue->array[queue->frente];
}

int cqueue_last(CQueue* queue) {
    if (cqueue_is_empty(queue)) {
        printf("La cola está vacía\n");
        return -1;
    }
    return queue->array[queue->final];
}

void cqueue_print(CQueue* queue) {
    if (cqueue_is_empty(queue)) {
        printf("La cola está vacía\n");
        return;
    }
    int i = queue->frente;
    while (true) {
        printf("%d ", queue->array[i]);
        if (i == queue->final) {
            break;
        }
        i = (i + 1) % queue->capacidad;
    }
    printf("\n");
}
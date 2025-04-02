#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct {
    int* data;
    int head;
    int tail;
    int size;
    int capacity;
} Deque;

// Funciones de la bicola
Deque* deque_create(int capacity);
void deque_destroy(Deque* deque);
bool deque_is_empty(Deque* deque);
bool deque_is_full(Deque* deque);
bool deque_push_front(Deque* deque, int value);
bool deque_push_back(Deque* deque, int value);
bool deque_pop_front(Deque* deque, int* value);
bool deque_pop_back(Deque* deque, int* value);

#endif // DEQUE_H

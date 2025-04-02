#include "deque.h"
#include <stdlib.h>
#include <stdio.h>

Deque* deque_create(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (!deque) return NULL;
    deque->data = (int*)malloc(capacity * sizeof(int));
    if (!deque->data) {
        free(deque);
        return NULL;
    }
    deque->head = -1;
    deque->tail = 0;
    deque->size = 0;
    deque->capacity = capacity;
    return deque;
}

void deque_destroy(Deque* deque) {
    if (deque) {
        free(deque->data);
        free(deque);
    }
}

bool deque_is_empty(Deque* deque) {
    return deque->size == 0;
}

bool deque_is_full(Deque* deque) {
    return deque->size == deque->capacity;
}

bool deque_push_front(Deque* deque, int value) {
    if (deque_is_full(deque)) return false;
    if (deque->head == -1) {
        deque->head = 0;
        deque->tail = 0;
    } else if (deque->head == 0) {
        deque->head = deque->capacity - 1;
    } else {
        deque->head--;
    }
    deque->data[deque->head] = value;
    deque->size++;
    return true;
}

bool deque_push_back(Deque* deque, int value) {
    if (deque_is_full(deque)) return false;
    if (deque->head == -1) {
        deque->head = 0;
        deque->tail = 0;
    } else if (deque->tail == deque->capacity - 1) {
        deque->tail = 0;
    } else {
        deque->tail++;
    }
    deque->data[deque->tail] = value;
    deque->size++;
    return true;
}

bool deque_pop_front(Deque* deque, int* value) {
    if (deque_is_empty(deque)) return false;
    *value = deque->data[deque->head];
    if (deque->head == deque->tail) {
        deque->head = -1;
        deque->tail = 0;
    } else if (deque->head == deque->capacity - 1) {
        deque->head = 0;
    } else {
        deque->head++;
    }
    deque->size--;
    return true;
}

bool deque_pop_back(Deque* deque, int* value) {
    if (deque_is_empty(deque)) return false;
    *value = deque->data[deque->tail];
    if (deque->head == deque->tail) {
        deque->head = -1;
        deque->tail = 0;
    } else if (deque->tail == 0) {
        deque->tail = deque->capacity - 1;
    } else {
        deque->tail--;
    }
    deque->size--;
    return true;
}

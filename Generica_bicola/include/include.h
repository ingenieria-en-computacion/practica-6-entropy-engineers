#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_DEQUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
        struct Node_##TYPE* prev; \
    } Node_##TYPE; \
    Node_##TYPE* node_##TYPE##_create(TYPE data); \
    void node_##TYPE##_destroy(Node_##TYPE* node); \
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } Deque_##TYPE; \
    \
    Deque_##TYPE* deque_##TYPE##_create(void); \
    void deque_##TYPE##_destroy(Deque_##TYPE* deque); \
    bool deque_##TYPE##_push_front(Deque_##TYPE* deque, TYPE data); \
    bool deque_##TYPE##_push_back(Deque_##TYPE* deque, TYPE data); \
    bool deque_##TYPE##_pop_front(Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_pop_back(Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_is_empty(const Deque_##TYPE* deque); \
    size_t deque_##TYPE##_length(const Deque_##TYPE* deque); \
    void deque_##TYPE##_print(const Deque_##TYPE* deque, void (*print_fn)(TYPE));

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_DEQUE(TYPE) \
    Node_##TYPE* node_##TYPE##_create(TYPE data) { \
        Node_##TYPE* new_node = (Node_##TYPE*)malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return NULL; \
        new_node->data = data; \
        new_node->next = new_node->prev = NULL; \
        return new_node; \
    } \
    \
    void node_##TYPE##_destroy(Node_##TYPE* node) { \
        free(node); \
    } \
    \
    Deque_##TYPE* deque_##TYPE##_create(void) { \
        Deque_##TYPE* deque = (Deque_##TYPE*)malloc(sizeof(Deque_##TYPE)); \
        if (!deque) return NULL; \
        deque->head = deque->tail = NULL; \
        deque->length = 0; \
        return deque; \
    } \
    \
    void deque_##TYPE##_destroy(Deque_##TYPE* deque) { \
        if (!deque) return; \
        Node_##TYPE* current = deque->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            node_##TYPE##_destroy(temp); \
        } \
        free(deque); \
    } \
    \
    bool deque_##TYPE##_push_front(Deque_##TYPE* deque, TYPE data) { \
        if (!deque) return false; \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (deque->head) { \
            new_node->next = deque->head; \
            deque->head->prev = new_node; \
            deque->head = new_node; \
        } else { \
            deque->head = deque->tail = new_node; \
        } \
        deque->length++; \
        return true; \
    } \
    \
    bool deque_##TYPE##_push_back(Deque_##TYPE* deque, TYPE data) { \
        if (!deque) return false; \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (deque->tail) { \
            new_node->prev = deque->tail; \
            deque->tail->next = new_node; \
            deque->tail = new_node; \
        } else { \
            deque->head = deque->tail = new_node; \
        } \
        deque->length++; \
        return true; \
    } \
    \
    bool deque_##TYPE##_pop_front(Deque_##TYPE* deque, TYPE* out) { \
        if (!deque || !deque->head) return false; \
        Node_##TYPE* temp = deque->head; \
        *out = temp->data; \
        deque->head = deque->head->next; \
        if (deque->head) { \
            deque->head->prev = NULL; \
        } else { \
            deque->tail = NULL; \
        } \
        node_##TYPE##_destroy(temp); \
        deque->length--; \
        return true; \
    } \
    \
    bool deque_##TYPE##_pop_back(Deque_##TYPE* deque, TYPE* out) { \
        if (!deque || !deque->tail) return false; \
        Node_##TYPE* temp = deque->tail; \
        *out = temp->data; \
        deque->tail = deque->tail->prev; \
        if (deque->tail) { \
            deque->tail->next = NULL; \
        } else { \
            deque->head = NULL; \
        } \
        node_##TYPE##_destroy(temp); \
        deque->length--; \
        return true; \
    } \
    \
    bool deque_##TYPE##_is_empty(const Deque_##TYPE* deque) { \
        return deque ? deque->length == 0 : true; \
    } \
    \
    size_t deque_##TYPE##_length(const Deque_##TYPE* deque) { \
        return deque ? deque->length : 0; \
    } \
    \
    void deque_##TYPE##_print(const Deque_##TYPE* deque, void (*print_fn)(TYPE)) { \
        if (!deque || !print_fn) return; \
        printf("["); \
        Node_##TYPE* current = deque->head; \
        while (current) { \
            print_fn(current->data); \
            if (current->next) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_DEQUE(int)
DECLARE_DEQUE(char)
DECLARE_DEQUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef LINKED_LIST_IMPLEMENTATION
IMPLEMENT_DEQUE(int)
IMPLEMENT_DEQUE(char)
IMPLEMENT_DEQUE(float)
#endif

#define LINKED_LIST_IMPLEMENTATION
#include "../include/include.h" 

void print_int(int value) {
    printf("%d", value);
}

int main() {
    Deque_int* deque = deque_int_create();
    if (!deque) {
        printf("Error al crear la deque.\n");
        return 1;
    }

    deque_int_push_back(deque, 10);
    deque_int_push_back(deque, 20);
    deque_int_push_front(deque, 5);
    deque_int_push_front(deque, 1);

    printf("Contenido de la deque: ");
    deque_int_print(deque, print_int);

    int value;
    if (deque_int_pop_front(deque, &value)) {
        printf("Elemento eliminado del frente: %d\n", value);
    }

    if (deque_int_pop_back(deque, &value)) {
        printf("Elemento eliminado del final: %d\n", value);
    }

    printf("Contenido de la deque después de las eliminaciones: ");
    deque_int_print(deque, print_int);

    deque_int_destroy(deque);
    return 0;
}

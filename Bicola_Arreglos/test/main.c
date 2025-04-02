#include <stdio.h>
#include "deque.h"

int main() {
    Deque* deque = deque_create(5);
    if (!deque) {
        printf("Error al crear la bicola.\n");
        return 1;
    }

    deque_push_back(deque, 10);
    deque_push_back(deque, 20);
    deque_push_front(deque, 5);
    deque_push_back(deque, 30);
    deque_push_front(deque, 1);

    int value;
    while (!deque_is_empty(deque)) {
        deque_pop_front(deque, &value);
        printf("%d ", value);
    }
    printf("\n");

    deque_destroy(deque);
    return 0;
}

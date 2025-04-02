#include <stdio.h>
#include "cola.h"

int main() {
    CQueue* queue = cqueue_create(5);

    cqueue_enqueue(queue, 10);
    cqueue_enqueue(queue, 20);
    cqueue_enqueue(queue, 30);
    cqueue_print(queue);

    printf("Primer elemento: %d\n", cqueue_first(queue));
    printf("Último elemento: %d\n", cqueue_last(queue));

    cqueue_dequeue(queue);
    cqueue_print(queue);

    cqueue_dequeue(queue);
    cqueue_print(queue);

    cqueue_dequeue(queue);
    cqueue_print(queue);

    cqueue_destroy(queue);

    return 0;
}
#include "queue.h"
#include <stdio.h>

void main()
{
    Queue queue = newQueue();
    insertQueue(&queue, 5);
    insertQueue(&queue, 10);
    insertQueue(&queue, 15);

    removeQueue(&queue);
    show(&queue);
}
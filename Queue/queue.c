#include <stdio.h>
#include "queue.h"


void initializeQueue(Queue *queue)
{
  queue->front = 0;
  queue->rear = 0;
  queue->count = 0;
}

Queue newQueue()
{
  Queue queue;
  initializeQueue(&queue);

  return queue;
}

void show(Queue *queue)
{
  int i;
  int j = queue->front;
  for (i = 0; i < queue->count; i++)
  {
    printf("%d\n", queue->items[j]);
    if (j == MaxItems - 1)
    {
      j = 0;
    }
    j++;
  }
}

int emptyQueue(Queue *queue)
{
  return queue->count == 0 ? 1 : 0;
}

int fullQueue(Queue *queue)
{
  return queue->count == MaxItems ? 1 : 0;
}

int insertQueue(Queue *queue, int newItem)
{
  if (fullQueue(queue))
    return (ErrorQueueFull);

  else
  {
    queue->items[queue->rear] = newItem;
    queue->count++;

    if (queue->rear == MaxItems - 1)
      queue->rear = 0;

    else
      queue->rear++;

    return (queue->rear);
  }
}

int removeQueue(Queue *queue)
{
  int removed;
  if (emptyQueue(queue))
    return (ErrorQueueEmpty);

  else
  {
    removed = queue->items[queue->front];
    queue->count--;

    if (queue->front != MaxItems)
      queue->front++;

    else
      queue->front = 0;

    return (queue->front);
  }
}

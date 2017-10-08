#define MaxItems 5
#define ErrorQueueEmpty -2
#define ErrorQueueFull -1

typedef struct
{
    int items[MaxItems];
    int front;
    int rear;
    int count;
} Queue;

Queue newQueue();

void show(Queue *queue);

int insertQueue(Queue *queue, int newItem);

int removeQueue(Queue *queue);

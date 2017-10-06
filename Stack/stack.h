#ifndef __STACK_H__
#define __STACK_H__

#define ErrorStackFull -1
#define ErrorStackEmpty -2
#define maxSize 10

typedef struct
{
    int items[maxSize];
    int top;
} Stack;

void show(Stack *stack);

int push(Stack *stack, int newItem);

int pop(Stack *stack);

Stack newStack(Stack stack);


#endif

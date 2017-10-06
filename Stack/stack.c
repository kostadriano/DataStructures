#include <stdio.h>
#include "stack.h"


Stack newStack(Stack stack){
    initializeStack(&stack);
    return stack;
}

void show(Stack *stack)
{
    int i = stack->top;
    for (; i > 0; i--)
    {
        printf(" %d\n", stack->items[i - 1]);
    }
}

int initializeStack(Stack *stack)
{
    stack->top = 0;
}

int isFull(Stack *stack)
{
    return ((stack->top == maxSize) ? 1 : 0);
}

int isEmpty(Stack *stack)
{
    return ((stack->top == 0) ? 1 : 0);
}

int push(Stack *stack, int newItem)
{
    if (isFull(stack))
        return ErrorStackFull;

    else
    {
        stack->items[stack->top] = newItem;
        stack->top++;
        return (stack->top);
    }
}

int pop(Stack *stack)
{
    int removed;

    if (isEmpty(stack))
        return ErrorStackEmpty;

    else
    {
        stack->top--;
        removed = stack->items[stack->top];
        printf("\nItem Removed: %d\n",removed);
        return removed;
    }
}

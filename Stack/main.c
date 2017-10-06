#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void main(){
    Stack stack = newStack(stack);
    push(&stack,5);
    push(&stack,3);
    push(&stack,4);


    show(&stack);

}
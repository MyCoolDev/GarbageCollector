#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *newStack()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

/* push & pop */
bool push(Stack* stack, Object* obj)
{
    if (stack->size >= STACK_MAX)
        return false;

    stack->stack[stack->size++] = obj;
    obj->next = stack->first;
    stack->first = obj;
    return true;
}

Object* pop(Stack* stack)
{
    if (stack->size == 0)
        return NULL;

    return stack->stack[--stack->size];
}

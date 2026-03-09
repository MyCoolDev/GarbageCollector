#ifndef STACK_H
#define STACK_H
#include "object.h"

#define STACK_MAX       (256)

typedef struct s_stack {
    Object* first;
    Object* stack[STACK_MAX];
    int size;
} Stack;

Stack *newStack();
bool push(Stack* stack, Object* obj);
Object* pop(Stack* stack);
bool pushInt(Stack* stack, int value);
bool pushPair(Stack* stack, Object* head, Object* tail);

#endif

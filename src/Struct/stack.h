#ifndef STACK_H
#define STACK_H
#include "object.h"

#define STACK_MAX       (256)

typedef struct s_stack {
    Object* first;
    Object* stack[STACK_MAX];
    int size;
} Stack;

#endif

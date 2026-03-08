#ifndef GC_H
#define GC_H
#include <stdbool.h>
#include "Struct/object.h"
#include "Struct/stack.c"

bool pushInt(Stack* stack, int value);
bool pushPair(Stack* stack, Object* head, Object* tail);
void markAll(Stack* stack);
void mark(Object* obj);

#endif

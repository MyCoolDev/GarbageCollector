#ifndef GC_H
#define GC_H
#include <stdbool.h>
#include "Struct/object.h"
#include "Struct/stack.c"

void markAll(Stack* vm);
void mark(Object* obj);
Object* sweep(Object* obj);
Object* sweepAll(Object* obj);

#endif

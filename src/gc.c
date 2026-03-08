/**
 * This file will create the base for a virtual language with a garbage collector.
 * We'll use the marking and sweeping technich.
 *
 * ObjectType:
 * We'll implement two object types;
 * - Int
 * - Pair
 * 
 * with these two you can do alot.
 *
 * The virtual lang will use a basic stack.
 *
 */

#include "gc.h"

bool pushInt(Stack* stack, int value)
{
    Object* newObj = createObject(OBJ_INT);
    newObj->value = value;

    return push(stack, newObj);
}

bool pushPair(Stack* stack, Object* head, Object* tail)
{
    Object* newObj = createObject(OBJ_PAIR);
    newObj->head = head;
    newObj->tail = tail;

    return push(stack, newObj);
}

void markAll(Stack* stack)
{
    for (int i = 0; i < stack->size; i++) {
        mark(stack->stack[i]);
    }
}

void mark(Object* obj)
{
    if (obj->marked) return;
    obj->marked = true;

    if (obj->type == OBJ_PAIR)
    {
        obj->head->marked = true;
        obj->tail->marked = true;
    }   
}

void sweep(Object* obj)
{
    
}

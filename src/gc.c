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
#include "Struct/object.h"
#include <stdlib.h>

/**
 * Mark all the "In Use Objects",
 * "In Use Objects" are reachable from the stack.
 */

void markAll(Stack* stack)
{
    for (int i = 0; i < stack->size; i++) {
        mark(stack->stack[i]);
    }
}

/**
 * The actual change of the mark byte in the mem.
 */
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

/**
 * Sweep all the unmarked Objects. Using the sweep func.
 */
Object* sweepAll(Object* obj)
{
    if (obj->next == NULL)
        return sweep(obj);

    obj->next = sweepAll(obj->next);

    return sweep(obj);
}

/**
 * free the unmarked Objects and return his "next" pointer,
 * return the obj if marked.
 */
Object* sweep(Object* obj)
{
    if (obj->marked)
        return obj;

    if (obj->type == OBJ_PAIR)
    {
        sweep(obj->head);
        sweep(obj->tail);
    }

    Object* next = obj->next;
    free(obj);

    return next;
}


/**
 * Garbage collector.
 */
void gc(Stack* stack)
{
    markAll(stack);
    sweepAll(stack->first);
}

#include "object.h"
#include <stdlib.h>

Object* createObject(ObjectType type)
{
    Object* obj = malloc(sizeof(Object));

    obj->marked = 0;
    obj->type = type;

    return obj;
}

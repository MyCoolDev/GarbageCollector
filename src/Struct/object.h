#ifndef OBJECT_H
#define OBJECT_H

typedef enum {
  OBJ_INT,
  OBJ_PAIR
} ObjectType;

typedef struct s_object {
    unsigned int marked;
    ObjectType type;
    
    union {
        /* int type */
        int value;

        /* pair type */
        struct {
            struct s_object* head;
            struct s_object* tail;
        };
    };

    struct s_object* next;
} Object;

Object* createObject(ObjectType type);

#endif

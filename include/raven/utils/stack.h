#pragma once

#include <stddef.h>
#include <stdlib.h>

#define stack(type)         \
    {                       \
        size_t capacity;    \
        int len;            \
        type *objects;      \
    }

#define createStack(StackType, name, ObjType, cap)      \
    StackType *name;                                    \
    name = malloc(sizeof(StackType));                   \
    name->capacity = cap;                               \
    name->len = 0;                                      \
    name->objects = calloc(cap, sizeof(ObjType))        

#define pushStack(s, obj)                                                       \
    do {                                                                        \
        if (s->len + 1 >= s->capacity) {                                        \
            s->capacity *= 2;                                                   \
            s->objects = realloc(s->objects, sizeof(obj) * s->capacity);        \
        }                                                                       \
        s->objects[s->len] = obj;                                               \
        s->len++;                                                               \
    } while(0)

#define peekStack(s, varname, defaultValue)     \
    do {                                        \
        if (s->len - 1 >= 0) {                  \
            varname = s->objects[s->len - 1];   \
        } else {                                \
            varname = defaultValue;             \
        }                                       \
    } while(0)

#define popStack(s, varname, defaultValue)      \
    do {                                        \
        if (s->len - 1 >= 0) {                  \
            s->len--;                           \
            varname = s->objects[s->len];       \
        } else {                                \
            varname = defaultValue;             \
        }                                       \
    } while(0)

#define freeStack(s)    \
    free(s->objects);   \
    free(s);            \

#include <stddef.h>
#include "list.h"

struct element
{
    void *value;
    int type;
};

struct list
{
    struct element *elements;
    int capacity;
    int size;
};

struct list *create_list(int capacity)
{
    struct list *newList = (struct list *)malloc(sizeof(struct list));
    newList->elements = (struct element *)malloc(sizeof(struct element) * capacity);

    if (!newList)
        return NULL;
    if (!newList->elements)
        return NULL;

    newList->capacity = capacity;
    newList->size = 0;
    return newList;
}

void destory_list(struct list *oldList)
{
    free(oldList->elements);
    free(oldList);
}

void add_to_list(struct list *curr, char *value)
{
    //
    if (curr->size == curr->capacity)
    {
        // call list size increaser
    }
}

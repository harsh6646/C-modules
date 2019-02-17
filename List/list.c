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
        _increase_list_size(curr);
    }
    int size = curr->size;
    // go to next available spot in array and set type
    curr->elements[size].type = TYPE_CHAR;
    // create space of value and add it
    char *temp_char = (char *)malloc(sizeof(char));
    if (temp_char)
        curr->elements[size].value = *value;
}

void _increase_list_size(struct list *curr)
{
    int curr_size = curr->size;
    int new_capacity = curr_size * 2;
    // create a array of double size
    struct element *new_array = (struct element *)malloc(sizeof(struct element) * curr_size * 2);
    if (new_array)
    {
        struct element *old_array = curr->elements;
        // copy over elements
        for (int i = 0; i < curr_size; i++)
        {
            new_array[i] = old_array[i];
        }
        // update list data
        curr->capacity = new_capacity;
        curr->elements = new_array;
        // no leaky boi
        free(old_array);
    }
}

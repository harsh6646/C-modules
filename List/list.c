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
    struct element *_elements = oldList->elements;
    // free malloc'd values
    for (int i = 0; i < oldList->size; i++)
    {
        free(_elements[i].value);
    }
    // free array
    // free the data structure
    free(oldList->elements);
    free(oldList);
}

struct list *add_to_list(struct list *curr, int value)
{
    //
    if (curr->size == curr->capacity)
    {
        _increase_list_size(curr);
    }
    int size = curr->size;
    // create space of value and add it
    int *temp_int = (int *)malloc(sizeof(int));
    if (temp_int)
        *temp_int = value;
    else
        return NULL;
    curr->elements[size].value = temp_int;
    curr->elements[size].type = TYPE_INT;
    curr->size++;
    return curr;
}

struct list *remove_from_list(struct list *curr, int index)
{
    free(curr->elements[index].value);
    for (int i = index + 1; i < curr->size; i++)
    {
        curr->elements[i - 1] = curr->elements[i];
    }
    curr->size--;
    if (curr->size < (int)(curr->capacity / 4))
    {
        if (!_decrease_list_size(curr))
            return NULL;
    }
    return curr;
}

struct list *_increase_list_size(struct list *curr)
{
    int curr_size = curr->size;
    int new_capacity = curr_size * 2;
    // create a array of double size
    struct element *new_array = (struct element *)malloc(sizeof(struct element) * new_capacity);
    if (!new_array)
        return NULL;

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
    return curr;
}

struct list *_decrease_list_size(struct list *curr)
{
    int new_capacity = (int)(curr->capacity / 2);
    struct element *new_array = (struct element *)malloc(sizeof(struct element) * new_capacity);
    if (!new_array)
        return NULL;
    // copy to new array
    for (int i = 0; i < curr->size; i++)
    {
        new_array[i] = curr->elements[i];
    }
    // free old array
    free(curr->elements);
    // update the list values
    curr->elements = new_array;
    return curr;
}

// use memcpy and use function pointers to wrap different data types around 1 function
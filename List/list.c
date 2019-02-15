

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
    newList->capacity = capacity;
    newList->elements = (struct element *)malloc(sizeof(struct element) * capacity);
    return newList;
}

void destory_list(struct list *oldList)
{
    free(oldList->elements);
    free(oldList);
}

void add_to_list(void *value)
{
    // determine what it is and do something
    // will need to overload this for the basic types declared in header
}

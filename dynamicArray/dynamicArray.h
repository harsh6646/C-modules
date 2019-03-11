
typedef struct {
    int size;
    int capacity;
    int type;
    void *array;
} dynamicArray;

createDynamicArray(int);

destroyDynamicArray(dynamicArray *);

push(dynamicArray *, void *);

add(dynamicArray *, void *, int);

pop(dynamicArray *);

remove(dynamicArray *, int);

sort(dynamicArray *);

subArray(dynamicArray *, int, int);

concat(dynamicArray *, dynamicArray *);
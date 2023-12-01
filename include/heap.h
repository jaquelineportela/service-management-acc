#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct {
    int os;
    char description[100];
    char priority[10];
    char status[20];
} Service;

typedef struct {
    Service *array;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity);
void destroyHeap(Heap* heap);
void insertHeap(Heap* heap, Service newService);
Service removeHeap(Heap* heap);

#endif

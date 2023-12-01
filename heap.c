#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heap.h"

void swapServices(Service* a, Service* b) {
    Service temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Heap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && strcmp(heap->array[left].priority, heap->array[largest].priority) > 0) {
        largest = left;
    }

    if (right < heap->size && strcmp(heap->array[right].priority, heap->array[largest].priority) > 0) {
        largest = right;
    }

    if (largest != index) {
        swapServices(&heap->array[index], &heap->array[largest]);
        heapify(heap, largest);
    }
}

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (Service*)malloc(capacity * sizeof(Service));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void destroyHeap(Heap* heap) {
    free(heap->array);
    free(heap);
}

void insertHeap(Heap* heap, Service newService) {
    if (heap->size == heap->capacity - 1) {
        printf("Heap cheio. Nao sera possivel inserir mais elementos.\n");
        return;
    }

    heap->size++;
    int index = heap->size - 1;
    heap->array[index] = newService;

    while (index != 0 && strcmp(heap->array[(index - 1) / 2].priority, heap->array[index].priority) < 0) {
        swapServices(&heap->array[(index - 1) / 2], &heap->array[index]);
        index = (index - 1) / 2;
    }
}

Service removeHeap(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap vazio. Nao sera possivel remover mais elementos.\n");
        Service emptyService;
        emptyService.os = -1;
        return emptyService;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    Service root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    heapify(heap, 0);

    return root;
}

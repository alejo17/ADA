#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

typedef struct {
    int *elements;
    int length;
    int heap_size;
} heap;

void max_heapify(heap *heap, int i) {
    int left  = LEFT(i),
        right = RIGHT(i),
        largest;

    if (left <= heap->heap_size && heap->elements[left] > heap->elements[i]) {
        largest = left;
    } else {
        largest = i;
    }

    if (right <= heap->heap_size && heap->elements[right] > heap->elements[largest]) {
        largest = right;
    }

    if (largest != i) {
        int tmp = heap->elements[i];
        heap->elements[i] = heap->elements[largest];
        heap->elements[largest] = tmp;

        max_heapify(heap, largest);
    }
}

void build_max_heap(heap *heap) {
    heap->heap_size = heap->length;
    for(int i = (heap->length)/2; i>0; i--)
        max_heapify(heap,i);
}

void heapsort(heap *heap) {
    build_max_heap(heap);
    for(int i = (heap->length); i>1; i--) {
        int tmp = heap->elements[0];
        heap->elements[0] = heap->elements[i];
        heap->elements[i] = tmp;
        heap->heap_size--;
        max_heapify(heap,0);
    }
}

int heap_maximum(heap *heap) {
    return heap->elements[0];
}

int heap_extract_max(heap *heap) {
    if (heap->heap_size < 1) {
        cout<<"heap underflow";
        exit(0);
    }

    int max = heap->elements[0];
    heap->elements[0] = heap->elements[heap->heap_size - 1];
    heap->heap_size--;
    max_heapify(heap, 0);

    return max;
}

void heap_increase_key(heap *heap, int i, int key) {
    if (key < heap->elements[i]) {
        cout<<"new key is smaller than current key";
        exit(0);
    }

    heap->elements[i] = key;
    while (i > 1 && heap->elements[PARENT(i)] < heap->elements[i]) {
        int tmp = heap->elements[PARENT(i)];
        heap->elements[PARENT(i)] = heap->elements[i];
        heap->elements[i] = tmp;
        i = PARENT(i);
    }
}

void max_heap_insert(heap *heap, int key) {
    if (heap->length == heap->heap_size) {
        cout<<"heap overflow";
        exit(0);
    }

    heap->elements[heap->heap_size] = INT_MIN;
    heap->heap_size++;                                      

    heap_increase_key(heap, heap->heap_size - 1, key);
}

int main() {
    heap *A;
    max_heap_insert(A,2);
    max_heap_insert(A,5);
    max_heap_insert(A,1);
    max_heap_insert(A,20);
    max_heap_insert(A,35);
    max_heap_insert(A,19);
    
    heapsort(A);

    for(int i=0; i<2; i++)
        cout<<A->elements[i]<<endl;


}
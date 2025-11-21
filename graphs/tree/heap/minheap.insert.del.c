/*
Algorithm to insert and delete in a minheap  
- make a heap 
- function to print it
- swap function 
- void_insert
- deleteMin
*/


#include <stdlib.h>
#include <limits.h>

typedef struct Heap {
    int *array;
    int capacity;
    int size;
} Heap;

//a heap is created 
Heap* createHeap(int capacity){
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap-> size = 0;
    heap->capacity = capacity; 
    heap->array = (int *)malloc(capacity* sizeof(int));
    return heap;
}

// printing the heap 

void printHeap(Heap *heap) {
    printf("Heap array: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}


// swapping function is made, where we get the values of two pointers and swap them
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// creating void_insert for min_heap
void insert(Heap *heap, int value) {
    if (heap->size == heap-> capacity){
        printf("Heap is full. No more space.\n");
        return;
    }

    heap-> array[heap->size] = value;

    int i = heap -> size; 
    heap -> size++; 
    while (i!=0 && heap->array[(i-1)/2] > heap-> array[i]){
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2; 
    }
}


//creating deleteMnin function for min_heap

int deleteMin(Heap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int root = heap->array[0];  
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
      int i = 0;

    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < heap->size && heap->array[left] < heap->array[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->array[right] < heap->array[smallest]) {
            smallest = right;
        }
        if (smallest == i)
        break;
   swap(&heap->array[i], &heap->array[smallest]);
        i = smallest;    
    }

    return root;
}

int main() {
    Heap *h = createHeap(10);

    insert(h, 10);
    printHeap(h);    

    insert(h, 40);
    printHeap(h);

    insert(h, 20);
    printHeap(h);

    insert(h, 30);
    printHeap(h);

    insert(h, 15);
    printHeap(h);

    printf("Deleted Min: %d\n", deleteMin(h));
    printHeap(h);

    printf("Deleted Min: %d\n", deleteMin(h));
    printHeap(h);

    return 0;
}

//write pseudo code 

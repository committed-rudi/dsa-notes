/*
Algorithm to insert and delete in a minheap  
- make a heap 
- function to print it
- swap function 
- void_insert
- deleteMin
*/

/*

# PSEUDO CODE 
1. CREATE A HEAP 

2. RULES FOR A MIN HEAP 
    - PARENT INDEX = I-1/2 
    - RIGHT CHILD = 2I+2 
    - LEFT CHILD = 2I+1
    - FOR MIN HEAP CONDITION TO BE TRUE-> CHILD >= PARENT

3. INSERTION 
    - AT THE END OF THE ARRAY, WHERE THE NEXT EMPTY SPOT IS
    - THE NEWLY INSERTED ELEMENT IS THEN BUBBLED UP
    - START COMPARING IF THE INSERTED VALUE IS GREATER THAN THE PARENT VALUE
        - IF YES, THEN KEEP IT THE SAME
        - IF NO, THEN SWAP TILL IT SATISFIES THE CONDITION OF MIN HEAP BY 
          BUBBLING UP TILL IT MEETS A PARENT SMALLER THAN IT
          
4. DELETION 
    - AT THE TOP OF THE ARRAY
        - ROOT ELEMENT IS DELETED 
        - STORE THE ROOT VALUE
        - ROOT IS REPLACED BY THE LAST CHILD NODE IN THE ARRAY 
        - REDUCE THE SIZE 
        - COMPARE THE NEW ROOT WITH THE REST OF ITS CHILDREN 
          - FIND THE SMALLEST CHILD AND SWAP IF THE NEWROOT > CHILD 
          - KEEP SWAPPING DOWNWARDS TILL MINHEAP CONDITION IS SATISFIED

*/

#include <stdio.h>
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

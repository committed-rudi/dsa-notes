/*

PSEUDO CODE FOR HEAPIFY FUNCTION

there's an heap = [4, 10, 3, 5, 1]

1. GO TO THE LAST ELEMENT OF THE HEAP 

which a[4] = 1; 

2. KEEP CHECKING THE SAME ROW TILL THE FIRST ELEMENT
3. GO TO THE PARENT ROW OF THE CURRENT ROW
4. FOR EACH ELEMENT IN THE CURRENT ROW, CHECK IF IT SATISFIES THE HEAP PROPERTY
5. if not, then swap the nodes and make the larger node the parent node 
6. repeat if required 
7. print heapified array


*/

#include <stdio.h>  

// a heapify function 
void heapify(int array[], int n, int i); 

// a buildheap function 
void buildheap(int array[], int n);

void heapify(int array[], int n, int i){
    
    int leftn = 2*i + 1; 
    int rightn = 2*i + 2; 
    int largest = i; 

    if (leftn <n && array[leftn] > array[largest]){
        largest = leftn; 
    }

    if (rightn <n && array[rightn] > array[largest]){
        largest = rightn; 
    }   

    if (largest != i) { 
        int temp = array[i] ; 
        array[i] = array[largest]; 
        array[largest]=temp; 
        heapify(array, n, largest);
    }
}

void buildheap(int array[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(array, n, i);   
}
int main() {

    int n;
    int array[100];

    printf("No of elements in the array : " ); 
    scanf("%d", &n);

    printf("Enter the elements : \n"); 
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    buildheap(array, n);        
    printf("Heapified array is : \n");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    return 0;

}

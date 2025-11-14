#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node {
int v;
int w;
struct Node *next;
} Node;

Node* createNode(int v, int w) {
Node* newNode = (Node*) malloc(sizeof(Node));
newNode->v = v;
newNode->w = w;
newNode->next = NULL;
return newNode;
}

void iM(int m[MAX][MAX], int n) {
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    m[i][j] = 0;
}

void iL(Node* list[], int n) {
    for(int i=0; i<n; i++)
    list[i] = NULL;
}

void addE(int m[MAX][MAX], Node* list[], int src, int dest, int weight, int directed) {
    m[src][dest] = weight;
    if(!directed) m[dest][src] = weight;

    Node* newNode = createNode(dest, weight);
    newNode->next = list[src];
    list[src] = newNode;

    if(!directed) {
        newNode = createNode(src, weight);
        newNode->next = list[dest];
        list[dest] = newNode;
    }
}

void printMatrix(int mat[MAX][MAX], int n) {
    printf("\nAdjacency Matrix:\n");
    for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
    printf("%d ", mat[i][j]);
    printf("\n");
    }
}

void printList(Node* list[], int n) {
    printf("\nAdjacency List:\n");
    for(int i=0; i<n; i++) {
        printf("%d -> ", i);
        Node* temp = list[i];
        while(temp) {
        printf("%d(w=%d) ", temp->v, temp->w);
        temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n = 5;

    int matrix[MAX][MAX];
    Node* list[MAX];

    iM(matrix, n);
    iL(list, n);

    addE(matrix, list, 0, 1, 1, 0);
    addE(matrix, list, 0, 2, 1, 0);
    addE(matrix, list, 1, 3, 1, 0);
    addE(matrix, list, 2, 4, 1, 0);

    printMatrix(matrix, n);
    printList(list, n);

    return 0;
}

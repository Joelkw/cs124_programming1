#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 4

typedef struct node
{
	int num;
	float key;
	struct node *parent;
} node;

// items in our linked list of nodes for the edge matrix of linked lists
typedef struct llnode {
    float edgeWeight;
    int num;
    struct llnode* next;
} llnode;


void printHeap(node* heap[]);
bool minHeapify(node* heap[], int i, node* masterKeys[]);
bool buildMinHeap(node* heap[], node* masterKeys[]);
node* extractMin(node* heap[], node* masterKeys[]);
float prim(int len, node* nodes[len], llnode* edgesMatrix[], node* masterKeys[]);
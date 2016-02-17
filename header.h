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
	int key;
	struct node *parent;
} node;

void printHeap(node* heap[]);
bool minHeapify(node* heap[], int i);
bool buildMinHeap(node* heap[]);
node* extractMin(node* heap[]);
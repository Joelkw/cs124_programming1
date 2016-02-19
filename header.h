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
	bool inQueue;
} node;

typedef struct edge
{
	int to;
	float weight;
	struct edge *next;
} edge;

void printHeap(node* heap[]);
bool minHeapify(node* heap[], int i);
bool buildMinHeap(node* heap[]);
node* extractMin(node* heap[]);
float prim(int len, node* nodes[len+1], edge* edges[len+1]);
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

void printHeap(int heap[]);
bool minHeapify(int heap[], int i);
bool buildMinHeap(int heap[]);

#define SIZE 16

typedef struct node
{
	int num;
	int key;
	struct node *parent;
} node;

typedef struct edge
{
	struct node *to;
	float weight;
} edge;
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

// prints a heap!
void printHeap(node* heap[])
{
	printf("size: %i\n", (int) heap[0]->key);
	for (int j = 1; j <= heap[0]->key; j++)
	{
		printf("%d ", heap[j]->num);
	}
	printf("\n");
}

// inserts an element into a heap
bool minHeapify(node* heap[], int i)
{
	int smallest;
	// find location of left and right children
	int l = 2 * i;
	int r = 2 * i + 1;
	// get size of heap
	int size = (int) heap[0]->key;
	// compare to left child
	smallest = (l <= size && heap[l]->key < heap[i]->key) ? l : i;
	// compare to right child
	if (r <= size && heap[r]->key < heap[smallest]->key)
	{
		smallest = r;
	}
	if (smallest != i)
	{
		// swap heap[i] and heap[smallest]
		node* temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		// update master keys
		masterKeys[(heap[i]->num)] = &heap[i];
		masterKeys[(heap[smallest]->num)] = &heap[smallest];
		// minHeapify the rest
		minHeapify(heap, smallest);
	}
	return true;
}

// plucks an element from the top of the heap
node* extractMin(node* heap[])
{
	int size = (int) heap[0]->key;
	// swap ending node into start of heap
	node* min = heap[1];
	heap[1] = heap[size];
	// decrease size
	heap[0]->key = size - 1;
	// balance our heap
	minHeapify(heap, 1);
	// return node
	return min;
}

// builds a min tree from root
bool buildMinHeap(node* heap[])
{
	// get size of heap
	int size = (int) heap[0]->key;
	// minHeapify the rest of the heap
	for (int i = floor(size / 2); i > 0; i--)
	{
		minHeapify(heap, i);
	}
	return true;
}
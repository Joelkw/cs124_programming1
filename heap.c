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
	/* printf("size: %i\n", (int) heap[0]->key);
	for (int j = 1; j <= heap[0]->key; j++)
	{
		printf("%d ", heap[j]->num);
	}
	printf("\n"); */
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
		heap[i]->loc = i;
		heap[smallest] = temp;
		heap[smallest]->loc = smallest;
		// minHeapify the rest
		minHeapify(heap, smallest);
	}
	return true;
}

// gets parent of a child
int getParent(int index)
{
	if (index % 2 == 1)
	{
		return (index - 1) / 2;
	}
	return index / 2;
}

// bubbles up an element
void bubbleUp(node* heap[], int index)
{
	//printf("BUBBLING UP %i at spot %i \n", heap[index]->num, index);
	// get parent location
	int parent = getParent(index);
	//printf("%i's parent was %i at spot %i", heap[index]->num, heap[parent]->num, parent);
	// swap upwards while needed
	while (index > 1 && heap[parent]->key > heap[index]->key)
	{
		node* temp = heap[index];
		heap[index] = heap[parent];
		heap[index]->loc = index;
		heap[parent] = temp;
		heap[parent]->loc = parent;
		index = parent;
	}
}

// plucks an element from the top of the heap
node* extractMin(node* heap[])
{
	//printf("before extractMin \n");
	printHeap(heap);
	int size = (int) heap[0]->key;
	// swap ending node into start of heap
	node* min = heap[1];
	heap[1] = heap[size];
	heap[1]->loc = 1;
	// decrease size
	heap[0]->key = size - 1;
	// balance our heap
	minHeapify(heap, 1);
	// return node
	//printf("we extracted node %i \n", min->num);
	printHeap(heap);
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
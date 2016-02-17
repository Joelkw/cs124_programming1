#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

// prints a heap!
void printHeap(int heap[])
{
	for (int j = 1; j < SIZE; j++)
	{
		printf("%i ", heap[j]);
	}
	printf("\n");
}

// inserts an element into a heap
bool minHeapify(int heap[], int i)
{
	int smallest;
	// find location of left and right children
	int l = 2 * i;
	int r = 2 * i + 1;
	// compare to left child
	smallest = (l <= SIZE && heap[l] < heap[i]) ? l : i;
	// compare to right child
	if (l <= SIZE && heap[r] < heap[smallest])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		// swap heap[i] and heap[smallest]
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		// minHeapify the rest
		minHeapify(heap, smallest);
	}
	return true;
}

// plucks an element from the top of the heap
int extractMin(int heap[])
{
	int min = heap[1];
	heap[1] = heap[heap[0]];
	heap[0] = heap[0] - 1;
	minHeapify(heap, 1);
	return min;
}

// builds a min tree from root
bool buildMinHeap(int heap[])
{
	// minHeapify the rest of the heap
	for (int i = floor(SIZE / 2); i > 0; i--)
	{
		minHeapify(heap, i);
	}
	return true;
}
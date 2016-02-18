#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 16

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
	printHeap(heap);
	int smallest;
	// find location of left and right children
	int l = 2 * i;
	int r = 2 * i + 1;
	printf("A[%i] = %i, A[%i] = %i, A[%i] = %i\n", i, heap[i],
			l, heap[l], r, heap[r]);
	// compare to left child
	if (l <= SIZE && heap[l] < heap[i])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	// compare to right child
	if (l <= SIZE && heap[r] < heap[smallest])
	{
		smallest = r;
	}
	// swap, if needed
	if (smallest != i)
	{
		// swap heap[i] and heap[smallest]
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		printf("swapping indices %i and %i\n", i, smallest);
		// minHeapify the rest
		minHeapify(heap, smallest);
	}
	return true;
}

// builds a min tree in root
bool buildMinHeap(int heap[])
{
	printHeap(heap);
	// max heapify repeatedly
	for (int i = floor((SIZE - 1) / 2); i > 0; i--)
	{
		printf("looking @ index %i\n", i);
		minHeapify(heap, i);
	}
	return true;
}

int main(int argc, char* argv[])
{
	// initialize our heap
	int heap[SIZE] = {0, 2, 8, 5, 7, 6, 3, 1, 4,
					  15, 17, 19, 100, 12, -1, 10};
	printHeap(heap);
	buildMinHeap(heap);
	printHeap(heap);
}
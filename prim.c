#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

int main(int argc, char* argv[])
{
	// initialize our heap
	int heap[SIZE] = {0, 2, 8, 5, 7, 6, 3, 1, 4,
					  15, 17, 19, 100, 12, -1, 10};
	printHeap(heap);
	buildMinHeap(heap);
	printHeap(heap);
}
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
	// initialize all of our nodes
	node* nodes[5]; 
	for (int i = 0; i <= 4; i++)
	{
		nodes[i] = malloc(sizeof(node));
		nodes[i]->num = i;
		nodes[i]->key = 2;
		nodes[i]->parent = NULL;
	}

	// by default, let the 0th node be the size of the heap
	nodes[0]->key = 4;
	// set the root's key to 0
	nodes[1]->key = 0;

	// heapify our nodes
	buildMinHeap(nodes);

	// initialize all of our edges

	// while the queue is not empty, extract minimum node
	while(nodes[0]->key != 0)
	{
		// get minimum node
		node* u = extractMin(nodes);
		int num = u->key;

		// get edges in graph adjacent to u

		nodes[0]->key--;
	} 

	// return the size of our MST
	printf("Size: %i\n", 4);
}
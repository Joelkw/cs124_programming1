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
	float edges[5][5];
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			// ensure mirroring
			edges[i][j] = 0.2 + j / 10 + i / 15;
			edges[i][j] = 0.2 + j / 10 + i / 15; 
		}
	}

	// while the queue is not empty, extract minimum node
	while(nodes[0]->key != 0)
	{
		// get minimum node
		node* u = extractMin(nodes);
		// get number of node
		int num = u->num;

		// get edges in graph adjacent to u
		for (int i = 1; i < 5; i++)
		{
			// get node i
			node* nodeV = malloc(sizeof(node));
			nodeV->num = i;
			nodeV->key = 300;
			nodeV->parent = NULL;
			// get weight from node i to u
			float weight = edges[num][i];
			// get node i's key ????
			float ikey = 3;
			// see if node is in our existing queue ????
			bool inQueue = true;
			if (inQueue && weight < i)
			{
				
			}
		}
	}

	// find length of MST tree by SUMMING UP KID PARENT WEIGHTS!!!
	int sum = 0;
	for (int i = 1; i < 5; i++)
	{
		sum += nodes[i]->key;
	}

	// return the size of our MST
	printf("Length of MST: %i\n", sum);
}
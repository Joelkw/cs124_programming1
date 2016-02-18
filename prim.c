#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

float prim(int len, node* nodes[len+1], float edges[len+1][len+1])
{
	// heapify our nodes
	buildMinHeap(nodes);

	// create a forest to store our path
	node* forest[len];

	// while the queue is not empty, extract minimum node
	int index = 0;
	while(nodes[0]->key != 0)
	{
		// get minimum node
		node* u = extractMin(nodes);
		// get number of node
		int num = u->num;
		// get edges still in queue & adjacent to u
		for (int i = 1; i < len + 1 - index; i++)
		{
			// get node at ith place
			node* nodeV = nodes[i];
			// get weight from node i to u
			float weight = edges[num][nodeV->num];
			// if our weight is lower than node i's key
			if (weight < nodeV->key)
			{
				// printf("key from %f to %f\n", nodeV->key, weight);
				nodeV->parent = u;
				nodeV->key = weight;
			}
		}
		forest[index] = u;
		index++;
	}

	// find length of MST by summing up parent-kids in forest
	float sum = 0;
	for (int i = 0; i < len; i++)
	{
		node* u = forest[i];
		// printf("key %f at num %i\n", u->key, u->num);
		sum += u->key;
	}

	// free our edges and root
	for (int i = 0; i < len; i++)
	{
		free(forest[i]);
	}
	free(nodes[0]);

	// return the size of our MST
	printf("Length of MST: %f\n", sum);
	return sum;
}
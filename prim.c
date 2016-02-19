#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

float prim(int len, node* nodes[len+1], edge* edges[len+1])
{
	// heapify our nodes
	buildMinHeap(nodes);

	// create a forest to store our path
	node* forest[len];

	// make a copy of nodes, in order
	node* master[len+1];
	for (int i = 0; i <=len; i++)
	{
		master[nodes[i]->num] = nodes[i];
	}

	// while the queue is not empty, extract minimum node
	int index = 0;
	while(nodes[0]->key != 0)
	{
		// get minimum node
		node* u = extractMin(nodes);
		// take u out of queue
		u->inQueue = false;
		// get number of node
		int num = u->num;
		printf("Removed %i from queue\n", num);
		// print out edges
		edge* w = edges[num];
		printf("Edges at %i: ", num);
		while (w != NULL)
		{
			printf("%f ", w->weight);
			w = w->next;
		}
		printf("\nLook at adjacent edges...\n");
		// get edges adjacent to u
		for (edge* ptr = edges[num]; ptr != NULL; ptr = ptr->next)
		{
			float weight = ptr->weight;
			node* nodeV = master[ptr->to];
			// if weight is lower than other's key
			printf("Node %i %i has key %f -> weight %f, and inQueue = %i\n",
					ptr->to, nodeV->num, nodeV->key, weight, nodeV->inQueue);
			// if we're in the queue
			if (!nodeV->inQueue && weight < nodeV->key)
			{
				printf("We made an actual switch from %f to %f\n", nodeV->key, weight);
				nodeV->parent = u;
				// percolate up....
				nodeV->key = weight;
			}
		}
		printf("Done with this iteration.\n");
		forest[index] = u;
		index++;
	}

	// find length of MST by summing up parent-kids in forest
	float sum = 0;
	for (int i = 0; i < len; i++)
	{
		node* u = forest[i];
		printf("key %f at num %i\n", u->key, u->num);
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
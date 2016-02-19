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
		edge* ptr = edges[num];
		// get edges adjacent to u
		while (ptr != NULL)
		{
			float weight = ptr->weight;
			node* nodeV = nodes[ptr->to];
			// if weight is lower than other's key
				printf("key from %f to %f\n",
						nodeV->key, weight);
			if (!nodeV->inQueue && weight < nodeV->key)
			{
				printf("key from %f to %f\n",
						nodeV->key, weight);
				nodeV->parent = u;
				nodeV->key = weight;
			}
			ptr = ptr->next;
		}

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
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
	int order[len+1];
	int x = 0;
	// heapify our nodes
	buildMinHeap(nodes);

	// make a copy of nodes, in order
	node* master[len+1];
	for (int i = 0; i <=len; i++)
	{
		master[nodes[i]->num] = nodes[i];
	}

	// while the queue is not empty, extract minimum node
	while(nodes[0]->key != 0)
	{
		// get minimum node
		node* u = extractMin(nodes);
		// take u out of queue
		u->inQueue = false;
		// get number of node
		int num = u->num;
		// record order of node
		order[x++] = num;
		// get edges adjacent to u
		for (edge* ptr = edges[num]; ptr != NULL; ptr = ptr->next)
		{
			float weight = ptr->weight;
			node* nodeV = master[ptr->to];
			// if weight is lower than other's key and we're in the queue
			if (nodeV->inQueue && weight < nodeV->key)
			{
				nodeV->parent = u;
				nodeV->key = weight;
				// bubble up!!!
				bubbleUp(nodes, nodeV->loc);
			}
		}
	}

	// find length of MST by summing up parent-kids in master
	float sum = 0;
	for (int i = 0; i < len; i++)
	{
		node* u = master[i];
		sum += u->key;
	}

	// free all edges and root
	for (int i = 1; i < len; i++)
	{
		free(master[i]);
	}
	free(nodes[0]);

	// return the size of our MST
	printf("Length of MST: %f\n", sum);
	return sum;
}
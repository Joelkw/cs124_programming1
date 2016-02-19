#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

float prim(int len, node* nodes[len+1], llnode* edgesMatrix[len+1], node* masterKeys[len+1])
{
	// heapify our nodes
	buildMinHeap(nodes);

	// create a forest to store our path
	node* forest[len];

	// while the queue is not empty, extract minimum node
	int index = 0;
	while(nodes[0]->key != 0)
	{
		// get minimum node that is NOT in our tree so far
		node* u = extractMin(nodes);
		// get number of node
		int num = u->num;

		// get nodes ALSO NOT IN TREE AND still in queue & adjacent to u
		// the adjacent to u part is what needs to change
		for (llnode* ptr = edgesMatrix[num]; ptr != NULL; ptr = ptr->next)
		{
			// get the node adjacent to it and its edge
			float weight = ptr->edgeWeight;

			// get its name/number
			float nodeV = ptr->num;

			// if our weight is lower than it's key
			// NEED SOME MASTER POINTER THING, then change it and then continue;
			if (weight < ((&masterKeys[nodeV])->key))
			{
				(&masterKeys[nodeV])->parent = u;
				(&masterKeys[nodeV])->key = weight;

			}

		}
		// this was the old loop
		// for (int i = 1; i < len + 1 - index; i++)
		// {
		// 	// get node at ith place that is adjacent to u, which is not in the tree
		// 	node* nodeV = nodes[i];
		// 	// get weight from node i to u
		// 	float weight = edgesMatrix;
		// 	// if our weight is lower than node i's key
		// 	if (weight < nodeV->key)
		// 	{
		// 		// printf("key from %f to %f\n", nodeV->key, weight);
		// 		nodeV->parent = u;
		// 		nodeV->key = weight;
		// 	}
		// }
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
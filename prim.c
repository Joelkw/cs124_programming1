#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

float prim(node* nodes[5], float edges[5][5])
{
	// heapify our nodes
	buildMinHeap(nodes);

	// create a forest to store our path
	node* forest[4];

	// while the queue is not empty, extract minimum node
	int index = 0;
	while(nodes[0]->key != 0)
	{
		// get minimum node
		node* u = extractMin(nodes);
		// get number of node
		int num = u->num;
		// get edges still in queue & adjacent to u
		for (int i = 1; i < 5 - index; i++)
		{
			// get node at ith place
			node* nodeV = nodes[i];
			// get weight from node i to u
			float weight = edges[num][nodeV->num];
			// if our weight is lower than node i's key
			if (weight < nodeV->key)
			{
				printf("key from %f to %f\n", nodeV->key, weight);
				nodeV->parent = u;
				nodeV->key = weight;
			}
		}
		forest[index] = u;
		index++;
	}

	// find length of MST by summing up parent-kids in forest
	float sum = 0;
	for (int i = 0; i <= 3; i++)
	{
		node* u = forest[i];
		printf("key %f at num %i\n", u->key, u->num);
		sum += u->key;
	}

	// free our edges and root
	for (int i = 0; i < 4; i++)
	{
		free(forest[i]);
	}
	free(nodes[0]);

	// return the size of our MST
	printf("Length of MST: %f\n", sum);
	return sum;
}

int main(int argc, char* argv[])
{
	// initialize all of our nodes
	node* nodes[5]; 
	for (int i = 0; i <= 4; i++)
	{
		nodes[i] = malloc(sizeof(node));
		nodes[i]->num = i;
		nodes[i]->key = 10 + i;
		nodes[i]->parent = NULL;
	}

	// let the 0th node be the size of the heap
	nodes[0]->key = 4;
	// set the root's key to 0
	nodes[1]->key = 0;

	// initialize all of our edges
	float edges[5][5];
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			// ensure mirroring
			edges[i][j] = 0.2 + (float) j / 10 + (float) i / 3;
			edges[j][i] = edges[i][j]; 
		}
	}

	// print out edges (for fun)
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			printf("%f ", edges[i][j]); 
		}
		printf("\n");
	}

	float x = prim(nodes, edges);
}
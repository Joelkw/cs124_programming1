// CS124 - Programming Assignment 1
// Joel Kwartler & Arianna Benson
 
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h> // necessary for sqrt()

#include "header.h"

// nodes for min heap eventually, linked list right now
typedef struct llnode {
    float dist;
    int llnodeIndex;
    struct llnode* next;
} llnode;

// returns a random float between 0 and 1 inclusive 
float randNum() 
{
	float rando = rand();
	float randNum = (rando / RAND_MAX);
	return randNum;
}

// we may want to fold this in eventually to optimize
// ( (x1,y1,x2,y2) <- IMPORTANT )
float dist2d(float x1, float y1, float x2, float y2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

float dist3d(float x1, float y1, float z1, float x2, float y2, float z2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}

int main(int argc, char* argv[])
{
	// make sure format was correct
	if (argc != 5)
	{
		printf("wrong syntax; should be 'randmst 0 numpoints numtrials dimension\r\n'");
		return 0;
	}

	// get our arguments
	int flag = atoi(argv[1]);
	int numpoints = atoi(argv[2]);
	// for debugging purposes
	numpoints = 4;
	int numtrials = atoi(argv[3]);
	int dimension = atoi(argv[4]);
	printf("numpoints %d, numtrials %d, dimension %d, flag %d \r\n", 
		   numpoints, numtrials, dimension, flag);

	// seed the random number generator
	srand(time(NULL));

	// begin timing
	clock_t start = clock();
	clock_t diff;

	node* nodes[numpoints]; 

	// iterate through trials
	for (int t = 0; t < numtrials; t++)
	{
		for (int i = 0; i <= numpoints; i++)
		{
			nodes[i] = malloc(sizeof(node));
			nodes[i]->num = i;
			nodes[i]->key = 10 + i;
			nodes[i]->parent = NULL;
		}

		// let the 0th node be the size of the heap
		nodes[0]->key = numpoints;
		// set the root's key to 0
		nodes[1]->key = 0;

		// create adjacency matrix for edgeweights
		float edgeWeights[numpoints+1][numpoints+1];

		// match on dimension type
		if (dimension == 0)
		{
			// fill adjcacency matrix with edgeweights
			for (int i = 1; i <= numpoints; i++)
			{
				for (int j = 1; j <= numpoints; j++)
				{
					edgeWeights[i][j] = randNum();
					// ensure mirroring
					edgeWeights[j][i] = edgeWeights[i][j]; 
				}
			}
		}

		if (dimension == 2) 
		{
			// a place for our x and y coordinates
			float xs[numpoints];
			float ys[numpoints];
			// generate our points
			for (int i = 1; i <= numpoints; i++) 
			{
				xs[i] = randNum();
				ys[i] = randNum();
			}
			// calculate all of our edges
			for (int i = 1; i <= numpoints; i++)
			{
				// j wil loop through other nodes
				for (int j = 1; j <= numpoints; j++)
				{
					edgeWeights[i][j] = dist2d(xs[i],ys[i],xs[j],ys[j]);
					// ensure mirroring
					edgeWeights[j][i] = edgeWeights[i][j];
				}
			}
		}

		if (dimension == 3) 
		{
			// a place for our x, y, and z coordinates
			float xs[numpoints];
			float ys[numpoints];
			float zs[numpoints];
			// generate our points
			for (int i = 1; i <= numpoints; i++) 
			{
				xs[i] = randNum();
				ys[i] = randNum();
				zs[i] = randNum();
			}
			// calculate all of our edges
			for (int i = 1; i < numpoints; i++)
			{
				// j will loop through other nodes
				for (int j = 1; j <= numpoints; j++)
				{
					edgeWeights[i][j] = dist3d(xs[i],ys[i],zs[i],xs[j],ys[j],zs[j]);
					// ensure mirroring
					edgeWeights[j][i] = edgeWeights[i][j];
				}
			}
		}

		// once we have generated all of our nodes and edges, run prim's!
		float x = prim(nodes, edgeWeights);
	}

	// end timing
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;

	// output results
	printf("%i trials of dim%i with %i points took %d seconds and %d milliseconds \n",
			numtrials, dimension, numpoints, msec/1000, msec%1000);
}
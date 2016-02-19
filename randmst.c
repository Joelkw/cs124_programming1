// CS124 - Programming Assignment 1
// Joel Kwartler & Arianna Benson
 
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h> // necessary for sqrt()

#include "header.h"

// returns a random float between 0 and 1 inclusive 
float randNum() 
{
	float rando = rand();
	float randNum = (rando / RAND_MAX);
	return randNum;
}

// generates 0-dimensional edge weights
void gen0Dim(int len, edge* edgeWeights[len+1])
{
	// fill adjcacency matrix with edgeweights
	for (int i = 1; i <= len; i++)
	{
		edge* root = malloc(sizeof(edge));
		for (int j = 1; j <= len; j++)
		{
			// create our node, affix to beginning
			edge* new = malloc(sizeof(edge));
			new->to = j;
			new->weight = randNum();
			printf("weight is %f\n", new->weight);
			new->next = root;
			// ensure mirroring
			edge* new2 = malloc(sizeof(edge));
			new2->to = i;
			new2->weight = new->weight;
			new2->next = edgeWeights[j];
			edgeWeights[j] = new2;
		}
		edgeWeights[i] = root;
	}
}

float dist2d(float x1, float y1, float x2, float y2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

// generates 2-dimensional edge weights
void gen2Dim(int len, float edgeWeights[len+1][len+1])
{
	// a place for our x and y coordinates
	float xs[len];
	float ys[len];
	// generate our points
	for (int i = 1; i <= len; i++) 
	{
		xs[i] = randNum();
		ys[i] = randNum();
	}
	// calculate all of our edges
	for (int i = 1; i <= len; i++)
	{
		// j wil loop through other nodes
		for (int j = 1; j <= len; j++)
		{
			edgeWeights[i][j] = dist2d(xs[i],ys[i],xs[j],ys[j]);
			// ensure mirroring
			edgeWeights[j][i] = edgeWeights[i][j];
		}
	}
}

float dist3d(float x1, float y1, float z1, float x2, float y2, float z2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}

// generates 3-dimensional edge weights
void gen3Dim(int len, float edgeWeights[len+1][len+1])
{
	// a place for our x, y, and z coordinates
	float xs[len];
	float ys[len];
	float zs[len];
	// generate our points
	for (int i = 1; i <= len; i++) 
	{
		xs[i] = randNum();
		ys[i] = randNum();
		zs[i] = randNum();
	}
	// calculate all of our edges
	for (int i = 1; i < len; i++)
	{
		// j will loop through other nodes
		for (int j = 1; j <= len; j++)
		{
			edgeWeights[i][j] = dist3d(xs[i],ys[i],zs[i],xs[j],ys[j],zs[j]);
			// ensure mirroring
			edgeWeights[j][i] = edgeWeights[i][j];
		}
	}
}

float dist4d(float x1, float y1, float z1, float t1, float x2, float y2, float z2, float t2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)+(t2-t1)*(t2-t1));
}

// generates 4-dimensional edge weights
void gen4Dim(int len, float edgeWeights[len+1][len+1])
{
	// a place for our x, y, z, and t coordinates
	float xs[len];
	float ys[len];
	float zs[len];
	float ts[len];

	// generate our points
	for (int i = 1; i <= len; i++) 
	{
		xs[i] = randNum();
		ys[i] = randNum();
		zs[i] = randNum();
		ts[i] = randNum();
	}
	// calculate all of our edges
	for (int i = 1; i < len; i++)
	{
		// j will loop through other nodes
		for (int j = 1; j <= len; j++)
		{
			edgeWeights[i][j] = dist4d(xs[i],ys[i],zs[i],ts[i],
									   xs[j],ys[j],zs[j],ts[j]);
			// ensure mirroring
			edgeWeights[j][i] = edgeWeights[i][j];
		}
	}
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
		// create all of our nodes
		for (int i = 0; i <= numpoints; i++)
		{
			nodes[i] = malloc(sizeof(node));
			nodes[i]->num = i;
			nodes[i]->key = 10 + i;
			nodes[i]->parent = NULL;
			nodes[i]->inQueue = true;
		}
		// let the 0th node be the size of the heap
		nodes[0]->key = numpoints;
		// set the root's key to 0
		nodes[1]->key = 0;

		// create list of linked lists
		edge* edgeWeights[numpoints+1];

		// match on dimension type
		if (dimension == 0)
		{
			gen0Dim(numpoints, edgeWeights);
		}
		/*
		else if (dimension == 2) 
		{
			gen2Dim(numpoints, edgeWeights);
		}
		else if (dimension == 3) 
		{
			gen3Dim(numpoints, edgeWeights);
		}
		else
		{
			gen4Dim(numpoints, edgeWeights);
		} */

		// once we have generated all of our nodes and edges, run prim's!
		float x = prim(numpoints, nodes, edgeWeights);
	}

	// end timing
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;

	// output results
	printf("%i trials of dim%i with %i points took %d seconds and %d milliseconds \n",
			numtrials, dimension, numpoints, msec/1000, msec%1000);
}
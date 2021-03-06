// CS124 - Programming Assignment 1
// Joel Kwartler & Arianna Benson
 
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "header.h"

// returns a random float between 0 and 1 inclusive 
float randNum() 
{
	float rando = rand();
	float randNum = (rando / RAND_MAX);
	return randNum;
}

// generates weight for pruning
float getK(int numpoints, int dim, int flag)
{
	// prune nothing if flag is on
	if (flag == 1 || numpoints < 1024) 
	{
		return 1.0;
	}
	if (dim == 2)
	{
		return 0.521;
	}
	if (dim == 3)
	{
		return 0.662;
	}
	if (dim == 4)
	{
		return 0.777;
	}
	return 1.0;
}

// generates 0-dimensional edge weights
void gen0Dim(int len, edge* edgeWeights[len+1], float k)
{
	// instantiate edgeweights as NULL
	for (int i = 1; i <= len; i++)
	{
		edgeWeights[i] = NULL;
	}

	// fill array of linked lists with edgeweights
	for (int i = 1; i <= len; i++)
	{
		edge* root = edgeWeights[i];
		for (int j = i; j <= len; j++)
		{
			float w = randNum();
			// if we haven't pruned the edge
			if (w < k)
			{
				// create our node, affix to beginning
				edge* new = malloc(sizeof(edge));
				new->to = j;
				new->weight = w;
				new->next = root;
				root = new;
				// ensure mirroring
				edge* new2 = malloc(sizeof(edge));
				new2->to = i;
				new2->weight = new->weight;
				new2->next = edgeWeights[j];
				edgeWeights[j] = new2;
			}
		}
		edgeWeights[i] = root;
	}
}

float dist2d(float x1, float y1, float x2, float y2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

// generates 2-dimensional edge weights
void gen2Dim(int len, edge* edgeWeights[len+1], float k)
{
	// a place for our x and y coordinates
	float *xs = malloc(sizeof(float) * (len+1));
	float *ys = malloc(sizeof(float) * (len+1));

	// generate our points
	for (int i = 1; i <= len; i++) 
	{
		xs[i] = randNum();
		ys[i] = randNum();
	}

	// instantiate edgeweights as NULL
	for (int i = 1; i <= len; i++)
	{
		edgeWeights[i] = NULL;
	}
	// fill array of linked lists with edgeweights
	for (int i = 1; i <= len; i++)
	{
		edge* root = edgeWeights[i];
		// j wil loop through other nodes
		for (int j = i; j <= len; j++)
		{
			float w = dist2d(xs[i],ys[i],xs[j],ys[j]);
			// if we haven't pruned the edge
			if (w < k) 
			{
				edge* new = malloc(sizeof(edge));
				new->to = j;
				new->weight = w;
				new->next = root;
				root = new;
				// ensure mirroring
				edge* new2 = malloc(sizeof(edge));
				new2->to = i;
				new2->weight = new->weight;
				new2->next = edgeWeights[j];
				edgeWeights[j] = new2;
			}
		}
		edgeWeights[i] = root;
	}

	// free storage
	free(xs);
	free(ys);
}

float dist3d(float x1, float y1, float z1, float x2, float y2, float z2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}

// generates 3-dimensional edge weights
void gen3Dim(int len, edge* edgeWeights[len+1], float k)
{
	// a place for our x, y, and z coordinates
	float *xs = malloc(sizeof(float) * (len+1));
	float *ys = malloc(sizeof(float) * (len+1));
	float *zs = malloc(sizeof(float) * (len+1));

	// generate our points
	for (int i = 1; i <= len; i++) 
	{
		xs[i] = randNum();
		ys[i] = randNum();
		zs[i] = randNum();
	}

	// instantiate edgeweights as NULL
	for (int i = 1; i <= len; i++)
	{
		edgeWeights[i] = NULL;
	}
	// fill array of linked lists with edgeweights
	for (int i = 1; i <= len; i++)
	{
		edge* root = edgeWeights[i];
		// j will loop through other nodes
		for (int j = i; j <= len; j++)
		{
			float w = dist3d(xs[i],ys[i],zs[i],xs[j],ys[j],zs[j]);
			// if we haven't pruned the edge
			if (w < k) 
			{
				edge* new = malloc(sizeof(edge));
				new->to = j;
				new->weight = w;
				new->next = root;
				root = new;
				// ensure mirroring
				edge* new2 = malloc(sizeof(edge));
				new2->to = i;
				new2->weight = new->weight;
				new2->next = edgeWeights[j];
				edgeWeights[j] = new2;
			}
		}
		edgeWeights[i] = root;
	}

	// free storage
	free(xs);
	free(ys);
	free(zs);
}

float dist4d(float x1, float y1, float z1, float t1, float x2, float y2, float z2, float t2) 
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)+(t2-t1)*(t2-t1));
}

// generates 4-dimensional edge weights
void gen4Dim(int len, edge* edgeWeights[len+1], float k)
{
	// a place for our x, y, z, and t coordinates
	float *xs = malloc(sizeof(float) * (len+1));
	float *ys = malloc(sizeof(float) * (len+1));
	float *zs = malloc(sizeof(float) * (len+1));
	float *ts = malloc(sizeof(float) * (len+1));

	// generate our points
	for (int i = 1; i <= len; i++) 
	{
		xs[i] = randNum();
		ys[i] = randNum();
		zs[i] = randNum();
		ts[i] = randNum();
	}

	// instantiate edgeweights as NULL
	for (int i = 1; i <= len; i++)
	{
		edgeWeights[i] = NULL;
	}

	// fill array of linked lists with edgeweights
	for (int i = 1; i <= len; i++)
	{
		edge* root = edgeWeights[i];
		// loop through all other nodes
		for (int j = i; j <= len; j++)
		{
			float w = dist4d(xs[i],ys[i],zs[i],ts[i], xs[j],ys[j],zs[j],ts[j]);
			// if we haven't pruned the edge
			if (w < k) 
			{
				// create our node, affix to beginning
				edge* new = malloc(sizeof(edge));
				new->to = j;
				new->weight = w;
				new->next = root;
				root = new;
				// ensure mirroring
				edge* new2 = malloc(sizeof(edge));
				new2->to = i;
				new2->weight = new->weight;
				new2->next = edgeWeights[j];
				edgeWeights[j] = new2;
			}
		}
		edgeWeights[i] = root;
	}

	// free storage
	free(xs);
	free(ys);
	free(zs);
	free(ts);
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
	float avgMST;

	// begin timing
	clock_t start = clock();
	clock_t diff;

	node* nodes[numpoints]; 

	// get a k function to prune edges longer than k
	float k = getK(numpoints, dimension, flag);

	printf("k was %f \n", k);

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
			nodes[i]->loc = i;
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
			gen0Dim(numpoints, edgeWeights, k);
		}
		else if (dimension == 2) 
		{
			gen2Dim(numpoints, edgeWeights, k);
		}
		else if (dimension == 3) 
		{
			gen3Dim(numpoints, edgeWeights, k);
		}
		else
		{
			gen4Dim(numpoints, edgeWeights, k);
		} 

		// once we have generated all of our nodes and edges, run prim's!
		float x = prim(numpoints, nodes, edgeWeights);

		// update this so we can take an average
		avgMST += x; 
	}

	// end timing
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;

	// calculate average MST length
	avgMST = avgMST / numtrials;

	// output results
	printf("%i trials of dim%i with %i points took %d seconds and %d milliseconds \n avgMST size was: %2.6f \n",
			numtrials, dimension, numpoints, msec/1000, msec%1000, avgMST);
}
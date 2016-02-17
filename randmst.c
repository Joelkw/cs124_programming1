// CS124 - Programming Assignment 1
// Joel Kwartler & Arianna Benson
 
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h> // necessary for sqrt()

// nodes for min heap eventually, linked list right now
typedef struct node {
    float dist;
    int nodeIndex;
    struct node* next;
} node;

// returns a random float between 0 and 1 inclusive 
float randNum() 
{
	float rando = rand();
	float randNum = (rando / RAND_MAX);
	return randNum;
}

// our heap implementation:

// a function to display a dimension 0 graph
int displayDim0(int numpoints, float edgeWeights[65536][65536]) 
{
	// printf("graph dimension 0 is: \r\n");
	// printf("xxx ");
	// for (float k = 0.0; k < numpoints; k++ )
	// {
	// 	printf("%2.6f ", k);
	// }
	// printf("\r\n");
	// for (int i = 0; i < numpoints; i++)
	// {
	// 	printf("%d:  ", i);
	// 	for (int j = 0; j < numpoints; j++)
	// 	{
	// 		printf("%2.6f ", edgeWeights[1][j]);
	// 	}
	// 	printf("\r\n");
	// }
	return 0;
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

int main (int argc, char* argv[])
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

	// match on dimension type
	if (dimension == 0)
	{
		// start timer
		clock_t start = clock();
		clock_t diff;
		// build a graph stored as an adjacency matrix
		// we know there is every possible edge so we just need points
		float edgeWeights[numpoints][numpoints];	
		// fill it with edge weights
		for (int i = 0; i < numpoints; i++)
		{
			for (int j = 0; j < numpoints; j++)
			{
				edgeWeights[i][j] = randNum();
			}
		}

		// THIS IS A FUNCTION FOR DEBUGGING
		// IT PRINTS THE MATRIX
		// printf("edgeweight[1][0] %2.6f \r\n", edgeWeights[1][0]);
		// displayDim0(numpoints, edgeWeights);

		// printf("graph dimension 0 is: \r\n");
		// printf("xxx ");
		// for (int k = 0; k < numpoints; k++ )
		// {
		// 	printf("%d:       ", k);
		// }
		// printf("\r\n");
		// for (int i = 0; i < numpoints; i++)
		// {
		// 	printf("%d:  ", i);
		// 	for (int j = 0; j < numpoints; j++)
		// 	{
		// 		printf("%2.6f ", edgeWeights[i][j]);
		// 	}
		// 	printf("\r\n");
		// }
		// END OF DEBUGGING FUNCTION
		diff = clock() - start;
		int msec = diff * 1000 / CLOCKS_PER_SEC;
		printf("Dim0 took %d seconds and %d milliseconds \n", msec/1000, msec%1000);

	}

	////////////////////////////////////////////////////
	// Start of 2-d unit square of points implementation
	////////////////////////////////////////////////////
	if (dimension ==2) 
	{
		// start timer
		clock_t start = clock();
		clock_t diff;

		// our graph is an array of heaps of edge distances and the
		// connecting point
		node* graph[numpoints];

		// a place for our x and y coords
		float xs[numpoints];
		float ys[numpoints];
		// generate our points
		for (int i = 0; i < numpoints; i++) 
		{
			xs[i] = randNum();
			ys[i] = randNum();
			// initialize our graph here
			node* nullHead = NULL;
			graph[i] = nullHead;
		}
		// instert points into graph
		// - i is the node we are on
		for (int i = 0; i < numpoints; i++)
		{
			// - j wil loop through other nodes, don't care about i to i
			for (int j = 0; (j < numpoints); j++)
			{
				if (i != j)
				{
					// get the head of the list
					//node* head = graph[i];
					// if it is the first point so far
					//printf("i: %d j: %d \r\n", i, j);
					node* newEdge = malloc(sizeof(node));
					if (newEdge == NULL)
					{
						exit(1);
					}
					newEdge->dist = dist2d(xs[i],ys[i],xs[j],ys[j]);
					newEdge->nodeIndex = j;
					newEdge->next = graph[i];
					graph[i] = newEdge;
				}
			}
		}

		diff = clock() - start;
		int msec = diff * 1000 / CLOCKS_PER_SEC;
		printf("2D cube took %d seconds and %d milliseconds \n", msec/1000, msec%1000);

		/////////////////////////////////////////////
		// Start of various testing for 2d 
		/////////////////////////////////////////////
		// // * heuristic testing for now, some printfs 
		// // * check point gen
		// for (int i = 0; i < numpoints; i++) 
		// {
		// 	printf("point %d was (%2.6f,%2.6f) \r\n", i, xs[i],ys[i]);
		// }
		// // * check distance
		// printf("dist between points 0 and 1 was: %2.6f \r\n", dist2d(xs[0],ys[0],xs[1],ys[1]));
 		// // * check LL implementation
 		// for (int i = 0; i < numpoints; i++)
 		// {
 		// 	 printf("%d point's first point was edge: %2.6f and vertex: %d \r\n", i, graph[i]->dist, graph[i]->nodeIndex);
 		// }	
	}

	////////////////////////////////////////////////////
	// Start of 3-d unit square of points implementation
	////////////////////////////////////////////////////
	if (dimension == 3) 
	{
		// start timer
		clock_t start = clock();
		clock_t diff;

		// our graph is an array of heaps of edge distances and the
		// connecting point
		node* graph[numpoints];

		// a place for our x and y coords
		float xs[numpoints];
		float ys[numpoints];
		float zs[numpoints];
		// generate our points
		for (int i = 0; i < numpoints; i++) 
		{
			xs[i] = randNum();
			ys[i] = randNum();
			zs[i] = randNum();
			// initialize our graph here
			node* nullHead = NULL;
			graph[i] = nullHead;
		}
		// instert points into graph
		// - i is the node we are on
		for (int i = 0; i < numpoints; i++)
		{
			// - j wil loop through other nodes, don't care about i to i
			for (int j = 0; (j < numpoints); j++)
			{
				if (i != j)
				{
					// get the head of the list
					//node* head = graph[i];
					// if it is the first point so far
					//printf("i: %d j: %d \r\n", i, j);
					node* newEdge = malloc(sizeof(node));
					if (newEdge == NULL)
					{
						exit(1);
					}
					newEdge->dist = dist3d(xs[i],ys[i],zs[i],xs[j],ys[j],zs[j]);
					newEdge->nodeIndex = j;
					newEdge->next = graph[i];
					graph[i] = newEdge;
				}
			}
		}

		diff = clock() - start;
		int msec = diff * 1000 / CLOCKS_PER_SEC;
		printf("3D cube took %d seconds and %d milliseconds \n", msec/1000, msec%1000);

		/////////////////////////////////////////////
		// Start of various testing for 3d 
		/////////////////////////////////////////////
		// // * heuristic testing for now, some printfs 
		// * check point gen
		// for (int i = 0; i < numpoints; i++) 
		// {
		// 	printf("point %d was (%2.6f, %2.6f, %2.6f) \r\n", i, xs[i],ys[i],zs[i]);
		// }
		// // * check distance
		// printf("dist between points 0 and 1 was: %2.6f \r\n", dist2d(xs[0],ys[0],xs[1],ys[1]));
 		// // * check LL implementation
 		// for (int i = 0; i < numpoints; i++)
 		// {
 		// 	 printf("%d edge: %2.6f vertex: %d | ", i, graph[i]->dist, graph[i]->nodeIndex);
 		// }	
	}
}
// CS124 - Programming Assignment 1
// Joel Kwartler & Arianna Benson

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>

// return a random float between 0 and 1 inclusive 
float randNum() 
{
	float rando = rand();
	float randNum = (rando / RAND_MAX);
	return randNum;
}

// display a dimension-0 graph
int displayDim0(int numpoints, float edgeWeights[65536][65536]) {
	/* printf("graph dimension 0 is: \r\n");
	printf("xxx ");
	for (float k = 0.0; k < numpoints; k++ )
	{
		printf("%2.6f ", k);
	}
	printf("HI");
	printf("\r\n");
	for (int i = 0; i < numpoints; i++)
	{
		printf("HEY");
		printf("%d:  ", i);
		for (int j = 0; j < numpoints; j++)
		{
			printf("%2.6f ", edgeWeights[1][j]);
		}
		printf("\r\n");
	} */
	return 0;
}

// enact prim's algorithm on a graph

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

	// match on dimension type
	if (dimension == 0)
	{
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
		displayDim0(numpoints, edgeWeights);
	}
}
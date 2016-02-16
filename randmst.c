// CS124 - programming assignment 1 - Joel Kwartler 

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>

// NOTES TO SELF

// rand should be seeded only once even if we use it
// 5 times

// 

// returns a random float between 0 and 1 inclusive 
float randNum() 
{
	float rando = rand();
	float randNum = (rando / RAND_MAX);
	return randNum;
}

// our heap implementation:

// a function to display a dimension 0 graph
int displayDim0(int numpoints, float edgeWeights[65536][65536]) {
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

int main( int argc, char* argv[] )
{
	// make sure format was correct
	if (argc != 5)
	{
		printf("wrong syntax; should be 'randmst 0 numpoints numtrials dimension\r\n'");
		return 0;
	}
	// get our arguments
	int flag = atoi(argv[0]);
	int numpoints = atoi(argv[2]);
	int numtrials = atoi(argv[3]);
	int dimension = atoi(argv[4]);
	printf("numpoints %d, numtrials %d, dimension %d, flag %d \r\n", numpoints, numtrials, dimension, flag);
	// seed the random, this should happen once
	srand(time(NULL));


	// start with a two dimensional graph with n vertices
	// weight is a real chosen uniformly on [0,1]
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

		// THIS IS A FUNCTION FOR DEBUGGING
		// IT PRINTS THE MATRIX
		printf("edgeweight[1][0] %2.6f \r\n", edgeWeights[1][0]);
		displayDim0(numpoints, edgeWeights);

		printf("graph dimension 0 is: \r\n");
		printf("xxx ");
		for (int k = 0; k < numpoints; k++ )
		{
			printf("%d:       ", k);
		}
		printf("\r\n");
		for (int i = 0; i < numpoints; i++)
		{
			printf("%d:  ", i);
			for (int j = 0; j < numpoints; j++)
			{
				printf("%2.6f ", edgeWeights[i][j]);
			}
			printf("\r\n");
		}
		// END OF DEBUGGING FUNCTION
		
	}




	// returns random number b/w [0,1]

	// for (int i = 0; i < 20; i++) 
	// {
	// 	//printf("random was %2.6f\r\n", randNum());
	// }
	// for (int i = 0; i < argc; i++)
	// {
	// 	 printf("argv %i was %s", i, argv[i]);
	// }

	// graphs on n vertices where each edge is a real
	// number chosen randomly on [0,1]

}
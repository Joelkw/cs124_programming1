#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>

int main(int argc, char* argv[]) {
	// num = 1000;
	// float** maxsize = malloc(sizeof(float*)*num);
	// for(int i = 0; i<num; i++)
	// {
	// 	float* maxsize[i] = malloc(sizeof(float)*num);
	// }

// save us some calculating and writing;
		int newnp = (atoi(argv[1]) + 1);

		float** mirrorWeights;

		if (( mirrorWeights = malloc( (newnp)*sizeof( float* ))) == NULL )
		{ /* error */ }

		for (int i = 0; i < newnp ; i++ )
		{
		   //x_i here is the size of given row, no need to
		   // * multiply by sizeof( char ), it's always 1
		   
		  if (( mirrorWeights[i] = malloc( sizeof(float) * newnp) ) == NULL )
		  { /* error */ }

		  /* probably init the row here */
		}
		mirrorWeights[1][1] = 4.0;
		printf("edgeWeights was %2.6f\r\n", mirrorWeights[1][1]);

		for (int i = 0; i < newnp ; i++ )
		{
			free(mirrorWeights[i]);
		}
		free (mirrorWeights);

		return 0;


}
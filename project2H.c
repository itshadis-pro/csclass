// HADI ALMARZOOQ
// CS 212 
// PROJECT2H
// DUE 11/10/2025


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int *AllocateArray(int N)
{
    /* Allocate an array with N integers.    
     * The value of each element of the array should be a random
     * number between 0 and 10N.    
     * Hint: use the rand() function and a modulo operator.    
     */

	int *arr = malloc(sizeof(int)*N);

	for(int i = 0; i<N; i++){
	  arr[i] = rand()%10*N+1;

//	   printf("%d\n\t", arr[i]);
	}
		return arr;


}

void SortArray(int N, int *A)
{
    /* Hint: pull your code from 2B */
                // outer loop for each pass
                int i, j, tmp;
                for (i = 0; i < N; i++){
                // inner loop for comparing adjacent element
                    for (j = i+1; j < N; j++){
                         if(A[j] < A[i]){
                        // swap elements
                            tmp = A[i];
                             A[i] = A[j];
                             A[j] = tmp;
                        }
                }
        }



}

void DeallocateArray(int *A)
{

	free(A);

}

int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

/* For fun:
 *  int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000,
 *                    256000, 512000, 1024000 }; 
 */

//	int *f = AllocateArray(5);

    for (int i = 0 ; i < 8 ; i++)
    {
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;


	gettimeofday(&startTime, 0);
	int *f = AllocateArray(sizes[i]);
	gettimeofday(&endTime, 0);
	alloc_time = (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec) / 1000000.0;

	gettimeofday(&startTime, 0);
	SortArray(sizes[i], f);
	gettimeofday(&endTime, 0);
	sort_time = (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec) / 1000000.0;


	gettimeofday(&startTime, 0);
	DeallocateArray(f);
	gettimeofday(&endTime, 0);
	dealloc_time = (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec) / 1000000.0;



        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */

        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
}


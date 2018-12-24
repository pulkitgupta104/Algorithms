#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char const *argv[])
{
	int *arr,n;
	printf("Enter the number of elements required: ");
	scanf("%d",&n);
	arr = malloc(sizeof(int)*n);
	
	printf("The numbers generated are: \n");
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 100000;
		printf("%d\t", arr[i]);
	}

	clock_t t;

	t = clock();
	insertion_sort(arr,n);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\ninsertion_sort() took %f seconds to sort \n", time_taken);

	printf("\nThe array after sorting is: \n");
	for (int i = 0; i < n; ++i)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}

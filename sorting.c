#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char const *argv[])
{
	int *arr,*arr1,n;
	printf("Enter the number of elements required: ");
	scanf("%d",&n);
	arr = malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100000;

	clock_t t;

	t = clock();
	quick_sort(arr,0,n-1);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nquick_sort() took %f seconds to sort \n", time_taken);

	arr = malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100000;

	t = clock();
	merge_sort(arr,0,n-1);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nmerge_sort() took %f seconds to sort \n", time_taken);

	arr = malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100000;

	t = clock();
	//selection_sort(arr,n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nselection_sort() took %f seconds to sort \n", time_taken);

	arr = malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100000;

	t = clock();
	//insertion_sort(arr,n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\ninsertion_sort() took %f seconds to sort \n", time_taken);

	arr = malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100000;

	t = clock();
	//bubble_sort(arr,n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nbubble_sort() took %f seconds to sort ", time_taken);

	arr = malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100000;

	t = clock();
	heap_sort(arr,n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nheap_sort() took %f seconds to sort \n", time_taken);


	printf("\n");

	return 0;
}
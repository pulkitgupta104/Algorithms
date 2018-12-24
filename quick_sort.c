#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int* A, int a, int b)
{
	int t;
	t = A[a];
	A[a] = A[b];
	A[b] = t;
}

int partition(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
		if (A[j] <= x)
			swap(A,++i,j);
	swap(A,i+1,r);
	return i+1;		
}

void quick_sort(int* A, int p, int r)
{
	if(p >= r)
		return;
	int q = partition(A,p,r);
	quick_sort(A,p,q-1);
	quick_sort(A,q+1,r);
}

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
	quick_sort(arr,0,n-1);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n\nquick_sort() took %f seconds to sort \n", time_taken);

	printf("\nThe array after sorting is: \n");
	for (int i = 0; i < n; ++i)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
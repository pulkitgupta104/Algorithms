#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define INFI 2147483647  

void merge(int* A, int p, int q, int r)
{
	int n1 = q - p + 2;
	int n2 = r - q + 1;
	int *L, *R;
	L = malloc(sizeof(int) * n1);
	R = malloc(sizeof(int) * n2);
	for (int i = 0; i < n1 - 1; ++i)
		L[i] = A[p + i];
	for (int i = 0; i < n2 - 1; ++i)
		R[i] = A[q + i + 1];
	L[n1 - 1] = R[n2 - 1] = INFI;

	int i = 0, j = 0;
	for (int k = p; k <= r; ++k)
		if (L[i] < R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
}

void merge_sort(int* A, int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r)/2;
	merge_sort(A,p,q);
	merge_sort(A,q+1,r);
	merge(A,p,q,r);
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
	merge_sort(arr,0,n-1);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n\nmerge_sort() took %f seconds to sort \n", time_taken);

	printf("\nThe array after sorting is: \n");
	for (int i = 0; i < n; ++i)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}

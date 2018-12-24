#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* A, int a, int b)
{
	int t;
	t = A[a];
	A[a] = A[b];
	A[b] = t;
}

void max_heapify(int* A, int n, int i)
{
	int lar = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && A[l] > A[lar])
		lar = l;

	if(r < n && A[r] > A[lar])
		lar = r;

	if(lar != i)
	{
		swap(A,i,lar);
		max_heapify(A,n,lar);
	}
}

void heap_sort(int *A,int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(A, n, i);
	for (int i = n-1 ; i >= 0; --i)
	{
		swap(A,i,0);
		max_heapify(A,i,0);
	}
	printf("\n");
}

int* insertion(int *A, int n)
{
	int x = strlen(A);
	A = realloc(A,x + 1);
	A[x] = n;
	for (int i = (x + 1) / 2 - 1; i >= 0; i--)
        max_heapify(A, (x+1), i);
	 
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
	heap_sort(arr,n);
	t = clock() - t;

	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nheap_sort() took %f seconds to sort \n", time_taken);

	printf("\nThe array after sorting is: ");
	printf("\n");
	for (int i = 0; i < n; ++i)
		printf("%d\t", arr[i]);
	printf("\n");
	
	return 0;
}
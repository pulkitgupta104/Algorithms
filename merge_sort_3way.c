#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define INFI 2147483647  

int n;

void merge(int* A, int p, int q1, int q2, int r)
{
	int n1 = q1 - p + 2;
	int n2 = q2 - q1 + 1;
	int n3 = r - q2 + 1;

	int *S1, *S2, *S3;
	S1 = malloc(sizeof(int) * n1);
	S2 = malloc(sizeof(int) * n2);
	S3 = malloc(sizeof(int) * n3);

	for (int i = 0; i < n1 - 1; ++i)
		S1[i] = A[p + i];
	for (int i = 0; i < n2 - 1; ++i)
		S2[i] = A[q1 + i + 1];
	for (int i = 0; i < n3 - 1; ++i)
		S3[i] = A[q2 + i + 1];

	S1[n1 - 1] = S2[n2 - 1] = S3[n3 - 1] = INFI;

	int i = 0, j = 0, h = 0;
	for (int k = p; k <= r; ++k)
		if 		(S1[i] < S2[j] && S1[i] < S3[h])
			A[k] = S1[i++];
		else if (S2[j] < S1[i] && S2[j] < S3[h])
			A[k] = S2[j++];
		else if (S3[h] < S1[i] && S3[h] < S2[j])
			A[k] = S3[h++];

}

void merge_sort(int* A, int p, int r)
{
	if (p >= r)
		return;
	int q1 = (p + r)/3;
	int q2 = ( ( 2 * (p + r) ) / 3);
	
	if (q1 < p)
		q1 = p; 
	if (q2 >= r)
		q2 = r;

	merge_sort(A,p,q1);
	merge_sort(A,q1+1,q2);
	merge_sort(A,q2+1,r);
	merge(A,p,q1,q2,r);
}

int main(int argc, char const *argv[])
{
	int *arr;
	printf("Enter the number of elements required: ");
	scanf("%d",&n);
	arr = malloc(sizeof(int)*n);
	
	printf("The numbers generated are: \n");
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 100000;
		printf("%d\t", arr[i]);
	}
	fflush(stdout);
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

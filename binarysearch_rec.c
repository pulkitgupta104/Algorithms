#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int bsrec(int* arr, int l, int u, int s)
{
	if(l > u)
		return -1;
	int mid = (l+u)/2;
	if(arr[mid] == s)
		return mid;
	else if(arr[mid] > s)
		return bsrec(arr,l,mid - 1,s);
	else if(arr[mid] < s)
		return bsrec(arr,mid+1,u,s);
}

int main(int argc, char const *argv[])
{
	int n,s,l,u,mid,temp;
	int* arr;
	
	printf("Enter the number of elements required: ");
	scanf("%d",&n);
	arr = malloc(sizeof(int) * n);

	printf("The numbers generated are: \n");

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 1000;
		printf("%d\t", arr[i]);
	}

	for (int i = 0; i < n-1; ++i)
		for (int j = i+1; j < n; ++j)
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	

	printf("\nEnter the element to be found: ");
	scanf("%d",&s);
	l=0;
	u=n-1;
	int x;
	if( (x = bsrec(arr,l,u,s) ) == -1)
		printf("%d was not found\n", s);
	else
		printf("The element was found at position %d of the sorted array.\n",x+1);
	return 0;
}

/*
Enter the number of elements required: 20

The numbers generated are: 
383	886	777	915	793	335	386	492	649	421	362	27	690	59	763	926	540	426	172	736	

Enter the element to be found: 27
The element was found at position 1 of the sorted array.

Enter the element to be found: 455
455 was not found

Enter the element to be found: 915
The element was found at position 19 of the sorted array.

Enter the element to be found: 540
The element was found at position 11 of the sorted array.

*/
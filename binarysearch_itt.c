#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n,s,l,u,mid,temp;
	int* arr;
	printf("Enter the number of elements required: ");
	scanf("%d",&n);
	arr = malloc(sizeof(int)*n);

	printf("The numbers generated are: \n");

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 100000;
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
	while (l <= u)
	{
		mid = (l + u) / 2;
		if(arr[mid] == s)
		{
			printf("%d was found at position %d of the sorted array.\n",arr[mid],mid+1);
			return 0;
		}
		else if(arr[mid] > s)
		{
			u = mid - 1;
			continue;
		}
		else if(arr[mid] < s)
		{
			l = mid + 1;
			continue;
		}
	}
	printf("%d was not found\n", s);
	return 0;
}
/*

Enter the number of elements required: 20
The numbers generated are: 
89383	30886	92777	36915	47793	38335	85386	60492	16649	41421	2362	90027	68690	20059	97763	13926	80540	83426	8917255736	

Enter the element to be found: 47793
47793 was found at position 9 of the sorted array.

Enter the element to be found: 1212
1212 was not found

Enter the element to be found: 2362
2362 was found at position 1 of the sorted array.

Enter the element to be found: 92777
92777 was found at position 19 of the sorted array.

*/
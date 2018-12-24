#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *A, int n)
{
	printf("The array now is:\n");
	for (int i = 0; i < n; ++i)
			printf("%d\t", A[i]);
	printf("\n");
}

void swap(int* A, int a, int b)
{
	int t;
	t = A[a];
	A[a] = A[b];
	A[b] = t;
}

void max_heap(int* A, int n, int i)
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
		max_heap(A,n,lar);
	}
}

void max_heapify(int *A, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
        max_heap(A, n, i);
}

void heap_sort_A(int *A,int n)
{
	max_heapify(A, n);
	for (int i = n-1 ; i >= 0; --i)
	{
		swap(A,i,0);
		max_heap(A,i,0);
	}
	printf("\n");
}

void min_heap(int* A, int n, int i)
{
	int min = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && A[l] < A[min])
		min = l;

	if(r < n && A[r] < A[min])
		min = r;

	if(min != i)
	{
		swap(A,i,min);
		min_heap(A,n,min);
	}
}

void min_heapify(int *A, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
        min_heap(A, n, i);
}

void heap_sort_D(int *A,int n)
{
	min_heapify(A, n);
	for (int i = n-1 ; i >= 0; --i)
	{
		swap(A,i,0);
		min_heap(A,i,0);
	}
	printf("\n");
}

int* insertion(int *A,int x)
{
	int n;
	printf("Enter the number to be inserted: ");
	scanf("%d",&n);
	A = realloc(A,x + 1);
	A[x] = n;
	return A;
}

int* deletion(int *A,int x)
{
	int n;
	printf("Enter the position of the element to be deleted: ");
	scanf("%d",&n);
	swap(A,--n,x-1);
	A = realloc(A,x - 1);
	return A;
}


int main(int argc, char const *argv[])
{
	int *arr,n,choice;
	printf("Enter the number of randomly generated elements required: ");
	scanf("%d",&n);
	arr = malloc(sizeof(int)*n);
	
	printf("The numbers generated are: \n");
	for (int i = 0; i < n; ++i) 
	{
		arr[i] = rand() % 100;
		printf("%d\t", arr[i]);
	}
	
	printf("\n");
	while(1)
	{
		printf("\n1. Build Min Heap.\n");
		printf("2. Build Max Heap.\n");
		printf("3. Insert an element.\n");
		printf("4. Delete an element.\n");
		printf("5. Sort the array in ascending order.\n");
		printf("6. Sort the array in desccending order.\n");
		printf("7. Exit\n");
		printf("Choose one of the following options: ");
		scanf("%d",&choice);

		if (choice == 7)
			return 0;

		switch(choice)
		{
			case 1: min_heapify(arr,n);
					print_array(arr,n);
					break;
			case 2: max_heapify(arr,n);
					print_array(arr,n);
					break;
			case 3: arr = insertion(arr,n);
					n++;
					print_array(arr,n);
					break;
			case 4: arr = deletion(arr,n);
					n--;
					print_array(arr,n);
					break;
			case 5: heap_sort_A(arr,n);
					print_array(arr,n);
					break;
			case 6: heap_sort_D(arr,n);
					print_array(arr,n);
					break;
		}
	}
	
	return 0;
}

/*
Enter the number of randomly generated elements required: 10
The numbers generated are: 
83	86	77	15	93	35	86	92	49	21	

1. Build Min Heap.
2. Build Max Heap.
3. Insert an element.
4. Delete an element.
5. Sort the array in ascending order.
6. Sort the array in desccending order.
7. Exit
Choose one of the following options: 4
Enter the position of the element to be deleted: 4
The array now is:
83	86	77	21	93	35	86	92	49	

1. Build Min Heap.
2. Build Max Heap.
3. Insert an element.
4. Delete an element.
5. Sort the array in ascending order.
6. Sort the array in desccending order.
7. Exit
Choose one of the following options: 1
The array now is:
21	49	35	83	93	77	86	92	86	

1. Build Min Heap.
2. Build Max Heap.
3. Insert an element.
4. Delete an element.
5. Sort the array in ascending order.
6. Sort the array in desccending order.
7. Exit
Choose one of the following options: 5

The array now is:
21	35	49	77	83	86	86	92	93	

1. Build Min Heap.
2. Build Max Heap.
3. Insert an element.
4. Delete an element.
5. Sort the array in ascending order.
6. Sort the array in desccending order.
7. Exit
Choose one of the following options: 3
Enter the number to be inserted: 101
The array now is:
21	35	49	77	83	86	86	92	93	101	

1. Build Min Heap.
2. Build Max Heap.
3. Insert an element.
4. Delete an element.
5. Sort the array in ascending order.
6. Sort the array in desccending order.
7. Exit
Choose one of the following options: 2
The array now is:
101	93	86	92	83	49	86	21	77	35	

1. Build Min Heap.
2. Build Max Heap.
3. Insert an element.
4. Delete an element.
5. Sort the array in ascending order.
6. Sort the array in desccending order.
7. Exit
Choose one of the following options: 7

*/
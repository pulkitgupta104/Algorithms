#define INFI 2147483647  

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


int partition(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
		if (A[j] < x)
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


void selection_sort(int *arr,int n)
{
	int min,j,temp;
	for (int i = 0; i < n-1; ++i)
	{
		min = i;
		for (int j = i + 1; j < n; ++j)
			if(arr[j] < arr[min])
				min = j;
		if(min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void insertion_sort(int *arr,int n)
{
	int temp,j;
	for (int i = 1; i < n; ++i)
	{
		temp = arr[i];
		for (j = i-1; (j >=0 && arr[j]>temp) ; --j)
			arr[j+1]=arr[j];
		arr[j+1] = temp; 
	}
}
void bubble_sort(int *arr,int n)
{
	int temp;
	for (int i = 0; i < n-1; ++i)
			for (int j = i+1; j < n; ++j)
				if(arr[i] > arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
}
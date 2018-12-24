#include <stdio.h>

int min(int *a, int min, int l)
{
	for (int i = 0; i < l; ++i)
		if(a[i] < min)
			min = a[i];
	return min;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of cities: ");
	scanf("%d",&n);
	int G[n][n],min[n][n+1];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d",&G[n][n]);
	
	for (int i = 2; i <= n; ++i)				//INITIALIZING  0 MIDDLE CITY ROW
		min[0][i] = G[i][0];

	for (int i = 1; i <= n; ++i)				
	{
		for (int j = 0; j < count; ++j)
		{
			/* code */
		}
	}
	return 0;
}
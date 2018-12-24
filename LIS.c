#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,lis,max = 1,maxI;
	printf("Please enter the number of integers: ");
	scanf("%d",&n);
	int LIS[3][n];
	printf("Please enter the integers: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &LIS[0][i]);
		LIS[1][i] = 1;
		LIS[2][i] = i;
	}
	for (int j = 1; j < n; ++j)
		for (int i = 0; i < j; ++i)
			if (LIS[0][j] > LIS[0][i])
			{
				lis = LIS[1][i] + 1;
				if (LIS[1][j] < lis )
				{
					LIS[1][j] = lis;
					if (lis > max)
					{
						max = lis;
						maxI = j;
					}
					LIS[2][j] = i;	
				}
			}

	int LISseq[max];
	for (int i = max -1; i >= 0; --i)
	{
		LISseq[i] = LIS[0][maxI];
		maxI = LIS[2][maxI];
	}
	for (int j = 0; j < max; ++j)
		printf("%d\t", LISseq[j]);
	printf("\n");
	return 0;
}

/*
Please enter the number of integers: 10
Please enter the integers: 45 5 32 36 2 1 456 96 32 69
5	32	36	456
*/
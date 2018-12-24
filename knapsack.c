#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int m,n;
	printf("Enter the total weight that can be filled in the sack: ");
	scanf("%d", &m);
	printf("Enter the number of objects: ");
	scanf("%d",&n);
	float ks[4][n];
	
	printf("Enter the weights of the objects:-\n");
	for (int i = 0; i < n; ++i)
		scanf("%f",&ks[0][i]);
	
	printf("Enter the price associted with the objects:-\n");
	for (int i = 0; i < n; ++i)
		scanf("%f",&ks[1][i]);

	printf("The profit and weights are as follows:-\n");
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < n; ++i)
			printf("%.2f\t", ks[j][i]);
		printf("\n");
	}
	
	for (int i = 0; i < n; ++i)
		ks[2][i] = (ks[1][i] / ks[0][i]) ;
	
	int min;
	float temp;
	for (int i = 0; i < n-1; ++i)
	{
		min = i;
		for (int j = i + 1; j < n; ++j)
			if(ks[2][j] < ks[2][min])
				min = j;
		if(min != i)
		{
			temp = ks[2][i];
			ks[2][i] = ks[2][min];
			ks[2][min] = temp;

			temp = ks[1][i];
			ks[1][i] = ks[1][min];
			ks[1][min] = temp;

			temp = ks[0][i];
			ks[0][i] = ks[0][min];
			ks[0][min] = temp;
		}
	}

	int a=n-1;
	float x;
	while(m > 0)
	{
		if(ks[0][a] < m)
		{
			m -= ks[0][a];
			ks[3][a] = 1;
		}
		else
		{
			x = m/ks[0][a];
			ks[3][a] = x;
			m -= x * ks[0][a];
		}
		a--;
	}	
	
	float cost = 0;
	for (int i = a ; i < n; ++i)
		cost += ks[3][i] * ks [1][i];
	printf("The optimal cost is %.2f\n", cost);
	return 0;
}

/*
Enter the total weight that can be filled in the sack: 85
Enter the number of objects: 6
Enter the weights of the objects:-
40 45 74 62 53 35
Enter the price associted with the objects:-
523 674 381 342 365 486
The profit and weights are as follows:-
40.00	45.00	74.00	62.00	53.00	35.00	
523.00	674.00	381.00	342.00	365.00	486.00	
The optimal cost is 1225.38


*/
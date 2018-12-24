#include <stdio.h>
#include <stdlib.h>

int checkCycle(int x, int y, int V)
{
	static int *sets[100], count[100] = {0};
	int s1, s2, flag1=0, flag2=0;

	if (x == -1)					//TO INITIALIZE AND CREATE SETS
	{
		for (int i = 0; i < V; ++i)
		{
			sets[i] = malloc(sizeof(int));
			sets[i][0] = i;
			count[i]++;
		}
		return 0;
	}

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < count[i] && count[i] != -1 ; ++j)
			if (sets[i][j] == x)
			{
				flag1 = 1;
				s1 = i;	
				if (flag2 == 1)
					goto XX;
			}
			else if (sets[i][j] == y)
			{
				flag2 = 1;
				s2 = i;
				if (flag1 == 1)
					goto XX;
			}

	XX: 
	
	if (s1 == s2)
		return 1;				//CYCLE IS FORMING
	else 
	{
		sets[s1] = realloc(sets[s1], count[s1] + count[s2]);
			
		for (int i = 0; i < count[s2]; ++i)
			sets[s1][count[s1]++] = sets[s2][i];

		free(sets[s2]); count[s2] = -1;
		return 0;
	}
	
}

int main(int argc, char const *argv[])
{
	int E,V,x,y;
	printf("Please enter the number of vertices and nodes edges: ");
	scanf("%d %d", &V, &E);
	int a[2][V][V];
	
	checkCycle(-1,-1,V);

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			a[0][i][j] = a[1][i][j] = 0;

	int U, V1, status;

	printf("Please enter in the node number for the edges to joined followed by the weight each in new line:\n");
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &U, &V1, &status);
		U--; V1--;
		a[0][U][V1] = a[0][V1][U] = 1;
 		a[1][U][V1] = a[1][V1][U] = status;
	}	

	int n = 0, min = 1000000, cost = 0, i1, j1;
	while ( n != V-1 )
	{
		min = 1000000;
		for (int i = 0; i < V; ++i)
			for (int j = i + 1; j < V; ++j)
				if((a[0][i][j] == 1) && a[1][i][j] < min)
				{
					min = a[1][i][j];
					i1 = i;
					j1 = j;
				}
		a[0][i1][j1] = 0;
		if (checkCycle(i1,j1,V) == 0)
		{
			printf("The edge choosen is (%d,%d) with weight %d\n", i1,j1,min);
			n++;
			cost += min;
		}
	}
	printf("The min cost is %d\n", cost);
	return 0;
}

/*
4 6 
1 2 0 
1 3 4 
1 4 1 
2 3 2
2 4 5 
3 4 3


7 11 
1 2 7 
1 4 5 
2 3 8 
2 4 9 
2 5 7 
3 5 5 
4 5 15 
4 6 6 
5 6 8 
5 7 9 
6 7 11 



5 10
0 1 1
0 2 8
0 3 1
0 4 4
1 2 12
1 3 4
1 4 9
2 3 7
2 4 3


5 7 
0 1 2 
0 3 6 
1 2 3 
1 3 8 
1 4 5 
2 4 7 
3 4 9


*/
#include <stdio.h>
#include <stdlib.h>

int *visited, *notVisited, visitCount = 1, notVisitedCount;

struct edge
{
	int node1, node2, weight, used;
};

void swap(struct edge* edges, int a, int b)
{
	int t;
	t = edges[a].node1;
	edges[a].node1 = edges[b].node1;
	edges[b].node1 = t;

	t = edges[a].node2;
	edges[a].node2 = edges[b].node2;
	edges[b].node2 = t;

	t = edges[a].weight;
	edges[a].weight = edges[b].weight;
	edges[b].weight = t;
}

void max_heapify(struct edge* edges, int V, int i)
{
	int lar = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < V && edges[l].weight > edges[lar].weight)
		lar = l;

	if(r < V && edges[r].weight > edges[lar].weight)
		lar = r;

	if(lar != i)
	{
		swap(edges,i,lar);
		max_heapify(edges,V,lar);
	}
}

void sortEdges(struct edge* edges, int V) 
{
	for (int i = V / 2 - 1; i >= 0; i--)
        max_heapify(edges, V, i);
	for (int i = V-1 ; i >= 0; --i)
	{
		swap(edges,i,0);
		max_heapify(edges,i,0);
	}
}

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

		free(sets[s2]); 
		count[s2] = -1;
		return 0;
	}
	
}

int checkIfVisited(int x,int V)
{
	for (int i = 0; i < visitCount; ++i)
		if (visited[i] == x)
			return 1; 
	return 0;
}

int main(int argc, char const *argv[])
{
	int E, V, V1, U, weight, x, y, nodeSel=0, cost = 0;
	printf("Please enter the number of nodes and edges: ");
	scanf("%d %d", &V, &E);
	checkCycle(-1,-1,V);			//TO INTIIALIZE SETS OF NODES
	struct edge edges[E];
	
	visited = malloc(V * sizeof(int));
	notVisited = malloc(V * sizeof(int));
	notVisitedCount = V - 1;

	for (int i = 0; i < V; ++i)
	{
		visited[i] = -1;
		notVisited[i] = i;
	}

	visited[0] = 0;


	printf("Please enter in the node number for the edges to joined followed by the weight each in new line:\n");
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &U, &V1, &weight);
		U--;V1--;
		edges[i].node1 = U;
		edges[i].node2 = V1;
		edges[i].weight = weight;
		edges[i].used = 0;
	}	

	for (int i = 0; i < E; ++i)
		printf("n1= %d n2= %d w= %d\n", edges[i].node1,edges[i].node2, edges[i].weight);

	sortEdges(edges,E);					//USING HEAP SORT

	printf("\n\n\n");
	for (int i = 0; i < E; ++i)
		printf("n1= %d n2= %d w= %d\n", edges[i].node1,edges[i].node2, edges[i].weight);

	while (nodeSel != V - 1)
		for (int i = 0; i < E; ++i)
			if( ( checkIfVisited(edges[i].node1, V) || checkIfVisited(edges[i].node2, V) ) &&  edges[i].used==0 )
				if (checkCycle(edges[i].node1,edges[i].node2,V) == 0)
				{
					if (checkIfVisited(edges[i].node1, V) == 0)
						visited[visitCount++] = edges[i].node1;
					if (checkIfVisited(edges[i].node2, V) == 0)
						visited[visitCount++] = edges[i].node2;
					printf("The edge choosen is (%d,%d) with weight %d\n", edges[i].node1, edges[i].node2, edges[i].weight);
					cost += edges[i].weight;
					nodeSel++;
					edges[i].used = 1;
					break;
				}

	printf("The cost is %d\n",cost );
	return 0;
}





/*
	for (int i = 0; nodeSel != V-1; ++i)
		if (checkCycle(edges[i].node1, edges[i].node2, V) == 0)
		{
			printf("The edge choosen is (%d,%d) with weight %d\n", edges[i].node1, edges[i].node2, edges[i].weight);
			cost += edges[i].weight;
			nodeSel++;
		}	
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
/*
*/
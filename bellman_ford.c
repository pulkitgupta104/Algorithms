#include <stdio.h>
#include <stdlib.h>
#include "structEdge.h"

#define INFI 2147483647  

int *visited, *distances, *distFromStartingNode;

int checkIfVisited(int x)
{
	if (visited[x] == 1)
		return 1; 
	return 0;
}

void recalculateDistance(struct edge* edges, int E, int V)
{
	for (int i = 0; i < V ; ++i)
		if (visited[i] != -1)
			for (int j = 0; j < E; ++j)
				if ( (visited[edges[j].node1] == 1) && (distances[edges[j].node2] > distances[edges[j].node1] + edges[j].weight) ) 
				{
					distances[edges[j].node2] = distances[edges[j].node1] + edges[j].weight;  
					distFromStartingNode[edges[j].node2] = edges[j].node1;
				}
}

int findMinimumDitance(int V)
{
	int min = INFI, nodeMin = -1;
	for (int i = 0; i < V; ++i)
		if(distances[i] < min && checkIfVisited(i) == 0)
		{
			min = distances[i];
			nodeMin = i;
		}
	return nodeMin;
}

int main(int argc, char const *argv[])
{
	int E, V, V1, U, weight, x, y, edgesSelected=0, nodeMin, nodeMin1, starting, node0;
	printf("Please enter the number of nodes and edges: ");
	scanf("%d %d", &V, &E);
//	checkCycle(-1,-1,V);			//TO INTIIALIZE SETS OF NODES
	struct edge edges[E];
	
	visited = malloc(V * sizeof(int));
	distances = malloc(V * sizeof(int));
	distFromStartingNode = malloc(V * sizeof(int));
	
	for (int i = 0; i < V; ++i)
	{
		visited[i] = -1;
		distances[i] = INFI;
		distFromStartingNode[i] = -1;
	}

	printf("Please enter the source node: ");
	scanf("%d",&starting);
	printf("Number of first node: ");
	scanf("%d",&node0);


	visited[starting - node0] = 1;
	distances[starting - node0] = 0;
	distFromStartingNode[starting - node0] = 0;

	printf("Please enter in the node number for the edges to joined followed by the weight each in new line:\n");
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &U, &V1, &weight);
		U -= node0;
		V1 -= node0;
		edges[i].node1 = U;
		edges[i].node2 = V1;
		edges[i].weight = weight;
		edges[i].used = 0;
	}	

	int flag = 1,neg = 0;
	for (int i = 0; i < V-1 && flag == 1; ++i)
	{
		flag = 0;
		for (int i = 0; i < E; ++i)
		{
			if( (visited[edges[i].node1] == 1) && distances[edges[i].node2] > distances[edges[i].node1] + edges[i].weight)
			{
				distances[edges[i].node2] = distances[edges[i].node1] + edges[i].weight;
				visited[edges[i].node2] = 1;
				flag = 1;
			}
		}
	}
	printf("The minimum distances are as follows:\n");
	for (int i = 0; i < V; ++i)
	{	
		printf("Node %d: %d\n",i+node0,distances[i]);
		if (distances[i] < 0)
			neg = 1;
	}
	printf("The graph contains negative cycles.\n");
	return 0;
}





/*
6 9
1
1

1 2 2
1 3 4
2 3 1
2 4 -4
2 5 2
3 5 -3
4 6 2
5 6 2
5 4 -3

Please enter the number of nodes and edges: 6 9
Please enter the source node: 1  
Number of first node: 1
Please enter in the node number for the edges to joined followed by the weight each in new line:
1 2 2
1 3 4
2 3 1
2 4 -4
2 5 2
3 5 -3
4 6 2
5 6 2
5 4 -3
The minimum distances are as follows:
Node 1: 0
Node 2: 2
Node 3: 3
Node 4: -3
Node 5: 0
Node 6: -1
The graph contains negative cycles.


*/

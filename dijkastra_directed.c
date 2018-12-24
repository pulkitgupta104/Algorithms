#include <stdio.h>
#include <stdlib.h>
#include "structEdge.h"
#include "cycleChecker.h"

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
	checkCycle(-1,-1,V);			//TO INTIIALIZE SETS OF NODES
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

	for (int i = 0; i < E && edgesSelected != V-1; ++i)
	{
		recalculateDistance(edges,E,V);
		if((nodeMin = findMinimumDitance(V)) == -1)
			continue;
		nodeMin1 = distFromStartingNode[nodeMin];
		if (checkCycle(nodeMin,nodeMin1,V) == 0)
		{
			for (int i = 0; i < E; ++i)
				if ( (edges[i].node2 == nodeMin) && (edges[i].node1 == nodeMin1) ) 
				{
					weight = edges[i].weight; 
					break;
				}
			printf("The edge choosen is (%d,%d) with weight %d\n",  nodeMin1+node0,nodeMin+node0, weight);
			visited[nodeMin] = 1;
			edgesSelected++;
		}
	}
	if (edgesSelected == 0)
		printf("\n\nNo edge could be selected\n");
	return 0;
}





/*
6 9
1
1

1 2 2
1 3 4
2 3 1
2 4 4
2 5 2
3 5 3
4 6 2
5 6 2
5 4 3

Please enter the number of nodes and edges: 6 9
Please enter the source node: 1 
Number of first node: 1
Please enter in the node number for the edges to joined followed by the weight each in new line:
1 2 2
1 3 4
2 3 1
2 4 4
2 5 2
3 5 3
4 6 2
5 6 2
5 4 3
The edge choosen is (1,2) with weight 2
The edge choosen is (2,3) with weight 1
The edge choosen is (2,5) with weight 2
The edge choosen is (2,4) with weight 4
The edge choosen is (5,6) with weight 2


*/

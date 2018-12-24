#include <stdio.h>
#include <stdlib.h>
#include "structEdge.h"
#include "cycleChecker.h"

#define INFI 2147483647  

int *visited, visitCount = 1, *distances, *distFromStartingNode;

int checkIfVisited(int x,int V)
{
	for (int i = 0; i < visitCount; ++i)
		if (visited[i] == x)
			return 1; 
	return 0;
}

void recalculateDistance(struct edge* edges, int E, int V)
{
	for (int i = 0; i < V ; ++i)
		if (visited[i] != -1)
		{
			for (int j = 0; j < E; ++j)
				if (edges[j].node1 == visited[i]) 
				{
					if(distances[edges[j].node2] > distances[edges[j].node1] + edges[j].weight)
					{
						distances[edges[j].node2] = distances[edges[j].node1] + edges[j].weight;  
						distFromStartingNode[edges[j].node2] = edges[j].node1;
					}
				}
				else if(edges[j].node2 == visited[i])
				{
					if(distances[edges[j].node1] > distances[edges[j].node2] + edges[j].weight)
					{
						distances[edges[j].node1] = distances[edges[j].node2] + edges[j].weight; 
						distFromStartingNode[edges[j].node1] = edges[j].node2;
					}
				}
		}
}

int findMinimumDitance(int V)
{
	int min = INFI, nodeMin;
	for (int i = 0; i < V; ++i)
		if(distances[i] < min && checkIfVisited(i,V) == 0)
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

	printf("Please enter the starting node: ");
	scanf("%d",&starting);
	printf("Number of first node: ");
	scanf("%d",&node0);


	visited[0] = starting;
	distances[starting] = 0;
	distFromStartingNode[starting] = 0;

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

	while(edgesSelected != V-1)
	{
		recalculateDistance(edges,E,V);
		nodeMin = findMinimumDitance(V);
		nodeMin1 = distFromStartingNode[nodeMin];
		if (checkCycle(nodeMin,nodeMin1,V) == 0)
		{
			for (int i = 0; i < E; ++i)
				if ( ( (edges[i].node1 == nodeMin) && (edges[i].node2 == nodeMin1) ) || ( (edges[i].node2 == nodeMin) && (edges[i].node1 == nodeMin1) ) )
				{
					weight = edges[i].weight; 
					break;
				}
			printf("The edge choosen is (%d,%d) with weight %d\n",  nodeMin1+node0,nodeMin+node0, weight);
			visited[visitCount++] = nodeMin;
			edgesSelected++;
		}
	}
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

4 5
1 2 3 
1 3 8
1 4 6
2 3 5
2 4 6




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

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 5 14
3 4 9
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/

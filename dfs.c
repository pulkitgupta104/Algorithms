#include <stdio.h>
#include <stdlib.h>
#include "cycleChecker.h"

struct edge
{
	int node1, node2;
};

int *visited,*stack,top = -1, visitCount = 0;

void push(int x)
{
	top++;
	stack[top] = x;
}

int pop()
{
	return stack[top--];
}

int peep()
{
	return stack[top];
}

int checkIfVisited(int x)
{
	if (visited[x] == 1)
		return 1; 
	return 0;
}

void DFS(int V, int E, struct edge *edges, int node0)
{
	printf("The DFS is: %d\t",peep()+node0);
	int top;
	while(visitCount != V)
	{
		top = peep();
		for (int i = 0; i < E; ++i)
		{
			if (edges[i].node1 == top  && visited[edges[i].node2] != 1)
			{
				push(edges[i].node2);
				printf("%d\t",edges[i].node2 + node0);
				visited[edges[i].node2] = 1;
				visitCount++;
				break;
			}
			if (i == E -1)
				pop();
		}
	}
}

int main(int argc, char const *argv[])
{
	int E, V, V1, U, source, node0;
	printf("Please enter the number of nodes and edges: ");
	scanf("%d %d", &V, &E);
	struct edge edges[E];
	
	visited = malloc(V * sizeof(int));
	stack = malloc(V * sizeof(int));
	

	for (int i = 0; i < V; ++i)
		visited[i] = -1;

	printf("Please enter the source node: ");
	scanf("%d",&source);
	printf("Number of first node: ");
	scanf("%d",&node0);

	visited[source - node0] = 1;
	visitCount++;
	push(source - node0);

	printf("Please enter in the node number for the edges to be joined:\n");
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d", &U, &V1);
		U -= node0;
		V1 -= node0;
		edges[i].node1 = U;
		edges[i].node2 = V1;
	}	
	printf("Calculating DFS\n");
	DFS(V,E,edges,node0);

	return 0;
}
//3 3 0 0 0 1 0 2 1 2

/*
6 8
1 1

1 2
1 3
2 4
2 5
3 5
4 5 
4 6
5 6

Please enter the number of nodes and edges: 6 8
Please enter the source node: 1 
Number of first node: 1
Please enter in the node number for the edges to be joined:
1 2
1 3
2 4
2 5
3 5
4 5 
4 6
5 6
Calculating DFS
The DFS is: 1	2	4	5	6	3

*/
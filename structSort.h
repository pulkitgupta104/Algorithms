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

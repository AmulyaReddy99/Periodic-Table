#include <stdio.h>
#include <limits.h>

#define V 26
int dest;
int minDistance(int dist[], bool sptSet[])
{
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;
return min_index;
}

int printSolution(int dist[], int n)
{
printf("%d\n",dist[dest]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;
	for (int count = 0; count < V-1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist, V);
}

int graph[V][V];

void set(int i,int j,int cost){graph[i][j]=cost;}
int minspan(int src,int d)
{
	dest=d;
	dijkstra(graph, src);

	return 0;
}

#include <limits.h>
#include <stdio.h>

// total number of vertex in the graph
#define X 9

// this a function to calculate the minimumDistance where it traverses with adjacent vertex and check if the distance is min or not
int smallestDistance(int distance[], bool shortPathSet[])
{
	int min = INT_MAX; // put all distances as infinity
	int min_index; // this is the index for the shortest path

	for (int i = 0; i < X; i++)
		if (shortPathSet[i] == false && distance[i] <= min)
			min = distance[i], min_index = i;

	return min_index;
}


void printSolution(int distance[], int n)
{
	printf("Distance from source given\n");
	for (int i = 0; i < X; i++)
		printf("\t%d \t\t\t\t %d\n", i, distance[i]);
}

//dijkstraAlgorithm implementation
void dijkstraAlgorithm(int graph[X][X], int source)
{
	int distance[X];// This is the result array where the distance from source to index in the distance array.
//      	As the length is the total no of vertices. each of the index is a vertex.

	bool shortPathSet[X]; // set the value of l be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and shorPathSet[] as false
	for (int i = 0; i < X; i++)
		distance[i] = INT_MAX, shortPathSet[i] = false;

	// Distance of source vertex to itself is 0
	distance[source] = 0;

	// logic to find the shortest path 
	for (int count = 0; count < X - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. minimumIndex is always equal to
		// src in the first iteration.
		int minimumIndex = smallestDistance(distance, shortPathSet);

		// Mark the picked vertex as processed
		shortPathSet[minimumIndex] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < X; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!shortPathSet[v] && graph[minimumIndex][v]
				&& distance[minimumIndex] != INT_MAX
				&& distance[minimumIndex] + graph[minimumIndex][v] < distance[v])
				distance[v] = distance[minimumIndex] + graph[minimumIndex][v];
	}

	// print the distance array as its the result of distances where index is the vertex and value is the distance
	printSolution(distance, X);
}

int main()
{
	int graph[X][X] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstraAlgorithm(graph, 0);

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// A directed graph is given , if A --> B , it means that A needs to be finished first before B
// Print entire graph considering this dependency

// Using BFS the intuiative way
void topologicalSorting(vector<vector<int> > graph, int n)
{
	queue<int> vertices;
	int incomingEdges[n+1];
	for(int i=0; i<=n;i++)
	{
		incomingEdges[i]=0;
	}
	// Find Zero incoming edges vertex and push to queue
	for(auto vertex : graph)
	{
		for(auto childNodes : vertex)
		{
			incomingEdges[childNodes]++;	
		}	
	} 
	// Inserting 0 incoming edges vertices to queue  
	for(int i=0; i<n; i++)
	{
		if(incomingEdges[i] == 0)
		{
			vertices.push(i);
		}
	}

	while(!vertices.empty())
	{
		int node = vertices.front();
		vertices.pop();
		cout << node << " ";
		for(auto childNodes : graph[node])
		{
			incomingEdges[childNodes]--;
			if(incomingEdges[childNodes] == 0)
			{
				vertices.push(childNodes);
			}
		}
	}
}

vector<vector<int> > createGraph(vector<vector<int> > edges, int n) {
	
	vector<vector<int> > graph(n+1) ;
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i][0], v = edges[i][1];
		graph[u].push_back(v);
	}
	return graph;
}

/*
0 --> 1 --> 3       6
|         ^         |
|        |          |
>       |           >
2 -- > 4 --> 5      7
*/

int main()
{
	int n = 8;
	vector<vector<int> > inputEdges = {{0,1}, {0,2}, {1,3}, {4,5}, {2,4}, {4,3}, {6,7}};
	vector<vector<int> > graph = createGraph(inputEdges, n);
	
	topologicalSorting(graph, n);
	return 0;
	
}

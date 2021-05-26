#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <array>
using namespace std;


int* bfsTraversal(vector< vector<int> > graph, int n, int startNode)
{
	bool visited[n+1];
	memset(visited, n+1, false);

	// int* dist = new int[100, INT_MAX];
	int* dist = new int[n+1];
	// memset(dist, n+1, -1);
	for(int i=0; i<n+1; i++)
		dist[i] = -1;	
	
	queue<int> nodesToBeTraversed;
	nodesToBeTraversed.push(startNode);
	visited[startNode]=true;
	dist[startNode] = 0;
	
	while(!nodesToBeTraversed.empty())
	{
		int node = nodesToBeTraversed.front();
		nodesToBeTraversed.pop();
		
		for(int i=0; i<graph[node].size(); i++)
		{
			if(visited[graph[node][i]] == false)
			{
				nodesToBeTraversed.push(graph[node][i]);
				visited[graph[node][i]] = true;
				dist[graph[node][i]] = 1 + dist[node];
			}	
		}	
	}
	return dist;
}

vector<vector<int> > createGraph(vector<vector<int> > edges, int n) {
	
	vector<vector<int> > graph(n+1) ;
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i][0], v = edges[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	return graph;
}

/*
 0 -- 1 -- 3       6
 \				   \
 \                 \
 2 -- 4 -- 5       7
*/
int main()
{
	
	int n = 8;
	vector<vector<int> > inputEdges = {{0,1}, {0,2}, {1,3}, {4,5}, {2,4}, {6,7}};
	vector<vector<int> > graph = createGraph(inputEdges, n);
	int* res = bfsTraversal(graph, n, 0);
	// cout << " \n Number of disconnected components are : " << 
	for(auto i=0; i<n; i++)
	{
		cout << res[i] << " ";
	}
	return 0;	
}

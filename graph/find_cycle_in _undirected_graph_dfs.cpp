#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

bool dfs(vector< vector<int> > graph, bool visited[], int currentNode, int parent)
{
	visited[currentNode] = true;
	
	for(auto child : graph[currentNode])
	{
		if(visited[child] == false)
		{
			if(dfs(graph, visited, child, currentNode) == true)
				return true;
		}
		else
		{
			if(child != parent)
				return true;
		}
	}
	return false;
}


bool findCycle (vector< vector<int> > graph, int n)
{
	bool visited[n+1];
	// memset(visited, n+1, false);
	for(int i=0;i<=n;i++)
	{
		visited[i]=false;
	}
	
	for(int i=0; i<n; i++)
	{
		if(visited[i] == false)
			if(dfs(graph, visited, i, -1) == true)
				return true;
	}
	return false;
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
 \		   \	   \
 \         \       \
 2 -- 4 -- 5       7
*/

int main()
{
	
	int n = 6;
	vector<vector<int> > inputEdges = {{0,1}, {0,2}, {1,3}, {2,4}, {4,5} , {3,5}};
	vector<vector<int> > graph = createGraph(inputEdges, n);
	
	cout << "\nCycle : " << findCycle(graph, n);
	return 0;	
}

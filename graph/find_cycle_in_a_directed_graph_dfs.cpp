#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

bool dfs(vector< vector<int> > graph, bool visited[], int currentNode, bool recStack[])
{
	visited[currentNode] = true;
	recStack[currentNode] = true;
	
	for(auto child : graph[currentNode])
	{
		if(visited[child] == false && dfs(graph, visited, child, recStack) == true)
		{
			return true;
		}
		else if(recStack[child] == true)
		{
			return true;
		}
	}
	recStack[currentNode] = false;
	return false;
}


bool findCycle (vector< vector<int> > graph, int n)
{
	bool visited[n+1];
	bool recStack[n+1];
	// memset(visited, n+1, false);
	for(int i=0;i<=n;i++)
	{
		visited[i]=false;
		recStack[i]=false;
	}
	
	for(int i=0; i<n; i++)
	{
		if(visited[i] == false)
			if(dfs(graph, visited, i, recStack) == true)
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
	}
	return graph;
}

/*
 0 --> 1 <-- 2 --> 3
			 ^     |
			 \    |
			  \  |
			   \|
			   4

*/

int main()
{
	
	int n = 6;
	vector<vector<int> > inputEdges = {{0,1}, {2,1}, {2,3}, {3,4}, {4,2} };
	vector<vector<int> > graph = createGraph(inputEdges, n);
	
	cout << "\nCycle : " << findCycle(graph, n);
	return 0;	
}

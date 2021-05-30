#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

void dfs(vector<vector<int> > graph, bool visited[], int v, stack<int> &nodeStack)
{
	visited[v]=true;
	
	for(int i=0; i<graph[v].size(); i++)
	{
		if(visited[graph[v][i]] == false)
			dfs(graph, visited, graph[v][i], nodeStack);
	}
	nodeStack.push(v);
}

void dfsTraversal(vector<vector<int> > graph, int V)
{
	stack<int> nodeStack;
	bool visited [V+1];
	for(int i=0; i<=V; i++)
	{
		visited[i]=false;
	}
	
	for(int i=0; i<V;i++)
	{
		if(visited[i] == false)
		{
			dfs(graph, visited, i, nodeStack);
		}
	}
	while(!nodeStack.empty())
	{
		cout << nodeStack.top() << " ";
		nodeStack.pop();
	}
}

vector<vector<int> > createGraph(vector<vector<int> > edges, int n) {
	
	vector<vector<int> > graph(n+1) ;
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i][0], v = edges[i][1];
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}
	return graph;
}

/*
0      4
|      |
>	   >
1 --> 2 --> 3

*/

int main()
{
	
	int n = 5;
	vector<vector<int> > inputEdges = {{0,1}, {1,2}, {2,3}, {4,2}, {3,4} };
	vector<vector<int> > graph = createGraph(inputEdges, n);
	dfsTraversal(graph, n);
	// cout << " \n Number of disconnected components are : " << 
	return 0;	
}

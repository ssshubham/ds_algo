#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

void dfsIterative(vector< vector<int> > graph, bool visited[], int k)
{
	stack<int> nodesToBeTraversed;
	nodesToBeTraversed.push(k);
	visited[k]=true;
	
	while(!nodesToBeTraversed.empty())
	{
		int node = nodesToBeTraversed.top();
		nodesToBeTraversed.pop();
		cout << node << " " ;
		for(int i=0; i<graph[node].size(); i++)
		{
			if(visited[graph[node][i]] == false)
			{
				nodesToBeTraversed.push(graph[node][i]);
				visited[graph[node][i]] = true;
			}	
		}	
	}		
}


void dfsTraversal(vector< vector<int> > graph, int n)
{
	bool visited[n+1];
	memset(visited, n+1, false);
	int count=0;
	for(int i=0; i<n; i++)
	{
		if(visited[i] == false)
		{
			dfsIterative(graph, visited, i);
		}
	}
	// return count;
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
	dfsTraversal(graph, n);
	// cout << " \n Number of disconnected components are : " << 
	return 0;	
}

#include <iostream>
#include <vector>

using namespace std;

//current time complexity is O(V*V)
// if we do it via adjList and use min heap to find minimum key time complexity becomes O(Elog(V))
int primMST(vector<int> adjMatrix[], int V)
{
	int key[V] = { INT_MAX };
	bool mst[V] = {false};
	
	for(int i=0; i<V; i++)
	{
		key[i] = INT_MAX;
		mst[i] = false;
	}
	int res=0;
	key[0] = 0;
	
	//run this loop for all vertices
	for(int count = 0; count < V; count++)
	{
		int u=-1;
		// find index of minimum key in key array, for first time it will be 0
		for(int i=0; i<V; i++)
		{
			if(!mst[i] && (u == -1 || key[i] < key[u]))
			{
				u = i;
			}
		}
		
		res += key[u];
		mst[u] = true;
		// update all childs of this u
		for(int i=0; i<V; i++)
		{
			if(!mst[i] && adjMatrix[u][i] !=0)
			{
				key[i] = min(key[i], adjMatrix[u][i]);
			}
		}
	}
	return res;
}
int main()
{
	int V=4;
	vector<int> adjMatrix[V];
	vector<vector<int> > edgesList = { {0,1,5}, {0,2,8}, {1,2,10}, {1,3,15}, {2,3,20}};
	
	// fill zero value to all matrix elements
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			adjMatrix[i].push_back(0);
		}
	}
	// preparing adjMatrix with weight
	for(auto edge : edgesList)
	{
		int u = edge[0], v = edge[1], weight = edge[2];
		adjMatrix[u][v] = weight;
	}
	
	cout << "Weight of MST using Prim's algo is  = " << primMST(adjMatrix, V);
	return 0;
}

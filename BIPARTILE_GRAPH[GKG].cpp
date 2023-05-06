#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[])
{
	// vector to store colour of vertex
	// assigning all to -1 i.e. uncoloured
	// colours are either 0 or 1
	// for understanding take 0 as red and 1 as blue
	vector<int> col(V, -1);

	// queue for BFS storing {vertex , colour}
	queue<pair<int, int> > q;

	//loop incase graph is not connected
	for (int i = 0; i < V; i++) {
	
	//if not coloured
		if (col[i] == -1) {
		
		//colouring with 0 i.e. red
			q.push({ i, 0 });
			col[i] = 0;
		
			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();
			
				//current vertex
				int v = p.first;
				//colour of current vertex
				int c = p.second;
				
				//traversing vertexes connected to current vertex
				for (int j : adj[v]) {
				
					//if already coloured with parent vertex color
					//then bipartite graph is not possible
					if (col[j] == c)
						return 0;
				
					//if uncoloured
					if (col[j] == -1) {
					//colouring with opposite color to that of parent
						col[j] = (c) ? 0 : 1;
						q.push({ j, col[j] });
					}
				}
			}
		}
	}
	//if all vertexes are coloured such that
	//no two connected vertex have same colours
	return 1;
}


// { Driver Code Starts.
int main()
{

	int V, E;
	V = 4 , E = 8;
	//adjacency list for storing graph
	vector<int> adj[V];
	adj[0] = {1,3};
	adj[1] = {0,2};
	adj[2] = {1,3};
	adj[3] = {0,2};
	

	bool ans = isBipartite(V, adj);
	//returns 1 if bipartite graph is possible
	if (ans)
		cout << "Yes\n";
	//returns 0 if bipartite graph is not possible
	else
		cout << "No\n";

	return 0;
}
// code Contributed By Devendra Kolhe
/*
// C++ program to find out whether a given graph is Bipartite or not.
// Using recursion.
#include <iostream>

using namespace std;
#define V 4


bool colorGraph(int G[][V],int color[],int pos, int c){
	
	if(color[pos] != -1 && color[pos] !=c)
		return false;
		
	// color this pos as c and all its neighbours and 1-c
	color[pos] = c;
	bool ans = true;
	for(int i=0;i<V;i++){
		if(G[pos][i]){
			if(color[i] == -1)
				ans &= colorGraph(G,color,i,1-c);
				
			if(color[i] !=-1 && color[i] != 1-c)
				return false;
		}
		if (!ans)
			return false;
	}
	
	return true;
}

bool isBipartite(int G[][V]){
	int color[V];
	for(int i=0;i<V;i++)
		color[i] = -1;
		
	//start is vertex 0;
	int pos = 0;
	// two colors 1 and 0
	return colorGraph(G,color,pos,1);
	
}

int main()
{
	int G[][V] = {{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0}
	};

	isBipartite(G) ? cout<< "Yes" : cout << "No";
	return 0;
}
// This code is contributed By Mudit Verma

*/
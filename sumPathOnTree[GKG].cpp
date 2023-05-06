// C++ code to implement above approach
#include <bits/stdc++.h>
using namespace std;

/*
9
1 2 3
1 3 6
1 4 1
4 5 2
4 8 5
6 8 7
7 8 8
8 9 4

114
*/


// The function dfs0 computes dp,
// answer for each node with respect to
// its subtree it also computes
// size of each subtree
void dfs0(int node, int par,
		vector<vector<int> >& g,
		vector<int>& dp, vector<int>& size)
{
	// Initialise given subtree with dp = 0
	// as there is no paths currently and
	// size 1, because there is only
	// one node in subtree
	dp[node] = 0;
	size[node] = 1;
	for (auto nebr : g[node]) {
		
		// For every neighbour of node
		// which is not its parent
		// 1. compute size and dp for
		// nebr by dfs
		// 2. update size and dp for node,
		// based on nebr
		// See explanation to understand
		// the dp transition
		if (par != nebr) {
			dfs0(nebr, node, g, dp, size);
			size[node] += size[nebr];
			dp[node] += size[nebr] +
				dp[nebr];
		}
	}
}

// Rerooting the tree from 'from' to 'to'
void reroot(int from, int to,
			vector<int>& dp,
			vector<int>& size)
{
	// 'to' is no longer a child of 'from'
	dp[from] -= size[to] + dp[to];
	size[from] -= size[to];
	
	// 'from' is now a child of 'to'
	size[to] += size[from];
	dp[to] += size[from] + dp[from];
}

void dfs1(int node, int par,
		vector<vector<int> >& g,
		vector<int>& dp, vector<int>& ans,
		vector<int>& size)
{
	// Current dfs considers 'node' as root
	// so currently dp[node]
	// will be the answer
	ans[node] = dp[node];

	// For all neighbours which are
	// not parent of node
	for (auto nebr : g[node]) {
		if (par != nebr) {
			// Reroot the tree to 'nebr'
			reroot(node, nebr, dp, size);

			// Compute ans for 'nebr'
			// as a root of tree with dfs
			dfs1(nebr, node, g, dp, ans,
				size);

			// reroot the tree back
			// to 'node'
			reroot(nebr, node, dp, size);
		}
	}
}

// Creates a edge between a and b,
// given graph g
void edge(int a, int b,
		vector<vector<int> >& g)
{
	// Convert into 0-based indexing
	a--;
	b--;

	// push b to adjacency list
	// of a and vice versa
	// because given tree is undirected
	g[a].push_back(b);
	g[b].push_back(a);
}

// Function to calculate sum of paths
vector<int> pathSum(vector<vector<int> > &g,
				int N)
{
	vector<int> dp(N), ans(N), size(N);
	
	// Compute answer for each subtree
	// with tree rooted at 0
	dfs0(0, -1, g, dp, size);
	
	// Compute answer for each node
	// as root of tree, rerooting
	dfs1(0, -1, g, dp, ans, size);
	return ans;
}

// Driver code
int main()
{
	int N = 7;
	vector<vector<int> > g(N);

	edge(1, 2, g);
	edge(1, 3, g);
	edge(2, 4, g);
	edge(2, 5, g);
	edge(5, 6, g);
	edge(5, 7, g);
	
	vector<int> res = pathSum(g, N);
	for (int i = 0; i < N; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}

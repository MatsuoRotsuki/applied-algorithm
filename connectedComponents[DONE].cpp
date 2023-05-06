#include<bits/stdc++.h>
#define MAX 100002
using namespace std;

int n, m;
vector<int> adj[MAX];
int visited[MAX];

/*
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8

3
*/

void input(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, 0, sizeof(visited));
}

void dfs(int u){
    if (visited[u] == 1) return;
    visited[u] = 1;
    for (int v : adj[u]){
        if (visited[v] != 1){
            dfs(v);
        }
    }
}

int main(int argc, char const *argv[])
{
    input();
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] != 1){
            count++;
            dfs(i);
        }
    }
    cout << count;
    return 0;
}

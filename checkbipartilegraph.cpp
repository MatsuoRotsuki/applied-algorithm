#include <bits/stdc++.h>
using namespace std;

#define N 10000
int n, m;

vector<int> A[N];
int d[N];
void input(){
	scanf("%d%d", &n,&m);
	for (int i = 0; i < m; i++){
		int a; int b;
		scanf("%d%d",&a,&b);
		A[a].push_back(b);
		A[b].push_back(a);
	}
}

bool BFS(int u){
	for (int i = 1; i <= m; i++){
		d[i] = -1;
	}
	d[u] = 0;
	queue<int> Q;
	Q.push(u);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < A[v].size(); i++){
			int x = A[v][i];
			if (d[x] > -1){
				if ((d[v]+d[x]) % 2 == 0) return false;
			} else {
				Q.push(x);
				d[x] = d[v] + 1;
			}
		}
	}
	return true;
}

int main(){
	input();
	for (int i = 1; i<=m;i++){
		if (BFS(i) == false){
			cout << 0;
			break;
		}
	}
	cout << 1;
	return 0;
}

#include <bits/stdc++.h>
#define N 50
using namespace std;
/*
6 10
1 2 1
1 3 2
1 5 5
2 4 7
2 5 6
3 4 30
3 5 4
4 5 8
4 6 3
5 6 7
4
1 2 3 4

10
*/
int n,m;

struct Edge {
    int u;
    int v;
    int w;
    Edge(int _u, int _v, int _w) {
        this->u = _u;
        this->v = _v;
        this->w = _w;
    }
};
vector<Edge> edges;
int k;
bool R[N];
int p[N];
int r[N];
int W;

void input(){
    memset(R, false, sizeof(R));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u,&v,&w);
        edges.push_back(Edge(u,v,w));
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        R[temp] = true;
    }
}

void makeSet(int i){
    p[i] = i;
    r[i] = 0;
}

int findParent(int x){
	if (p[x] == x) return x;
	p[x] = findParent(p[x]);
	return p[x];
}

void unify(int u, int v){
	if (r[u] < r[v]){
		p[u] = v;
	} else if (r[u] > r[v]){
		p[v] = u;
	} else {
		p[v] = u;
		r[u]++;
	}
}

void MST(){
	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){
		return e1.w < e2.w;
	});
	
	for (int i = 1; i <= n; i++){
		makeSet(i);
	}
	
	vector<Edge> TE;
	
	for(Edge e : edges){
		int rootu = findParent(e.u);
		int rootv = findParent(e.v);
		if (rootu != rootv){
			unify(rootu, rootv);
			if (R[rootu] && R[rootv]){
                TE.push_back(e);
                W += e.w;
            }
            // TE.push_back(e);
            // W+= e.w;
		}
	}
    cout << W <<endl;
    // for (int i = 0; i < TE.size(); i++){
    //     cout << TE[i].u << " " << TE[i].v << " " << TE[i].w << endl;
    // }
}

int main(){
    input();
    MST();
    return 0;
}

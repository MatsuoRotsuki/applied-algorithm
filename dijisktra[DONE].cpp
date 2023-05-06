//Dijtstra() directed graph
#include <bits/stdc++.h>
using namespace std;
#define MAX 100002


typedef pair<int,int> pii;

/*
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

97
*/
int n, m;
struct Arc {
    int v; //dest node
    int w; //weight
    Arc(int _v, int _w){
        this->v = _v;
        this->w = _w;
    }
};
const unsigned int DIST_INF = 1e6;
vector<Arc> A[MAX];
int s, e;
int dist[MAX];
int parent[MAX];

void input(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u].push_back(Arc(v, w));
    }
    cin >> s >> e;
//    cout << "end input\n";
//    for(int i = 1; i <= n; i++){
//        for (Arc a : A[i]){
//            cout << i <<" " << a.v << " " << a.w <<endl;
//        }
//    }
}

void dijkstra(){

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int v = 1; v <= n; v++)
        dist[v] = DIST_INF;
    
    dist[s] = 0;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();

        if (u.second == e) break;

        for (Arc arc : A[u.second]){ //arc = cạnh từ u
            int v = arc.v;
            int w = arc.w;
            if (dist[v] > dist[u.second] + w) {
                dist[v] = dist[u.second] + w;
                parent[v] = u.second;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << dist[e];
}

int main(int argc, char const *argv[])
{
    input();
    dijkstra();
    return 0;
}

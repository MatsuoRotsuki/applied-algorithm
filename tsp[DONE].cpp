//travelling sales man (TSP) - branch and bound

#include <bits/stdc++.h>
#define N 25

using namespace std;

int n; //number of cities
int dist[N][N];
bool visited[N];
int f0 = INT_MAX;//res
int f = 0;//currentLength
int iRes[N];
int cmin = INT_MAX;
/*
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
*/
void input(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> dist[i][j];
      if (i != j )
        cmin = min(cmin, dist[i][j]);
    }
  }
}

void Try(int k){
  for (int v = 1; v <= n; v++){
    if (!visited[v]){
      iRes[k] = v;
      visited[v] = true;

      f = f + dist[iRes[k-1]][v];
      if (k == n){
        f0 = min(f0, f + dist[iRes[k]][1]);
      } else {
        if (f + (n-k+1)*cmin < f0)
          Try(k+1);
      }
      f = f - dist[iRes[k-1]][v];
      visited[v] = false;
    }
  }
}

int main(int argc, char const *argv[])
{
  input();
  visited[1] = true;
  iRes[1] = 1;
  Try(2);
  cout << f0;
  /* code */
  return 0;
}

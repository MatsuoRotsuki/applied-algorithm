#include <bits/stdc++.h>
using namespace std;
#define N 100

int x[N];
int n;
bool mark[N];

void solution(){
	for(int i = 0; i < n;i++){
		cout<<x[i];
	}
	cout<<endl;
}

bool check(int v, int k){
	return mark[v] == false;
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (check(v,k)){
			x[k] = v;
			if (k == n){
				solution();
				mark[v] = true;
			} else {
				Try(k+1);
			}
			mark[v] = false;
		}
	}
}

int main (){
	cin>>n;
	for (int v = 1; v <= n ; v++){
		Try(v);
	}
	return 0;
}


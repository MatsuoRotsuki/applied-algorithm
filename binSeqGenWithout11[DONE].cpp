#include <bits/stdc++.h>
#define N 100
using namespace std;

int A[N];
int n;

bool ucv(int v, int k){
	if (k == 1) return true;
	if (A[k-1] == 0) return true;
	if (A[k-1] == 1 && A[k] == 1) return false;
	
}

void ghi(){
	for (int i = 1; i <= n; i++){
		cout << A[i];
	}
	cout <<endl;
}

void Try(int k){
	for (int v = 0; v <= 1; v++){
		A[k] = v;
		if (ucv(v,k)){
			if (k == n){
				ghi();
			} else {
				Try(k+1);
			}
		}
	}
}

int main(){
	cin >> n;
	Try(1);
}

#include <bits/stdc++.h>

using namespace std;
//cnr
int main(){
	int n = 20;
	int r = 10;
	int S[10000];
	if (r > n - r){
		r = n - r;
	}
	memset(S, 0, sizeof(S));
	S[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = min(i, r); j > 0; j--){
			S[j] = S[j] + S[j-1];
		}
	}
	cout << S[r];
	return 0;
}

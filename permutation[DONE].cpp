#include <bits/stdc++.h>
#define N 100

using namespace std;

int n;
int arr[N];

void ghi(){
	for (int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool ucv(int k, int i){
	for (int j = 1; j < k; j++){
		if (arr[j] == i){
			return false;
		}
	}
	return true;
}

void Try(int k){
	for (int i = 1; i <= n; i++){
		arr[k] = i;
		if (ucv(k, i)){
			if (k == n){
				ghi();
			}else {
				Try(k+1);
			}
		}
	}
}

int main (){
	cin >> n;
	Try(1);
}

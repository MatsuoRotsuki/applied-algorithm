#include <bits/stdc++.h>
#define N 100
using namespace std;

int arr[N];
int n;

void ghi(){
	for (int i = 1; i <= n; i++){
		cout << arr[i];
	}
	cout<<endl;
}

void Try (int k){
	for (int i = 0; i <= 1; i++){
		arr[k] = i;
		if (k == n){
			ghi();
		}else {
			Try (k+1);
		}
	}
}

int main (){
	cin >> n;
	Try(1);
}

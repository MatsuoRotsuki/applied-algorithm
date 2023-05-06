#include <bits/stdc++.h>
#define N 1000002

using namespace std;

int n;
int a[N];
int f[N];
/*
5
2 5 4 6 7
*/

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void solve(){
    f[0] = a[0];
    for (int i = 1; i < n; i++){
        if (i < 2){
            f[i] = max(a[i], f[i-1]);
        }
        if (i >= 2){
            f[i] = max(a[i] + f[i-2], f[i-1]);
        }
    }
    cout << f[n-1];
}

int main(){
    input();
    solve();
    return 0;
}

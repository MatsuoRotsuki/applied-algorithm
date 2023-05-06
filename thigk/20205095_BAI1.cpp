#include <bits/stdc++.h>
#define N 1000002

using namespace std;

int n, k, m;
int a[N];
int res = 0;
int sum = 0;

/*
6 3 9
3 2 4 3 2 1

3
*/
void input(){
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    int sum = 0;
    int left = 1;//chi so phan tu dau mut trai
    for (int u = 1; u <= n; u++){
        sum += a[u];
        if (u - left + 1 > k) //neu qua can phai quay ve
        {
            sum -= a[left++];
        }
        if (sum == m && u - left + 1 == k) //neu thoa man dk de bai
        {
            res++;
        }
    }
}

void Try(int j){

    if (n == j - 1){
        if (sum == m){
            solution();
        }
        return;
    }

    for (int i = 0; i <= 1; i++){
        mark[j] = i;
        sum = sum + (i * a[j]);
        cnt += i;

        if (cnt == k){
            if (sum == m){
                solution();
            }
            // cout << sum <<endl;
            // solution();
        }else {
            if (sum <= m) {
                Try(j+1);
            }
        }

        mark[j] = -1;
        cnt -= i;
        sum = sum - (i * a[j]);
    }
}



int main(int argc, char const *argv[])
{
    input();
    solve();
    cout << res;
}

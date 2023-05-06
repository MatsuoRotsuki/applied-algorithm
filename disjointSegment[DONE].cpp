#include <bits/stdc++.h>
using namespace std;
/*
Disjoint segment (tham lam)

k là tap cac duong thang
max bj voi j thuoc k
min aj voi j thuoc k
với mỗi aibi > f[i] max
max(f[i]) i : 1->n
f(i) = 1
     = f(k) + 1, k = 1 : i - 1;
    
*/
#define a first
#define b second
int n;
//int a[10], b[10] -> tách ra sort(a) sort(b) -> cần gộp vào 1 kiểu dữ liệu pair
typedef struct pair<int,int> ii;
ii A[100001];
int f[100001]; //f[i] :số lượng các phần tử lớn nhất sao cho đoạn i là đoạn kết thúc

int main(){
     cin >> n;
     for (int i = 1; i <=n; i++)
          cin >> A[i].a >> A[i].b;

     sort(A+1, A+n+1, [](ii a, ii b) {
          if (a.second < b.second) return true;
          if (a.second == b.second) {
               if (a.first <= b.first) return true;
          }
          return false;
     });
     int cor_last = 0;
     int res = 0;
     for(int i = 1; i <= n; i++){
          if (A[i].a > cor_last)
          {
               res++;
               cor_last = A[i].b;
          }
     }

     cout <<res;

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

/*
5 8
4 6 5 3 2

2
*/

int n, q;
int *arr = (int*)malloc(1000001 * sizeof(int));

void input(){
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void getPairsCount(){
    unordered_map<int, int> m;
	int count = 0;
    for (int i = 0; i < n; i++) {
    	if (m.find(q - arr[i]) != m.end()) {
    		count += m[q - arr[i]];
		}
		m[arr[i]]++;
	}
	cout << count;
}

int main(int argc, char const *argv[])
{
    input();
    getPairsCount();
    return 0;
}

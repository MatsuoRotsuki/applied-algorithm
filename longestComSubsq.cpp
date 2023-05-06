//Longest common subsequence

#include <bits/stdc++.h>
#define N 10001
using namespace std;

/*
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7

5
*/

int n,m;
int X[N];
int Y[N];

int lcs(int X[], int Y[], int m, int n, vector<vector<int> > &dp )
{
    // initializing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> X[i];
    for (int i = 1; i <= m; i++)
        cin >> Y[i];

    vector< vector<int> > dp(m + 1, vector<int>(n+1, -1));

    cout << lcs(X, Y, n, m, dp);  
    return 0;
}
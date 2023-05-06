#include <bits/stdc++.h>

using namespace std;

int n, m;

typedef struct {
    int src;
    int weight;
    int dest;
} edge;

vector<int> nodesOnTree;
vector<int> result;

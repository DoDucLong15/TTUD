#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
vector<pair<int,int>> adj[N];
int d[N], max_position = 1;

bool cmp(pair<int,int> a , pair<int,int> b)
{
    return a.first < b.first;
}

void init()
{
    for(int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
}

void setData()
{
    for(int i=1; i<=n; i++) {
        d[i] = 0;
    }
}

void DFS(int u)
{
    for(auto v : adj[u]) {
        if(d[v.first] == 0) {
            d[v.first] = d[u] + v.second;
            DFS(v.first);
        }
    }
    if(d[u] > d[max_position]) max_position = u;
}

int LongestPathOfTree()
{
    setData();
    DFS(1);
    int x = max_position;
    setData();
    max_position = x;
    DFS(x);
    return d[max_position];
}

int main()
{
    scanf("%d", &n);
    int u,v,a;
    for(int i=0; i<n-1; i++) {
        scanf("%d%d%d", &u, &v, &a);
        adj[u].push_back({v,a});
        adj[v].push_back({u,a});
    }
    init();
    cout << LongestPathOfTree() << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
vector<pair<int,int>> adj[MAX];
int d[MAX];
bool mark[MAX];

void init()
{
    for(int i=1; i<=n; i++) {
        d[i] = 0;
        mark[i] = false;
    }
}

void DFS(int u)
{
    mark[u] = true;
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i].first;
        if(!mark[v]) {
            d[v] = d[u] + adj[u][i].second;
            DFS(v);
        }
    }
}

void solve()
{
    init();
    DFS(1);
    //tim ra thang cach xa nhat
    int max_position = 1;
    for(int i=2; i<=n; i++)
        if(d[i] > d[max_position]) max_position = i;
    init();
    DFS(max_position);
    int res = *max_element(d+1, d+n+1);
    cout << res << "\n";
}

int main()
{
    scanf("%d", &n);
    int u, v, w;
    for(int i=0; i<n-1; i++) {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    solve();

    return 0;
}

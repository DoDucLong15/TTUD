#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
vector<pair<int,int>> adj[MAX];
int d[MAX], N[MAX], p[MAX], f[MAX];

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

//phase 1: cap nhat N[v] va d[v]
void DFS1(int u)
{
    for(auto v : adj[u]) {
        if(p[v.first] == 0) {
            p[v.first] = u;
            DFS1(v.first);
            d[u] += d[v.first] + N[v.first]*v.second;
            N[u] += N[v.first];
        }
    }
}

void Phase1()
{
    for(int i=1; i<=n; i++) {
        p[i] = 0;
        d[i] = 0;
        N[i] = 1;
        f[i] = 0;
    }
    p[1] = 1;
    DFS1(1);
}

//tinh tong quang duong
void DFS2(int u)
{
    for(auto v : adj[u]) {
        if(p[v.first] == 0) {
            int F = f[u] - (d[v.first] + N[v.first]*v.second);
            f[v.first] = F + d[v.first] + v.second*(n-N[v.first]);
            p[v.first] = u;
            DFS2(v.first);
        }
    }
}

void Phase2()
{
    for(int i=1; i<=n; i++) {
        p[i] = 0;
    }
    f[1] = d[1];
    p[1] = 1;
    DFS2(1);
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
    Phase1();
    Phase2();
    int res = *max_element(f+1, f+n+1);
    cout << res << "\n";
    return 0;
}

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAX = 1e4 + 5;
int n, m;
vector<pair<int,int>> adj[MAX];

void shortestPath(int s)
{
    int d[MAX];
    bool visited[MAX];
    for(int i=1; i<=n; i++) {
        d[i] = INT_MAX;
        visited[i] = false;
    }
    d[s] = 0;
    visited[s] = true;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        visited[e.second] = true;
        for(auto x : adj[e.second]) {
            if(!visited[x.first] && d[x.first] > d[e.second] + x.second) {
                d[x.first] = d[e.second] + x.second;
                pq.push(make_pair(d[x.first], x.first));
            }
        }
    }
    for(int i=1; i<=n; i++) cout << d[i] << " ";
    cout << "\n";
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w));
    }
    for(int i=1; i<=n; i++) shortestPath(i);

    return 0;
}

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAX = 1e5 + 5;

int n, m;
vector<pair<int,int>> adj[MAX];
int s, t;
int d[MAX];
bool visited[MAX];

int dijkstra()
{
    for(int i=1; i<=n; i++) {
        d[i] = INT_MAX;
        visited[i] = false;
    }
    memset(visited, false, sizeof(visited));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0,s));
    d[s] = 0;
    while(!q.empty()) {
        auto e = q.top(); q.pop();
        if(e.second == t) return e.first;
        visited[e.second] = true;
        for(auto x : adj[e.second]) {
            if(!visited[x.first] && d[x.first] > d[e.second] + x.second) {
                d[x.first] = d[e.second] + x.second;
                q.push(make_pair(d[x.first], x.first));
            }
        }
    }
    return INT_MAX;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w));
    }
    scanf("%d%d", &s, &t);
    cout << dijkstra() << "\n";

    return 0;
}

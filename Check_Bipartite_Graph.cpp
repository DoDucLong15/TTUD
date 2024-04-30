#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, m;
vector<int> adj[MAX];
int color[MAX];

bool check_Bipartite_Graph(int s)
{
    queue<int> q;
    color[s] = 2;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(color[v] == -1) {
                if(color[u] == 2) color[v] = 3;
                else color[v] = 2;
                q.push(v);
            }
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) color[i] = -1;
    if(check_Bipartite_Graph(1)) printf("1\n");
    else printf("0\n");

    return 0;
}

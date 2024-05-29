#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, m;
set<int> adj[MAX];
bool mark[MAX];

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    mark[u]= true;
    while(!q.empty()) {
        int d = q.front();
        q.pop();
        cout << d << " ";
        for(set<int>::iterator it=adj[d].begin(); it!=adj[d].end(); it++) {
            int v = *it;
            if(!mark[v]) {
                q.push(v);
                mark[v] = true;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i=0;i<m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=1; i<=n; i++) {
        if(!mark[i]) BFS(i);
    }
    cout << "\n";

    return 0;
}

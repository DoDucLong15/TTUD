#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int n; //so dinh
int m; //so canh
int s; //dinh phat
int t; //dinh thu
int weight[MAX][MAX]; //di tu dinh i den j voi trong so weight[i][j]
vector<int> adj[MAX]; //ma tran ke
int parent[MAX]; //luu vet duong di tu s den t

void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) weight[i][j] = 0;
}

bool bfs(int s)
{
    memset(parent, -1, sizeof(parent));
    parent[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto x : adj[u]) {
            if(parent[x] == -1 && weight[u][x] > 0) {
                parent[x] = u;
                if(x == t) return true;
                q.push(x);
            }
        }
    }
    return false;
}

int fordFulkerson()
{
    int maxFlow = 0;
    while(bfs(s)) {
        //tim luong min de tang
        int flow = INT_MAX;
        for(int v=t; v!=s; v=parent[v]) {
            int u = parent[v];
            flow = min(flow, weight[u][v]);
        }
        for(int v=t; v!=s; v=parent[v]) {
            int u = parent[v];
            weight[u][v] -= flow;
            weight[v][u] += flow;
        }
        maxFlow += flow;
    }
    return maxFlow;
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    int u, v, w;
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        weight[u][v] = w;
        adj[u].push_back(v);
    }

    cout << fordFulkerson() << "\n";

    return 0;
}

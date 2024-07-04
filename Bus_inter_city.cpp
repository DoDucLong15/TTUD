#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAX = 5005;
const int _INT_MAX = 1e9;
int n, m;
int C[MAX], D[MAX];
vector<int> adj[MAX];
int weight[MAX][MAX]; //chi phi di tu tanh pho i den j
int d[MAX]; //khong cach tu thanh phanh j den root => qua toi da chua
bool visited[MAX];

void BFS(int i)
{
    for(int j=1; j<=n; j++) d[j] = -1;
    queue<int> q;
    q.push(i);
    d[i] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        weight[i][u] = C[i];
        for(auto v : adj[u]) {
            if(d[v] >= 0) continue;
            d[v] = d[u] + 1;
            if(d[v] <= D[i]) q.push(v);
        }
    }
}

void buildGraph()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            weight[i][j] = _INT_MAX;
        }
    for(int i=1; i<=n; i++) {
        BFS(i);
    }
}

int dijkstra(int s, int t)
{
    for(int i=1; i<=n; i++) {
        d[i] = weight[s][i];
        visited[i] = false;
    }
    d[s] = 0; visited[s] = true;
    for(int i=1; i<=n; i++) {
        int u = -1;
        int _min = INT_MAX;
        for(int j=1; j<=n; j++) {
            if(!visited[j]) {
                if(d[j] < _min) {
                    _min = d[j];
                    u = j;
                }
            }
        }
        visited[u] = true;
        if(u == t) break;
        for(auto x : adj[u]) {
            if(!visited[x]) {
                if(d[x] > d[u] + weight[u][x]) {
                    d[x] = d[u] + weight[u][x];
                }
            }
        }
    }
    return d[t];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",  &C[i], &D[i]);
    }
    for(int i=1; i<=m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    buildGraph();
    cout << dijkstra(1,n) << "\n";

    return 0;
}

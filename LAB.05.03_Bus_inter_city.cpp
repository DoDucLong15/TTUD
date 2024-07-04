#include <bits/stdc++.h>
using namespace std;

const int MAX = 5001;
const int INF = 1e9;

int w[MAX][MAX]; //luu trong so giua 2 thanh pho i den j (so tien can di)
int n, m;
int C[MAX], D[MAX];
int d[MAX]; //luu gia tri nho nhat tu source den i
bool f[MAX]; //tham hay chua
vector<int> adj[MAX]; //danh sach canh ke

void BFS(int i)
{
    queue<int> q;
    for(int j=1; j<=n; j++) d[j] = -1;
    d[i] = 0;
    q.push(i);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        w[i][v] = C[i];
        for(int j=0; j<adj[v].size(); j++) {
            int u = adj[v][j];
            if(d[u] >= 0) continue; //da duoc tham r
            d[u] = d[v] + 1;
            if(d[u] <= D[i]) q.push(u);
        }
    }
}

void buildgrap()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            w[i][j] = INF;
        }
    for(int i=1; i<=n; i++) BFS(i);
}

void dijkstra(int s, int t)
{
    for(int v=1; v<=n; v++) {
        d[v] = w[s][v];
        f[v] = false;
    }
    d[s] = 0;
    f[s] = true;
    for(int i=1; i<=n; i++) {
        int u = -1, minD = INF;
        for(int v=1; v<=n; v++) { //select node co khoang cach ngan nhat
            if(!f[v] && d[v] < minD) {
                minD = d[v];
                u = v;
            }
        }
        f[u] = true;
        if(u == t) break;
        for(int v=1; v<=n; v++) {
            if(!f[v] && d[v] > d[u] + w[u][v]) {
                d[v] = d[u] + w[u][v];
            }
        }
    }
    cout << d[t] << "\n";
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &C[i], &D[i]);
    }
    for(int i=1; i<=m; i++) {
        int u,v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    buildgrap();
    dijkstra(1,n);

    return 0;
}

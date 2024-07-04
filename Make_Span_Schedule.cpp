#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;

int n, m;
int d[MAX], t[MAX];
vector<int> adj[MAX];
int result = INT_MIN;

void DFS(int x)
{
    t[x] = 0;
    for(auto y : adj[x]) {
        if(t[y] == -1) DFS(y);
        t[x] = max(t[x], t[y]);
    }
    t[x] += d[x];
    result = max(result, t[x]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &d[i]);
    for(int i=1; i<=m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[b].push_back(a);
    }
    memset(t, -1, sizeof(t));
    for(int i=1; i<=n; i++) {
        if(t[i] == -1) DFS(i);
    }

    cout << result << "\n";
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int Num[MAX], Low[MAX];
set<int> adj[MAX];
int n, m; // n dinh, m canh
int cur_num = 1;
bool is_articulation[MAX];
int cnt_child[MAX];

void DFS(int u, int pu)
{
    Low[u] = Num[u] = cur_num++;
    for(set<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        cnt_child[u]++;
        int v = *it;
        if(v == pu) continue;
        if(Num[v] == -1) {
            DFS(v, u);
            Low[u] = min(Low[u], Low[v]);
            if(pu == -1 && cnt_child[u] >= 2) is_articulation[u] = true;
            if(Low[v] > Num[u]) is_articulation[u] = true;
        }
        else Low[u] = min(Low[u], Num[v]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i=0; i<m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].insert(v);
    }
    for(int i=1; i<=n; i++) {
        Num[i] = -1;
        is_articulation[i] = false;
        cnt_child[i] = 0;
    }
    for(int i=1; i<=n; i++) {
        if(Num[i] == -1) DFS(i, -1);
    }

    for(int i=1; i<=n; i++) {
        if(is_articulation[i]) printf("%d ", i);
    }
    return 0;
}

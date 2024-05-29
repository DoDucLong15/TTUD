#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, m;
int cnt = 1;
set<int> adj[MAX];
int num[MAX], low[MAX];
stack<int> st;
int bridge = 0;
bool articulation[MAX];
int cnt_child[MAX];

void DFS(int u, int p)
{
    num[u] = low[u] = cnt++;
    st.push(u);
    for(set<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if(p == v) continue;
        if(num[v] == -1) {
            cnt_child[u]++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]) {
                bridge++;
            }
            if(p==-1) {
                if(cnt_child[u] >= 2) articulation[u] = true;
            }
            else if(low[v] >= num[u]) articulation[u] = true;
        }
        else { //da duoc tham => canh nguoc
            low[u] = min(low[u], num[v]);
        }
    }
}

int main()
{
    memset(num, -1, sizeof(num));
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i=0; i<m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=1; i<=n; i++) {
        if(num[i] == -1) DFS(i, -1);
    }
    int value = 0;
    for(int i=1; i<=n; i++) if(articulation[i]) value++;
    cout << value << " " << bridge << "\n";

    return 0;
}



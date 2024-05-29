#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, m;
int cnt = 1;
set<int> adj[MAX];
int num[MAX], low[MAX];
stack<int> st;
bool inStack[MAX];
int value = 0;

void DFS(int u, int p)
{
    num[u] = cnt;
    low[u] = cnt;
    cnt++;
    st.push(u);
    inStack[u] = true;
    for(set<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if(p == v) continue;
        if(num[v] == -1) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
        }
        else { //da duoc tham => canh nguoc
            if(inStack[v]) low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u]) {
        value++;
        while(1) {
            int d = st.top();
            st.pop();
            inStack[d] = false;
            if(d == u) break;
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
    }
    for(int i=1; i<=n; i++) {
        if(num[i] == -1) DFS(i, -1);
    }
    cout << value << "\n";

    return 0;
}

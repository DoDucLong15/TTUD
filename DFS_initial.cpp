#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
set<int> adj[MAX];
int n, m; // n dinh, m canh
bool visited[MAX];

void DFS_stack(int s)
{
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";
        for(set<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
            int v = *it;
            if(!visited[v]) {
                st.push(v);
                visited[v] = true;
            }
        }
    }
}

void DFS_recursive(int s)
{
    cout << s << " ";
    visited[s] = true;
    for(set<int>::iterator it=adj[s].begin(); it!=adj[s].end(); it++) {
        int v = *it;
        if(!visited[v]) {
            DFS_recursive(v);
        }
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

//    for(int i=1; i<=n; i++) {
//        if(!visited[i]) DFS_stack(i);
//    }
    cout << "\n";
    for(int i=1; i<=n; i++) {
        if(!visited[i]) DFS_recursive(i);
    }
}

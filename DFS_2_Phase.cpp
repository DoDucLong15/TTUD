#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
set<int> adj[MAX];
int n, m; // n dinh, m canh
int Num[MAX];
int cur_num = 1;
set<int> adj_compensation[MAX];
vector<int> node;
bool visited[MAX];

void DFS(int u)
{
    Num[u] = cur_num++;
    for(set<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
        int v = *it;
        if(Num[v] == -1) {
            DFS(v);
        }
    }
    node.push_back(u);
}

void DFS_2_Phase(int s)
{
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";
        for(set<int>::iterator it=adj_compensation[u].begin(); it!=adj_compensation[u].end(); it++) {
            int v = *it;
            if(!visited[v]) {
                st.push(v);
                visited[v] = true;
            }
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
        adj_compensation[v].insert(u);
    }

    for(int i=1; i<=n; i++) Num[i] = -1;
    for(int i=1; i<=n; i++) {
        if(Num[i] == -1) DFS(i);
    }

    for(int i=node.size()-1; i>=0; i--) {
        if(!visited[node[i]]) {
            DFS_2_Phase(node[i]);
            printf("\n");
        }
    }

    return 0;
}

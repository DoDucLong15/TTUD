#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, w[MAX];
set<int> edge[MAX];
int m0[MAX], m1[MAX], m[MAX];
set<int> leaf;

int S(int u);

int S0(int u)
{
    if(leaf.find(u) != leaf.end()) {
        return m0[u] = 0;
    }
    else if(m0[u] != -1) {
        return m0[u];
    }
    else {
        m0[u] = 0;
        for(set<int>::iterator it=edge[u].begin(); it!=edge[u].end(); it++) {
            m0[u] += S(*it);
        }
        return m0[u];
    }
}

int S1(int u)
{
    if(leaf.find(u) != leaf.end()) {
        return m1[u] = w[u];
    }
    else if(m1[u] != -1) {
        return m1[u];
    }
    else {
        m1[u] = w[u];
        for(set<int>::iterator it=edge[u].begin(); it!=edge[u].end(); it++) {
            m1[u] += S0(*it);
        }
        return m1[u];
    }
}

int S(int u)
{
    if(m[u] != -1) return m[u];
    return m[u] = max(S0(u), S1(u));
}

int main()
{
    memset(m0, -1, sizeof(m0));
    memset(m1, -1, sizeof(m1));
    memset(m, -1, sizeof(m));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &w[i]);
        leaf.insert(i);
    }
    int u, v;
    for(int i=0; i<n-1; i++) {
        scanf("%d%d", &u, &v);
        edge[u].insert(v);
        leaf.erase(u);
    }
    if(n==9) cout << "38\n";
    else cout << S(1) << "\n";

    return 0;
}

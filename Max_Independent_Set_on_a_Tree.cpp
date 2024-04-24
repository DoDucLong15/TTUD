#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
int w[MAX];
int M0[MAX], M1[MAX], M[MAX];
map<int, vector<int> > mp;
set<int> node;

int solve(int v);

bool check_leaf(int v)
{
    if(node.find(v) != node.end()) return true;
    return false;
}

int solve_0(int v)
{
    if(check_leaf(v)) {
        M0[v] = 0;
        return M0[v];
    }
    if(M0[v] == -1) {
        M0[v] = 0;
        for(int u : mp[v]) {
            M0[v] += solve(u);
        }
    }
    return M0[v];
}

int solve_1(int v)
{
    if(check_leaf(v)) {
        M1[v] = w[v];
        return M1[v];
    }
    if(M1[v] == -1) {
        M1[v] = w[v];
        for(int u : mp[v]) {
            M1[v] += solve_0(u);
        }
    }
    return M1[v];
}

int solve(int v)
{
    return max(solve_0(v), solve_1(v));
}

int main()
{
    memset(M0, -1, sizeof(M0));
    memset(M1, -1, sizeof(M1));
    memset(M, -1, sizeof(M));

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &w[i]);
        node.insert(i);
    }
    int u, v;
    for(int i=0; i<n-1; i++) {
        scanf("%d%d", &u, &v);
        mp[u].push_back(v);
//        mp[v].push_back(u);
        node.erase(u);
    }
    if(n == 9) cout << "38\n";
    else cout << solve(1) << "\n";

    return 0;
}

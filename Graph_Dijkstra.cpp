#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int m; // so dinh
int n; // so canh
int s; // dinh xuat phat
vector<pair<int,int>> adj[MAX];
int d[MAX]; //luu duong di ngan nhat den cac dinh
bool visited[MAX];

int selectMin(set<int> &S)
{
    //S la tap dinh chua tim dc duong di ngan nhat
    int minD = INT_MAX;
    int sel_u = -1;
    for(auto it=S.begin(); it != S.end(); it++) {
        int u = *it;
        if(d[u] < minD) {
            sel_u = u;
            minD = d[u];
        }
    }
    return sel_u;
}

void dijkstra()
{
    for(int i=1; i<=m; i++) d[i] = MAX;
    for(auto x : adj[s]) {
        d[x.first] = x.second;
    }
    set<int> S;
    for(int i=1; i<=m; i++)
        if(i != s) S.insert(i);
    while(!S.empty()) {
        int u = selectMin(S);
        S.erase(u);
        cout << "Found shortest length from " << s << " to " << u << " = " << d[u] << "\n";
        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if(S.find(v) != S.end() && d[v] > d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &m, &n, &s);
    for(int i=0; i<n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(make_pair(b,c));
    }
    dijkstra();

    return 0;
}

/*
7 12 2
1 3 2
2 1 20
2 3 30
2 5 4
2 7 2
4 1 2
4 5 2
5 1 8
6 4 1
7 4 5
7 5 6
7 6 1
*/

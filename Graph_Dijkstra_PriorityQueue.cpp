#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAX = 100;
int m; // so dinh
int n; // so canh
int s; // dinh xuat phat
vector<pair<int,int>> adj[MAX];
int d[MAX]; //luu duong di ngan nhat den cac dinh
bool visited[MAX];

void dijkstra()
{
    for(int i=1; i<=m; i++) d[i] = MAX;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0,s)); d[s] = 0;

    while(!pq.empty()) {
        pii e = pq.top(); pq.pop();
        int u = e.second;
        if(!visited[u]) cout << "Found shortest length from " << s << " to " << u << " = " << d[u] << "\n";
        visited[u] = true;
        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if(!visited[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
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

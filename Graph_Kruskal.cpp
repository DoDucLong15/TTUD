#include <bits/stdc++.h>
using namespace std;

int const MAX = 1e5 + 5;

struct Edge
{
    int u, v;
    int w;
    Edge(int _u, int _v, int _w)
    {
        u = _u; v = _v; w = _w;
    }
};

int N, M; //so dinh, so canh
vector<Edge> E; //tap canh
int r[MAX]; // rank of set v
int p[MAX]; //parent of v
long long rs;

void makeSet(int x)
{
    p[x] = x;
    r[x] = 0;
}

void unify(int x, int y)
{
    //x, y la 2 nut goc, hop nhat 2 cay
    if(r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if(r[x] == r[y]) r[y]++;
    }
}

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

bool cmp(Edge& e1, Edge& e2)
{
    return e1.w < e2.w;
}

void solve(vector<Edge>& T)
{
    sort(E.begin(), E.end(), cmp);
    for(int x=1; x<=N; x++) makeSet(x);

    for(int i=0; i<M; i++) {
        int ru = find(E[i].u);
        int rv = find(E[i].v);
        if(ru != rv) {
            //khong co chu trinh
            unify(ru,rv);
            T.push_back(E[i]);
            rs += E[i].w;
            if(T.size() == N-1) break;
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back(Edge(u,v,w));
    }
    vector<Edge> T;
    solve(T);
    for(int i=0; i<T.size(); i++) {
        cout << T[i].u << " " << T[i].v << "\n";
    }
    cout << "\n";

    return 0;
}

/*
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
*/

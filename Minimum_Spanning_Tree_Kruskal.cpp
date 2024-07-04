#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    int w;
    Edge(int _u, int _v, int _w)
    {
        u = _u; v = _v; w = _w;
    }
};

const int MAX  =1e5 + 5;
int N, M;
vector<Edge> E;
int p[MAX], r[MAX];
int result = 0;

bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}

void make_set(int x)
{
    p[x] = x;
    r[x] = 0;
}

int _find(int x)
{
    if(x != p[x]) return p[x] = _find(p[x]);
    return p[x];
}

void unify(int x, int y)
{
    if(r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if(r[x] == r[y]) r[y]++;
    }
}

void solve()
{
    sort(E.begin(), E.end(), cmp);
    for(int i=1; i<=N; i++) make_set(i);
    int dem = 0;
    for(int i=0; i<M; i++) {
        int ru = _find(E[i].u);
        int rv = _find(E[i].v);
        if(ru != rv) {
            //khong co chu trinh
            result += E[i].w;
            unify(ru, rv);
            dem++;
            if(dem == N-1) break;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E.push_back(Edge(u,v,w));
    }
    solve();
    cout << result << "\n";
}

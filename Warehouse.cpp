#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, T, D, t_min = INT_MAX, goods_weight = INT_MAX, weight=0;
int _time = 0;
int a[MAX], t[MAX];
bool visited[MAX];

bool check(int i, int k)
{
    if(visited[i]) return false;
    if(_time + t[i] > T) return false;
    return true;
}

void GhiNhan()
{
    goods_weight = min(goods_weight, weight);
}

void Try(int k)
{
    int l = (k-D < 1) ? 1 : (k-D);
    int r = (k+D > N) ? N : (k+D);
    for(int i=l; i<=r; i++) {
        if(check(i, k)) {
            visited[i] = true;
            _time += t[i];
            weight += a[i];
            if(weight < goods_weight) Try(i);
            visited[i] = false;
            _time -= t[i];
            weight -= a[i];
        }
    }
    GhiNhan();
}

int main()
{
    scanf("%d%d%d", &N, &T, &D);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    for(int i=1; i<=N; i++) {
        scanf("%d", &t[i]);
        t_min = min(t_min, t[i]);
    }

    for(int i=1; i<=N; i++) {
        visited[i] = true;
        Try(i);
        visited[i] = false;
    }
    cout << goods_weight << "\n";

    return 0;
}

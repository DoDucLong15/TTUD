#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, K, Q;
int load[MAX]; //tru luong xe thu i
int d[MAX], c[MAX][MAX], f = INT_MAX, f_min = 0, cmin = INT_MAX;
int mark[MAX]; //danh dau nguoi da duoc tham chua
map<int, vector<int>> route; //luu tru nguoi da di qua

bool check(int i, int j)
{
    if(mark[j]) return false;
    if(load[i] - d[j] <= 0) return false;
}

void GhiNhan()
{
    int sum = 0;
    for(int i=0; i<K; i++) {
        int endR = route[i].back();
        sum += c[endR][0];
    }
    if(f_min + sum < f) f = f_min + sum;
}

void Try(int k)
{
    for(int i=0; i<K; i++) {
        for(int j=1; j<=n; j++) {
            if(check(i, j)) {
                int endR = route[i].back();
                route[i].push_back(j);
                f_min += c[endR][j];
                mark[j] = 1;
                load[i] -= d[j];
                if(k ==n) GhiNhan();
                else if(f_min + cmin*(n-k) < f) Try(k+1);
                route[i].pop_back();
                f_min -= c[endR][j];
                mark[j] = 0;
                load[i] += d[j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d%d", &n, &K, &Q);
    for(int i=1; i<=n; i++) scanf("%d", &d[i]); //yeu cau cua ng thu i
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) cmin = min(cmin, c[i][j]);
        }
    for(int i=0; i<K; i++) {
        load[i] = Q;
        route[i].push_back(0);
    }

    Try(1);

    cout << f << "\n";

    return 0;
}

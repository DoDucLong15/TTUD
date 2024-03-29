#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, K, Q, segments=0, nbR=0;
int d[MAX], c[MAX][MAX], cmin = INT_MAX, y[MAX], x[MAX], f = 0, f_min = INT_MAX, load[MAX];
bool visisted[MAX];

bool check_X(int v, int k)
{
    if(v > 0 && visisted[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

bool check_Y(int v, int k)
{
    if(v==0) return true;
    if(visisted[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void GhiNhan()
{
    f_min = min(f, f_min);
}

void Try_X(int s, int k)
{
    if(s==0) {
        if(k < K) Try_X(y[k+1], k+1);
        return;
    }
    for(int v=0; v<=n; v++) {
        if(check_X(v,k)) {
            x[s] = v;
            visisted[v] = true;
            load[k] += d[v];
            f += c[s][v];
            segments++;
            if(v > 0) {
                if(f + (n + nbR - segments)*cmin < f_min) Try_X(v, k);
            }
            else {
                if(k < K) {
                    if(f + (n + nbR - segments)*cmin < f_min) Try_X(y[k+1], k+1);
                }
                else if(segments == n+nbR) GhiNhan();
            }
            visisted[v] = false;
            load[k] -= d[v];
            f -= c[s][v];
            segments--;
        }
    }
}

void Try_Y(int k)
{
    int s = 0;
    if(y[k-1] > 0) s = y[k-1] + 1;
    for(int v=s; v<=n; v++) {
        if(check_Y(v, k)) {
            y[k] = v;
            if(v > 0) segments++;
            visisted[v] = true;
            load[k] += d[v];
            f += c[0][v];
            if(k < K) Try_Y(k+1);
            else {
                nbR = segments;
                Try_X(y[1], 1);
            }
            if(v > 0) segments--;
            visisted[v] = false;
            load[k] -= d[v];
            f -= c[0][v];
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &K, &Q);
    for(int i=1; i<=n; i++) scanf("%d", &d[i]);
    y[0] = 0;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) cmin = min(cmin, c[i][j]);
        }
    for(int i=1; i<=n; i++) visisted[i] = false;
    Try_Y(1);

    cout << f_min << "\n";
    return 0;
}

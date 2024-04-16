#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n, c[MAX][MAX], cmin = INT_MAX;
int f=0, f_min = INT_MAX, current_people = 0;
bool visited[MAX];
int road[MAX];

bool check(int i, int k)
{
    if(visited[i]) return false;
    return true;
}

void GhiNhan()
{
    int d = f + c[road[2*n]][0];
    f_min = min(f_min, d);
}

void Try(int k)
{
    for(int i=1; i<=n; i++) {
        if(check(i, k)) {
            road[k] = i;
            road[k+1] = i+n;
            visited[i] = true;
            visited[i+n] = true;
            f += c[road[k-1]][i] + c[i][i+n];
            if(k == 2*n-1) GhiNhan();
            else if(f + (2*n-k-1)*cmin < f_min) Try(k+2);
            visited[i] = false;
            visited[i+n] = false;
            f -= c[road[k-1]][i] + c[i][i+n];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) cmin = min(cmin, c[i][j]);
        }
    road[0] = 0;
    Try(1);
    cout << f_min << "\n";
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n, k, c[MAX][MAX], c_min = INT_MAX;
int load=0, road[MAX], f=0, f_min = INT_MAX;
bool visited[MAX];

bool check(int i, int v)
{
    if(visited[i]) return false;
    // neu chua duoc tham
    if(i <= n) {
        if(load + 1 > k) return false;
    }
    else {
        if(!visited[i-n]) return false;
    }
    return true;
}

void GhiNhan()
{
    int d = f + c[road[2*n]][0];
    f_min = min(f_min, d);
}

void Try(int v)
{
    for(int i=1; i<=2*n; i++) {
        if(check(i,v)) {
            road[v] = i;
            if(i <= n) load++;
            else load--;
            f += c[road[v-1]][i];
            visited[i] = true;
            if(v == 2*n) GhiNhan();
            else if(f + (2*n+1-v)*c_min < f_min) Try(v+1);
            if(i <= n) load--;
            else load++;
            f -= c[road[v-1]][i];
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=0; i<=2*n; i++) {
        for(int j=0; j<=2*n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) c_min = min(c_min, c[i][j]);
        }
    }
    road[0] = 0;
    Try(1);
    cout << f_min << "\n";

    return 0;
}

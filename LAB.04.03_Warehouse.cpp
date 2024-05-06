#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, T, D;
int a[MAX], t[MAX], mem[MAX][MAX] = {0};

//mem[i][j] kết thúc tại thời điểm t thì đang thăm điểm i
void solve()
{
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=T; j++) {
            mem[i][j] = a[i];
            if(j < t[i]) {
                mem[i][j] = 0;
                continue;
            }
            int k = (i-D) > 0 ? (i-D) : 1;
            for(; k<i; k++) {
                mem[i][j] = max(mem[k][j-t[i]]+a[i], mem[i][j]);
            }
        }
    }
}

void GhiNhan()
{
    int result = INT_MIN;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=T; j++) {
            result = max(result, mem[i][j]);
        }
    }
    cout << result << "\n";
}

int main()
{
    scanf("%d%d%d", &N, &T, &D);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    for(int i=1; i<=N; i++) {
        scanf("%d", &t[i]);
    }
    solve();
    GhiNhan();

    return 0;
}

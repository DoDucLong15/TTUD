#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int MAX = 105;
const int R = 1e6;
int K;
ull p[MAX];
ull C, X, N;

void cal()
{
    //tinh N
    N = 1;
    for(int i=1; i<=K; i++) {
        N *= p[i];
    }
}

void solve()
{
    for(ull i=0; i<=R; i++) {
        if((i*i*i)%N == C) {
            cout << i << "\n";
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    for(int i=1; i<=K; i++) cin >> p[i];
    cin >> C;
    cal();
    solve();

    return 0;
}

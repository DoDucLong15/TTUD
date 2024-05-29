#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, a[MAX];
long long seven_max = 0, seven_min = 0, sodd_max = INT_MIN, sodd_min = INT_MAX;

void solve()
{
    long long sum = 0;
    for(int i=1; i<=n; i++) {
        sum += a[i];
        if(sum % 2 == 0) {
            seven_max = max(seven_max, sum);
            seven_min = min(seven_min, sum);
        }
        else {
            sodd_max = max(sodd_max, sum);
            sodd_min = min(sodd_min, sum);
        }
    }
    if(sodd_max == INT_MIN || sodd_min == INT_MAX) cout << seven_max-seven_min << "\n";
    else {
        long long value = max(seven_max-seven_min, sodd_max-sodd_min);
        cout << value << "\n";
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, m;
int a[MAX];

bool isPossible(int mid)
{
    int currentSum = 0;
    int dem=1, i=0;
    while(i < n) {
        if(a[i] > mid) return false;
        if(currentSum + a[i] > mid) {
            dem++;
            currentSum = a[i];
            if(dem > m) return false;
        }
        else currentSum += a[i];
        i++;
    }
    return true;
}

int solve()
{
    int sum = 0;
    if(n < m) return -1;
    for(int i=0; i<n; i++) sum += a[i];
    int Start = a[n-1], End = sum, result = INT_MAX;
    while(Start <= End) {
        int mid = (Start + End)/2;
        if(isPossible(mid)) {
            result = mid;
            End = mid-1;
        }
        else Start = mid + 1;
    }
    return result;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    cout << solve() << "\n";

    return 0;
}

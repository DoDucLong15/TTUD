#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e9 + 7;
int n, a[N];
int temp[N];

long long _merge(int l, int m, int r)
{
    long long cnt = 0;
    //m = mid+1;
    int i=l, j=m;
    int k = l;
    while(i <= (m-1) && j <= r) {
        if(a[i] > a[j]) {
            cnt += (m-i);
            temp[k] = a[j];
            k++;
            j++;
        }
        else {
            temp[k] = a[i];
            k++;
            i++;
        }
    }
    while(i <= (m-1)) {
        temp[k] = a[i];
        k++;
        i++;
    }
    while(j <= r) {
        temp[k] = a[j];
        k++;
        j++;
    }
    for(int i=l; i<=r; i++) a[i] = temp[i];
    return cnt;
}

long long merge_sort(int l, int r)
{
    long long res = 0;
    if(l < r) {
        int m = (l+r)/2;
        res += merge_sort(l, m);
        res += merge_sort(m+1, r);
        res += _merge(l, m+1, r);
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    cout << merge_sort(1, n)%M << "\n";

    return 0;
}

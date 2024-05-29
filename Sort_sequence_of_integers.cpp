#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, a[MAX];
int temp[MAX];

void _merge(int l, int mid, int r);

void _merge_sort(int l, int r)
{
    if(l < r) {
        int mid = (l+r)/2;
        _merge_sort(l, mid);
        _merge_sort(mid+1, r);
        _merge(l, mid, r);
    }
}

void _merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else temp[k++] = a[j++];
    }
    while(i <= mid) {
        temp[k++] = a[i++];
    }
    while(j <= r) {
        temp[k++] = a[j++];
    }
    for(int i=l; i<=r; i++) a[i] = temp[i];
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    _merge_sort(0, n-1);

    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}

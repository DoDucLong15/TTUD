#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int n, a[MAX], temp[MAX];

long long Merge(int left, int mid, int right)
{
    int i=left, j=mid, k=left;
    long long inv_count = 0;
    while((i <= mid-1) && (j <= right)) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            inv_count += mid-i;
        }
    }
    while(i <= mid-1) {
        temp[k++] = a[i++];
    }
    while(j <= right) {
        temp[k++] = a[j++];
    }
    for(int i=left; i<=right; i++) a[i] = temp[i];
    return inv_count;
}

long long mergeCom(int left, int right)
{
    int mid;
    long long inv_count=0;
    if(left < right) {
        mid = (left + right)/2;
        inv_count += mergeCom(left, mid);
        inv_count += mergeCom(mid+1, right);
        inv_count += Merge(left, mid+1, right);
    }
    return inv_count;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    long long result = mergeCom(0, n-1);
    cout << result % (1000000000 + 7) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int n, M;
int a[MAX], temp[MAX];

int _merge(int left, int mid, int right)
{
    int i=left, j=mid+1, k=left;
    int p=mid, q=mid+1, cnt = 0;
    while(p >= left && q <= right) {
        if(a[p] + a[q] == M) {
            cnt++;
            p--;
            q++;
        }
        else if(a[p] + a[q] > M) p--;
        else q++;
    }
    while(i <= mid && j <= right) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else temp[k++] = a[j++];
    }
    while(i <= mid) {
        temp[k++] = a[i++];
    }
    while(j <= right) {
        temp[k++] = a[j++];
    }
    for(int i=left; i<=right; i++) a[i] = temp[i];
    return cnt;
}

int merge_part(int left, int right)
{
    int mid;
    int cnt = 0;
    if(left < right) {
        mid = (left + right)/2;
        cnt += merge_part(left, mid);
        cnt += merge_part(mid+1, right);
        cnt += _merge(left, mid, right);
    }
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &M);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    int res = merge_part(0, n-1);
    printf("%d\n", res);

    return 0;
}

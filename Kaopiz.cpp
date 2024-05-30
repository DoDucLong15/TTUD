#include <bits/stdc++.h>
using namespace std;

int solve1(int price[], int n)
{
    set<int> st;
    int res = INT_MAX;
    int result[n];
    result[0] = 0;
    st.insert(price[0]);
    for(int i=1; i<n; i++) {
        auto it = st.lower_bound(price[i]);
        if(it != st.end()) {
            result[i] = (*it) - price[i];
            res = min(res, result[i]);
        }
        else result[i] = 0;
        st.insert(price[i]);
    }
    return res;
}

bool solve2(int arr[], int n)
{
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    int left = 0, right = sum - arr[0];
    for(int i=0; i<n-1; i++) {
        if(left == right) return true;
        else {
            left += arr[i];
            right -= arr[i+1];
        }
    }
    if(left == right) return true;
    return false;
}

int result = INT_MAX;
void _merge(int arr[], int n, int l, int mid, int r)
{
    int tmp[n], k=l;
    int i=l, j=mid;
    while(i < mid && j <= r) {
        if(arr[i] > arr[j]) {
            result = min(result, arr[i] - arr[j]);
            tmp[k++] = arr[j++];
        }
        else {
            tmp[k++] = arr[i++];
        }
    }
    while(i < mid) {
         tmp[k++] = arr[i++];
    }
    while(j <= r) {
        tmp[k++] = arr[j++];
    }
    for(int i=l; i<=r; i++) {
        arr[i] = tmp[i];
    }
}

void _mergePart(int arr[], int n, int l, int r)
{
    if(l < r) {
        int mid = (l+r)/2;
        _mergePart(arr, n, l, mid);
        _mergePart(arr, n, mid+1, r);
        _merge(arr, n, l, mid+1, r);
    }
}

int main()
{
    int price[5] = {22, 16, 8, 2, 14};
    int n = 5;
//    _mergePart(price, n, 0, n-1);
//    cout << result << "\n";
    cout << solve1(price, n) << "\n";

    return 0;
}

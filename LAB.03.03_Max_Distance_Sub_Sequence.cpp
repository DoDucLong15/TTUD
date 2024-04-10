#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int arr[], int n, int k) {
    int pos = arr[0];
    int elements = 1; //do chua arr[0] roi
    for (int i = 1; i < n; i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if (elements == k)
                return true;
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int k) {
    sort(arr, arr + n);
    int res = -1;
    int left = 1, right = arr[n - 1];
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid, arr, n, k)) {
            res = max(res, mid);
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, C;
        scanf("%d%d", &N, &C);
        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        cout << largestMinDist(arr, N, C) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

long long max_even_subarray()
{
    long long max_so_far = 0;
    long long max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }

        else if ((max_so_far < max_ending_here) && (max_ending_here % 2 == 0)) {
            max_so_far = max_ending_here;
        }
    }

    return max_so_far;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    cout << max_even_subarray() << "\n";

    return 0;
}

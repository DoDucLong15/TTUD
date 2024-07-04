// GROUPUP

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int solve(vector<int> a, int n)
{
    int value = 0;
    while(a.size() > 1) {
        vector<int> b;
        int i=0, res = INT_MIN;
        int len = a.size();
        while(i+1 < len) {
            int d = a[i] + a[i+1];
            res = max(res,d);
            b.push_back(d);
            i += 2;
        }
        while(i < len) {
            b.push_back(a[i]);
            i++;
        }
        value += res;
        a = b;
    }
    return value;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, tmp;
        vector<int> a;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
        cout << solve(a,n) << "\n";
    }

    return 0;
}

/*
1
6
3 1 2 5 4 3
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2005;
int n;
int a[MAX];
int cnt = 0;
set<int> st;

void solve(int x)
{
    st.erase(x);
    vector<int> v(st.begin(), st.end());
    int l=0, r=n-2;
    while(l < r) {
        if(v[l]+v[r] == x) {
            cnt++;
            l++;
            r--;
        }
        else if(v[l]+v[r] < x) {
            l++;
        }
        else r--;
    }
    st.insert(x);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        st.insert(a[i]);
    }
    for(int i=0; i<n; i++) {
        solve(a[i]);
    }
    cout << cnt << "\n";

    return 0;
}

/*
6
9 5 4 3 8 1
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int n, m; //kich thuoc n x m
int a[MAX][MAX];

int largestHis(int arr[], int n)
{
    vector<int> next(n, n);
    vector<int> prev(n, -1);
    stack<int> st;
    //next small
    st.push(n);
    for(int i=n-1; i>=0; i--) {
        while(st.top() != n && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        next[i] = st.top();
        st.push(i);
    }
    //prev small
    stack<int> empty;
    st.swap(empty);
    st.push(-1);
    for(int i=0; i<=n-1; i++) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        prev[i] = st.top();
        st.push(i);
    }
    int area = INT_MIN;
    for(int i=0; i<n; i++) {
        area = max(area, arr[i]*(next[i]-prev[i]-1));
    }
    return area;
}

void solve()
{
    int tmp[m];
    memset(tmp, 0, sizeof(tmp));
    for(int j=0; j<m; j++) tmp[j] = a[0][j];
    int res = largestHis(tmp, m);
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == 0) tmp[j] = 0;
            else tmp[j] += a[i][j];
        }
        res = max(res, largestHis(tmp,m));
    }
    cout << res << "\n";
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
    solve();

    return 0;
}

/*
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
*/

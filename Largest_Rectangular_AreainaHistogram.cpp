#include <bits/stdc++.h>
using namespace std;

int largest_rectangular_his(int a[], int n)
{
    vector<int> next(n, n);
    vector<int> prev(n, -1);
    //next samller
    stack<int> st;
    st.push(n);
    for(int i=n-1; i>=0; i--) {
        while(st.top() != n && a[st.top()] >= a[i]) {
            st.pop();
        }
        next[i] = st.top();
        st.push(i);
    }
    //last smaller
    stack<int> s;
    s.push(-1);
    for(int i=0; i<n; i++) {
        while(s.top() != -1 && a[s.top()] >= a[i]) {
            s.pop();
        }
        prev[i] = s.top();
        s.push(i);
    }
    int max_area = INT_MIN;
    for(int i=0; i<n; i++) {
        max_area = max(max_area, a[i] * (next[i]-prev[i]-1));
    }
    return max_area;
}

int main()
{
    int a[6] = {3, 5, 1, 7, 5, 9};
    int n = 6;
    cout << largest_rectangular_his(a, n) << "\n";

    return 0;
}

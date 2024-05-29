#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int n, m, arr[MAX][MAX];

int largest_rectangular_his(vector<int> a, int n)
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

int max_subrectangle()
{
    vector<vector<int> > v;
    vector<int> _temp;
    for(int i=0; i<m; i++) {
        _temp.push_back(arr[0][i]);
    }
    v.push_back(_temp);
    int maxArea = largest_rectangular_his(_temp, m);
    for(int i=1; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            if(arr[i][j]) temp.push_back(v[i-1][j] + arr[i][j]);
            else temp.push_back(0);
        }
        v.push_back(temp);
        maxArea = max(maxArea, largest_rectangular_his(temp, m));
    }
    return maxArea;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            scanf("%d", &arr[i][j]);
        }
    cout << max_subrectangle() << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    set<int> st;
    for(int i=0; i<n; i++) {
        int size = st.size();
        st.insert(a[i]);
        if(size != st.size()) cout << "0" << endl;
        else cout << "1" << endl;
    }

    return 0;
}

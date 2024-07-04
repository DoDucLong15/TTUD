#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int n;
int a[MAX];

void GhiNhan()
{
    for(int i=1; i<=n; i++) {
        cout << a[i];
    }
    cout << "\n";
}

int main()
{
    scanf("%d", &n);

//    stack<string> st;
//    st.push("");
//    while(!st.empty()) {
//        string s = st.top(); st.pop();
//        if(s.length() == n) {
//            cout << s << "\n";
//        }
//        else {
//            st.push(s + "1");
//            st.push(s + "0");
//        }
//    }

    //solution 2
    stack<pair<int,int>> st;
    st.push(make_pair(0,0));
    while(!st.empty()) {
        auto node = st.top();
        a[node.first] = node.second;
        if(node.first == n) {
            st.pop();
            GhiNhan();
        }
        else {
            st.push(make_pair(node.first+1,1));
            st.push(make_pair(node.first+1,0));
        }
    }

    return 0;
}

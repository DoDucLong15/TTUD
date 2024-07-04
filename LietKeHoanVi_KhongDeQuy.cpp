#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int n;
int a[MAX];

bool check(string s, int a)
{
    if(s.find(to_string(a)) != string::npos) return false;
    return true;
}

int main()
{
    scanf("%d", &n);

    stack<string> st;
    st.push("");
    while(!st.empty()) {
        string s = st.top(); st.pop();
        if(s.length() == n) {
            cout << s << "\n";
        }
        else {
            for(int i=n; i>=1; i--) {
                if(check(s,i)) {
                    st.push(s + to_string(i));
                }
            }
        }
    }

    return 0;
}

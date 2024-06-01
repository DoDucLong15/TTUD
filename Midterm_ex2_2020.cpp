//DINO

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
int a[MAX];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    stack<int> st;
    for(int i=n-1; i>=0; i--) st.push(a[i]);
    queue<int> q;

    string s;
    getchar();
    getline(cin,s);
    for(auto ch : s) {
        if(ch == 'C') {
            if(!st.empty()) {
                q.push(st.top());
                st.pop();
            }
        }
        else if(ch == 'H') {
            if(!q.empty()) {
                st.push(q.front());
                q.pop();
            }
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    return 0;
}

/*
4
3 1 4 2
CCHCCHHH
*/

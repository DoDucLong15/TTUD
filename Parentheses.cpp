#include <bits/stdc++.h>
using namespace std;

bool parentheses(string s)
{
    stack<char> st;
    int length = s.length();
    for(int i=0; i<length; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else {
            if(!st.empty()) {
                char c = st.top();
                if((s[i]==')' && c=='(') || (s[i]==']' && c=='[') || (s[i]=='}' && c=='{')) st.pop();
                else return false;
            }
            else return false;
        }
    }
    if(st.empty()) return true;
    return false;
}

int main()
{
    string s;
    getline(cin, s);

    if(parentheses(s)) cout << "1\n";
    else cout << "0\n";

    return 0;
}

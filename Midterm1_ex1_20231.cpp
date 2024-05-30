//Given a string representing a math expression including operator + and operands
// (positive integers). Compute the value Q of this expression.

//Input 2+1+7+4
//Output: 14

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int i=0, len=s.length();
    stack<int> st;
    int cnt = 0;
    while(i < len) {
        if(s[i] == '+') {
            cnt++;
            if(st.empty()) break;
            else i++;
        }
        else {
            string value = "";
            while(s[i] != '+' && s[i] != '\0') {
                value += s[i];
                i++;
            }
            st.push(stoi(value));
        }
    }
    if(i == len) {
        if(cnt == st.size()) cout << "NOT_CORRECT\n";
        else {
            int result = 0;
            while(!st.empty()) {
                result += st.top();
                st.pop();
            }
            cout << result << "\n";
        }
    }
    else {
        cout << "NOT_CORRECT\n";
    }

    return 0;
}

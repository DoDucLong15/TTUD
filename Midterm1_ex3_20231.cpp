#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    string s;
    getline(cin, s);
    while(s != "#") {
        stringstream ss(s);
        string command;
        int num;
        ss >> command >> num;
        if(command == "PUSH") {
            st.insert(num);
        }
        else if(command == "POP") {
            int d = *st.begin();
            st.erase(st.begin());
            cout << d << "\n";
        }
        getline(cin, s);
    }
    return 0;
}
/*
PUSH 10
PUSH 4
PUSH 1
PUSH 8
PUSH 7
POP
PUSH 2
PUSH 9
POP
POP
POP
#
*/

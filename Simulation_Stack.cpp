#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    string s, request, num;
    int n;
    getline(cin,s);
    while(s != "#") {
        stringstream ss(s);
        ss >> request >> num;
        if(request == "PUSH") {
            n = stoi(num);
            st.push(n);
        }
        else if(request == "POP") {
            if(!st.empty()) {
                int d = st.top();
                st.pop();
                printf("%d\n", d);
            }
            else printf("NULL\n");
        }
        getline(cin,s);
    }

    return 0;
}

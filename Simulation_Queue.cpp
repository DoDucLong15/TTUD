#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    string s, request, num;
    int n;
    getline(cin,s);
    while(s != "#") {
        stringstream ss(s);
        ss >> request >> num;
        if(request == "PUSH") {
            n = stoi(num);
            q.push(n);
        }
        else if(request == "POP") {
            if(!q.empty()) {
                int d = q.front();
                q.pop();
                printf("%d\n", d);
            }
            else printf("NULL\n");
        }
        getline(cin,s);
    }

    return 0;
}


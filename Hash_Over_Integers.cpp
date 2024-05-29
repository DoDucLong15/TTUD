//C++
#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
    string s;
    getline(cin, s);
    while(s != "*") {
        mp[s] = 1;
        getline(cin, s);
    }
    getline(cin, s);
    while(s != "***") {
        stringstream ss(s);
        string command, num;
        ss >> command >> num;
        if(command == "find") {
            if(mp[num] == 1) cout << "1\n";
            else cout << "0\n";
        }
        else if(command == "insert") {
            if(mp[num] == 1) {
                cout << "0\n";
            }
            else {
                cout << "1\n";
                mp[num] = 1;
            }
        }
        getline(cin, s);
    }

    return 0;
}

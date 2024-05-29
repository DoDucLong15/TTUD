#include <bits/stdc++.h>
using namespace std;

int n, L, m;
vector<string> v;
set<int> key;

int main()
{
    scanf("%d%d%d", &n, &L, &m); getchar();
    string s;
    for(int i=0; i<n; i++) {
        getline(cin, s);
        int d = stoi(s);
        key.insert(d);
    }
    int i=1, cnt = 1;
    while(cnt <= m) {
        if(key.find(i) != key.end()) {
            key.erase(i);
            string tmp = to_string(i);
            int d = tmp.length();
            string zero(L-d,'0');
            cout << zero << tmp << "\n";
        }
        else {
            string tmp = to_string(i);
            int d = tmp.length();
            string zero(L-d,'0');
            cout << zero << tmp << "\n";
            cnt++;
        }
        i++;
    }
    for(set<int>::iterator it=key.begin(); it!=key.end(); it++) {
        string tmp = to_string(*it);
        int d = tmp.length();
        string zero(L-d,'0');
        cout << zero << tmp << "\n";
    }

    return 0;
}

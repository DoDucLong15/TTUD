#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    vector<int> v;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    getchar();
    string s;
    getline(cin, s);
    while(s != "#") {
        string command, u, p;
        int a, b;
        stringstream ss(s);
        ss >> command >> u >> p;
        if(command == "addlast") {
            a = stoi(u);
            auto it = find(v.begin(), v.end(), a);
            if(it == v.end()) v.push_back(a);
        }
        else if(command == "addfirst") {
            a = stoi(u);
            auto it = find(v.begin(), v.end(), a);
            if(it == v.end()) {
                v.insert(v.begin(), a);
            }
        }
        else if(command == "addafter") {
            a = stoi(u);
            b = stoi(p);
            auto it1 = find(v.begin(), v.end(), b);
            auto it2 = find(v.begin(), v.end(), a);
            if(it1 != v.end() && it2 == v.end()) {
                v.insert(it1+1, a);
            }
        }
        else if(command == "addbefore") {
            a = stoi(u);
            b = stoi(p);
            auto it1 = find(v.begin(), v.end(), b);
            auto it2 = find(v.begin(), v.end(), a);
            if(it1 != v.end() && it2 == v.end()) {
                v.insert(it1, a);
            }
        }
        else if(command == "remove") {
            a = stoi(u);
            auto it = find(v.begin(), v.end(), a);
            if(it != v.end()) v.erase(it);
        }
        else if(command == "reverse") {
            reverse(v.begin(), v.end());
        }
        getline(cin,s);
    }
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << "\n";

    return 0;
}

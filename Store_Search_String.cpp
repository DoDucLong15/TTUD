#include <bits/stdc++.h>
using namespace std;

string s, demand, vocabulary;
map<string, int> mp;

int _find(string vocab)
{
    if(mp[vocab]==1) return 1;
    return 0;
}

int _insert(string vocab)
{
    if(_find(vocab)) return 0;
    mp[vocab] = 1;
    return 1;
}

int main()
{
    getline(cin, s);
    while(s != "*") {
        mp[s] = 1;
        getline(cin, s);
    }
    getline(cin, s);
    while(s != "***") {
        stringstream ss(s);
        ss >> demand >> vocabulary;
        if(demand == "find") cout << _find(vocabulary) << "\n";
        else if(demand == "insert") cout << _insert(vocabulary) << "\n";
        getline(cin, s);
    }

    return 0;
}

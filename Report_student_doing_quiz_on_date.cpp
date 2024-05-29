#include <bits/stdc++.h>
using namespace std;

map<string,set<string>> mp; //luu danh sach quiz lam trong ngay
set<string> st; //luu ngay

int main()
{
    string s;
    string date, time, user_id, question_id;
    getline(cin, s);
    while(s != "*") {
        stringstream ss(s);
        ss >> date >> time >> user_id >> question_id;
        string temp = user_id + question_id;
        mp[date].insert(temp);
        st.insert(date);
        getline(cin,s);
    }
    for(set<string>::iterator it=st.begin(); it!=st.end(); it++) {
        cout << *it << " " << mp[*it].size() << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int Q = 1e9 + 7;
string s;

int main()
{
    getline(cin, s);
    //chuyen sang bieu thuc hau to
    string res = "";
    int i=0, len=s.length();
    stack<char> opera;
    while(i < len)
    {
        if(isdigit(s[i])) res += s[i];
        else {
            res += '#';
            if(opera.empty()) opera.push(s[i]);
            else {
                if(s[i] == '*') {
                    if(opera.top() == '+') opera.push(s[i]);
                    else res += s[i];
                }
                else {
                    if(opera.top() == '+') res += s[i];
                    else {
                        res += opera.top();
                        opera.pop();
                        opera.push(s[i]);
                    }
                }
            }
        }
        i++;
    }
    while(!opera.empty()) {
        res += opera.top();
        opera.pop();
    }

    //tinh toan
    stack<int> num;
    i=0;
    int length = res.length();
    bool ok = true;
    while(i < length) {
        if(isdigit(res[i])) {
            string tmp = "";
            while(res[i] != '#' && res[i] != '+' && res[i] != '*') {
                tmp += res[i];
                i++;
            }
            num.push(stoi(tmp));
        }
        else if(res[i] == '#') i++;
        else if(res[i] == '+') {
            if(num.size() < 2) {
                ok = false;
                break;
            }
            int d1 = num.top(); num.pop();
            int d2 = num.top(); num.pop();
            num.push((d1+d2)%Q);
            i++;
        }
        else if(res[i] == '*') {
            if(num.size() < 2) {
                ok = false;
                break;
            }
            int d1 = num.top(); num.pop();
            int d2 = num.top(); num.pop();
            num.push((d1*d2)%Q);
            i++;
        }
    }
    if(!ok) cout << "NOT_CORRECT\n";
    else cout << num.top()%Q << "\n";

    return 0;
}

/*
5+7*3*10*10
*/

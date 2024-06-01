// Perform Insertion and Delete-Max on a collection

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
priority_queue<int> q;

int main()
{
    scanf("%d", &n);
    int tmp;
    for(int i=0; i<n; i++) {
        scanf("%d", &tmp);
        q.push(tmp);
    }
    getchar();
    string s;
    getline(cin, s);
    while(s != "*") {
        stringstream ss(s);
        string command;
        int num;
        ss >> command >> num;
        if(command == "insert") {
            q.push(num);
        }
        else if(command == "delete-max") {
            cout << q.top() << "\n";
            q.pop();
        }
        getline(cin, s);
    }
    return 0;
}

/*
10
8 5 7 9 10 4 7 2 2 6
insert 3
delete-max
insert 6
insert 10
insert 7
insert 8
delete-max
delete-max
delete-max
delete-max
*
*/

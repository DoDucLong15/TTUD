#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int v, e; //so dinh va so canh
vector<int> adj[MAX]; //danh sach canh ke
int d[MAX]; //ban bac vao cua moi dinh
vector<int> lst;

void topo()
{
    //Y tuong: tinh ban bac vao, bang 0 thi cho vao queue,
    //lay ra lan luot va cap nhat ban bac vao
    queue<int> q;
    for(int i=1; i<=v; i++) {
        if(d[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        lst.push_back(u);
        for(auto x : adj[u]) {
            d[x]--;
            if(d[x] == 0) q.push(x);
        }
    }
}

int main()
{
    scanf("%d%d", &v, &e);
    //khoi tao d
    for(int i=1; i<=v; i++) d[i] = 0;
    int a, b;
    for(int i=0; i<e; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        d[b]++;
    }
    topo();
    if(lst.size() != v) cout << "Do thi co chu trinh!\n";
    else {
        for(auto x : lst) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

/*
6 10
1 3
2 1
2 3
2 5
2 6
4 1
4 5
5 1
6 4
6 5
*/

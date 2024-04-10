#include <bits/stdc++.h>
using namespace std;

int n, K, Q;
vector<vector<int> > c;
vector<int> d;
vector<vector<int> > road;
vector<int> length_road;
vector<int> capacity;

pair<int,int> selectClientTruck(set<int> C)
{
    int MIN = INT_MAX, sel_k = -1, sel_i=-1;
    for(int i=0; i<K; i++) {
        int last = road[i].back();
        for(int x : C) {
            if(capacity[i] + d[x-1] > Q) continue;
            int maxL = length_road[i] + c[last][x];
            for(int j=0; j<K; j++) {
                if(j != i) {
                    if(maxL < length_road[i]) maxL = length_road[i];
                }
            }
            if(maxL < MIN) {
                MIN = maxL;
                sel_k = i;
                sel_i = x;
            }
        }
    }
    return {sel_k,sel_i};
}

void printSolution()
{
    for(int i=0; i<K; i++) {
        length_road[i] += c[road[i].back()][0];
        if(road[i].size() == 1) cout << "0\n";
        else {
            cout << road[i].size()-1 << " ";
            for(int j=1; j<road[i].size(); j++) cout << road[i][j] << " ";
            cout << "\n";
        }
    }
}

void Greedy()
{
    set<int> C;
    for(int i=1; i<=n; i++) C.insert(i); //UCV
    while(!C.empty()) {
        pair<int,int> s = selectClientTruck(C);
        if(s.first == -1) {
            cout << "Can't\n";
            return;
        }
        int a = s.first;
        int b = s.second;
        int last = road[a].back();
        length_road[a] += c[last][b];
        capacity[a] += d[b-1];
        road[a].push_back(b);
        C.erase(b);
    }
    printSolution();
}

int main()
{
    int temp;
    scanf("%d%d", &K, &n);
    for(int i=0; i<K; i++) {
        scanf("%d", &temp);
        capacity.push_back(temp);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &temp);
        d.push_back(temp);
    }
    for(int i=1; i<=K; i++) {
        vector<int> v = {0};
        road.push_back(v);
        length_road.push_back(0);
    }
    for(int i=0; i<=n; i++) {
        vector<int> vt;
        for(int j=0; j<=n; j++) {
            scanf("%d", &temp);
            vt.push_back(temp);
        }
        c.push_back(vt);
    }

    Greedy();

    return 0;
}



/*

*/

#include <bits/stdc++.h>
using namespace std;

int n, K, Q;
vector<vector<int> > c;
vector<int> d;
vector<vector<int> > road;
vector<int> length_road;
vector<int> capacity;

int TruckIsMinLengthRoad()
{
    int MIN = INT_MAX, position=-1;
    for(int i=0; i<K; i++) {
        if(length_road[i] < MIN) {
            MIN = length_road[i];
            position = i;
        }
    }
    return position;
}

int NextPerson(set<int> C, int a)
{
    int lastPerson = road[a].back();
    int MIN = INT_MAX, position = -1;
    for(auto x : C) {
        if((capacity[a] + d[x-1]) <= Q && c[lastPerson][x] < MIN) {
            MIN = c[lastPerson][x];
            position = x;
        }
    }
    return position;
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
        int a = TruckIsMinLengthRoad();
        int lastPerson = road[a].back();
        int b = NextPerson(C, a);
        if(b == -1) {
            cout << "No solution\n";
            return;
        }
        road[a].push_back(b);
        length_road[a] += c[lastPerson][b];
        capacity[a] += d[b-1];
        C.erase(b);
    }
    printSolution();
}

int main()
{
    int temp;
    scanf("%d%d%d", &n, &K, &Q);
    for(int i=1; i<=n; i++) {
        scanf("%d", &temp);
        d.push_back(temp);
    }
    for(int i=1; i<=K; i++) {
        vector<int> v = {0};
        road.push_back(v);
        length_road.push_back(0);
        capacity.push_back(0);
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


/*
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.
A person wants to find a closed tour that visits each city exactly once (excelt the starting city).
Find the itinerary for that person so that the total travel distance is minimal.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int n, c[MAX][MAX];
map<int, int> mp;
bool visisted[MAX];
int parent[MAX];

struct edge
{
    int from;
    int to;
    int value;
};

vector<edge> v;

void init()
{
    for(int i=1; i<=n; i++) {
        mp[i] = 0;
        visisted[i] = false;
    }
}

bool compareEdge(edge a, edge b)
{
	return a.value < b.value;
}

void make_set(int n) {
	for(int i=1; i<=n; i++) {
		parent[i] = i;
	}
}

int Find(int v) {
	if(v == parent[v]) return v;
	else return parent[v] = Find(parent[v]);
}

int main()
{
    int dem = 1;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) {
                edge E;
                E.from = i;
                E.to = j;
                E.value = c[i][j];
                v.push_back(E);
            }
        }
    init();
    make_set(n);
    sort(v.begin(), v.end(), compareEdge); //sap xep cac canh tang dan
    for(int i=0; i<v.size(); i++) {
        if(dem == n) break;
        if(mp[v[i].from] != 0) continue;
        else if (!visisted[v[i].to]) {
            int from = Find(v[i].from);
            int to = Find(v[i].to);
            if(from != to) {
                mp[v[i].from] = v[i].to;
                visisted[v[i].to] = true;
                parent[to] = from;
                dem++;
            }
        }
        else continue;
    }

    int start;
    for(int i=1; i<=n; i++)
        if(!visisted[i]) {
            start = i;
            break;
        }

    cout << n << "\n";
    while(mp[start] != 0) {
        cout << start << " ";
        start = mp[start];
    }
    cout << start << "\n";

    return 0;
}

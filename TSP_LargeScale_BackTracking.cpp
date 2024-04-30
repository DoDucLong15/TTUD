/*
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.
A person wants to find a closed tour that visits each city exactly once (excelt the starting city).
Find the itinerary for that person so that the total travel distance is minimal.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int n, c[MAX][MAX], c_min = INT_MAX;
int result[MAX], road[MAX], f_min = INT_MAX, f = 0;
bool marked[MAX];

void init()
{
    for(int i=1; i<=n; i++) marked[i] = false;
    f = 0;
}

bool check(int n)
{
    if(marked[n]) return false;
    return true;
}

void GhiNhan()
{
    int d = f + c[road[n]][road[1]];
    f_min = min(f_min, d);
}

void Try(int k)
{
    for(int i=2; i<=n; i++) {
        if(check(i)) {
            road[k] = i;
            f += c[road[k-1]][i];
            marked[i] = true;
            if(k == n) GhiNhan();
            else if(f + c_min*(n-k+1) < f_min) Try(k+1);
            f -= c[road[k-1]][i];
            marked[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) {
                c_min = min(c_min, c[i][j]);
            }
        }
    init();
    road[1] = 1;
    marked[1] = true;
    Try(2);
    cout << f_min << "\n";

    return 0;
}


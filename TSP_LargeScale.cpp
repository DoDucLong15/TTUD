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

void GhiNhan()
{
    f += c[road[n]][road[1]];
    if(f < f_min) {
        for(int i=1; i<=n; i++) result[i] = road[i];
        f_min = f;
    }
}

void Try(int k)
{
    //k la dinh xuat phat
    int dem = 1;
    road[dem] = k;
    marked[k] = true;
    while(dem <= n) {
        int min_num = INT_MAX, min_position = -1;
        for(int i=1; i<=n; i++) {
            if(!marked[i] && c[k][i] < min_num) {
                min_num = c[k][i];
                min_position = i;
            }
        }
        marked[min_position] = true;
        f += min_num;
        if(f > f_min) return;
        k = min_position;
        dem++;
        road[dem] = k;
    }
    GhiNhan();
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
    for(int i=1; i<=n; i++) {
        init();
        Try(i);
    }

    cout << n << "\n";
    for(int i=1; i<=n; i++) cout << result[i] << " ";
    cout << "\n";

    return 0;
}

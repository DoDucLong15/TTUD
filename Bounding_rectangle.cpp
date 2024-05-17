#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2;
    int x_min = INT_MAX, y_min = INT_MAX;
    int x_max = INT_MIN, y_max = INT_MIN;
    for(int i=0; i<n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x_min = min(x_min, min(x1, x2));
        y_min = min(y_min, min(y1, y2));
        x_max = max(x_max, max(x1, x2));
        y_max = max(y_max, max(y1, y2));
    }
    printf("%d\n", (y_max-y_min)*(x_max-x_min));

    return 0;
}

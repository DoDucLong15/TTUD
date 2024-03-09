#include <bits/stdc++.h>
using namespace std;
#define MAX 1000100

int lookup[20][MAX];

void preprocess(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;
 
    for (int j = 1; (1 << j) <= n; j++) 
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) 
        {
            if (arr[lookup[i][j - 1]]
                < arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j]
                    = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int arr[], int L, int R)
{
    int j = (int)log2(R - L + 1);

    if (arr[lookup[L][j]]
        <= arr[lookup[R - (1 << j) + 1][j]])
        return arr[lookup[L][j]];
 
    else
        return arr[lookup[R - (1 << j) + 1][j]];
}

// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, j, k, res = 0;
    scanf("%d", &n);
    int* a = new int[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    preprocess(a, n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
    	scanf("%d%d", &j, &k);
    	res += query(a, j, k);
	}
	cout << res << "\n";
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, q;
	scanf("%d%d", &n, &m);
	int** a = new int*[n];
	for(int i=0; i<n; i++) a[i] = new int[m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
	int** b = new int*[n+1];
	for(int i=0; i<=n; i++) b[i] = new int[m+1];
	for(int i=0; i<=n; i++) b[i][0] = 0;
	for(int j=0; j<=m; j++) b[0][j] = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i-1][j-1];
	//tinh
	scanf("%d", &q);
	for(int i=0; i<q; i++) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		cout << b[r2][c2] - b[r2][c1-1] - b[r1-1][c2] + b[r1-1][c1-1] << "\n";
	}
	
	for(int i=0; i<n; i++) {
		delete(a[i]);
		delete(b[i]);
	}
	delete(a);
	delete(b);
	return 0;
} 
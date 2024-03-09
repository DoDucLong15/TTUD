#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n+1];
	for(int i=0; i<n; i++) scanf("%d", &a[i]); //scanf nhanh hon
	//tinh trc
	b[0] = 0;
	for(int i=1; i<=n; i++) b[i] = b[i-1] + a[i-1];
	
	cin >> q;
	for(int i=0; i<q; i++) {
		int m, n;
		cin >> m >> n;
		cout << b[n] - b[m-1] << "\n";
	}
	
	delete(a);
	delete(b);
	return 0;
}
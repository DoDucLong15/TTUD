#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, Q, temp;
	scanf("%d%d", &n, &Q);
	vector<int> v;
	for(int i=0; i<n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	int i=0, res = 0, sum = 0;
	for(int j=0; j<n; j++) {
		sum += v[j];
		while(sum > Q) {
			sum -= v[i];
			i++;
		}
		res = max(res, j-i+1);
	}	
	cout << res << "\n";
	return 0;
}
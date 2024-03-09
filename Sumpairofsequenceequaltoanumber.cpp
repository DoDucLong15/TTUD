#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, M, temp;
	vector<int> v;
	scanf("%d%d", &n, &M);
	for(int i=0; i<n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int i=0, j=n-1, count=0;
	while(i < j) {
		if(v[i] + v[j] == M) {
			count++;
			i++;
			j--;
		}
		else if(v[i] + v[j] > M) j--;
		else i++;
	}
	cout << count << "\n";
	
	return 0;
}
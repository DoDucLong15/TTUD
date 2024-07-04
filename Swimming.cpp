#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    int d = N/K;
    if(N != (d*K)) d++;
    int sum = 0;
    for(int i=1; i<=d; i++) sum += i;

    cout << sum << "\n";

    return 0;
}

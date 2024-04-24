#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, a[MAX];
int mem[MAX];
bool mark[MAX];

int maxSum(int i)
{
    if(i == 1) return a[1];
    if(mark[i]) return mem[i];

    int res = max(a[i], a[i] + maxSum(i-1));
    mem[i] = res;
    mark[i] = true;
    return res;
}

void Trace_2(int i)
{
    if(i != 1 && mem[i] == mem[i-1] +a[i]) {
        Trace_2(i-1);
        cout << a[i] << " ";
    }
}

void Trace(int i)
{
    stack<int> st;
    int sum = 0, _max = mem[i];
    while(sum < _max) {
        st.push(a[i]);
        sum += a[i];
        i--;
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    memset(mem, 0, sizeof(mem));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    maxSum(n);
    int positionMax = 1;
    for(int i=2; i<=n; i++)
        if(mem[i] > mem[positionMax]) positionMax = i;
    cout << mem[positionMax] << "\n";
    Trace(positionMax); //vong lap
    cout << "\n";
    Trace_2(positionMax); //de quy
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

const int maxn = 10010;
ll n, dp[maxn];
bool mark[maxn];

ll fib(ll x) {
    if (x <= 1) return 1;

    if (mark[x] == 1) return dp[x];

    mark[x] = 1;

    dp[x] = fib(x-1)+fib(x-2);
    
    return dp[x];
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fib(54); 

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

const int maxn = 10010;

int dp[maxn];
bool mark[maxn];

int solve(int i, int n, int k=0) {
    int ans = 0;
    
    if (i == n) return 1;
    if (i > n) return 0;

    if (mark[i]) return dp[i];
    
    ans = solve(i + 1, n, k) + solve(i + k, n, k);
    
    mark[i] = 1;
    dp[i] = ans;

    return ans;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;

    cout << solve(0, n, k);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100

int dp[5000];
bool visited[5000];

int mov(vector<int>& a, int pos) {
    if (dp[pos] != 0) return dp[pos];
   
    // se ja foi visitado, temos um ciclo;
    // queremos achar o fim do ciclo;
    if (visited[pos]) {
        int end = pos;
        int at = a[pos];

        while (at != pos) {
            end = at;
            at = a[at];
        }

        return end;
    }
    
    visited[pos] = 1; 
    int result = mov(a, a[pos]);
    visited[pos] = 0;

    dp[pos] = result;
    return result;
}

void solve() {
    
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(visited, 0, sizeof(visited));

    vector<int> a(n+1);
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int p = mov(a, i);
        cout << p << " ";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

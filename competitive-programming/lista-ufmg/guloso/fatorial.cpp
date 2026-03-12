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

void solve() {
    int n; cin >> n;
    
    vector<int> fat(11);
    fat[0] = 1;

    for (int i = 1; i <= 10; i++) fat[i] = fat[i-1] * i;

    int ans = 0;
    for (size_t i = 10; i > 0; i--) {
        if (fat[i] <= n) {
            n -= fat[i];
            //cout << n << ' ' << fat[i] << "\n";
            ans++;
            i++;
        } 
    }

    cout << ans << "\n";
}

// 10 -> 3! + 2! + 2!

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

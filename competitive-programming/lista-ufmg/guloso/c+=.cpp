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
    int a, b, n; cin >> a >> b >> n; 

    int sum = 0;
    int c = 0;
    while (sum <= n) {
        if (a > b) {
            b += a; sum = b;
        } else {
            a += b; sum = a;
        }
        c++;

        if (sum > n) break;
    }
    
    cout << c << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
    return 0;
}

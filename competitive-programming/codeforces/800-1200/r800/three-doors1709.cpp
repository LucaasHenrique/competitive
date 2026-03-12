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

void solve() {
    int n; cin >> n;

    vector<int> a(4);
    int c = 0;
    for (int i = 1; i <= 3; i++) {
        cin >> a[i];
        c += a[i];
    }   
    
    cout << (a[n] != 0 && a[a[n]] != 0 ? "YES" : "NO") << "\n";

}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
    return 0;
}

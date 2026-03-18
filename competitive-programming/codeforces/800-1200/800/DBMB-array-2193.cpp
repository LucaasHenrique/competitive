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

int sum_array(vector<int>& a) {
    int sum = 0;

    for (int i = 0; i < a.size(); i++) sum += a[i];

    return sum;
}

void solve() {
    
    int n, s, x; cin >> n >> s >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (sum_array(a) == s) cout << "YES" << "\n";
    else if (sum_array(a) > s) cout << "NO" << "\n";
    else if (abs(sum_array(a) - s) % x == 0) cout << "YES" << '\n';
    else cout << "NO" << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}

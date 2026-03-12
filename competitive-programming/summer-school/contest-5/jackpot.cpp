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
#define maxn 300100

void solve() {
    int n; cin >> n;
    vector<ll> a(2*n);

    for (int i = 0; i < 2*n; i++) cin >> a[i];
     
    sort(a.begin(), a.end());

    int i = (2*n)/2, j = ((2*n)/2) + 1;
    i--; j--;
    int t = 0; ll c = 0;
    while (i < a.size() && j < a.size() && t < n) {
        c += abs(a[i] - a[j]);
        t++;
        i--; j++;
    }

    cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
    return 0;
}

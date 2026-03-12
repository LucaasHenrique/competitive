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

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool c = true;
    while (c) {
        c = false;
        for (int i = 0; i < n; i++) {
            if (2*(i+1) <= n && a[i] > a[2*(i+1)-1]) {
                swap(a[i], a[2*(i+1)-1]);
                c = true;
            }
        }
     
   
    //for (auto p: a) cout << p << " ";
    int ct = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) ct++;
    }

    cout << (ct >= 1 ? "NO" : "YES") << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}

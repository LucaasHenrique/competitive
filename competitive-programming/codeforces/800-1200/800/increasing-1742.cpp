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
    
    vector<int> a(n);
    unordered_set<int> s;

   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    
    for (auto x: a) {
        if (s.count(x)) {cout << "NO" << "\n"; return;}

        s.insert(x);
    }

    cout << "YES" << "\n";
}
int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while(t--) solve();
    return 0;
}

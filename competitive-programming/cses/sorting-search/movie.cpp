#include <bits/stdc++.h>
#include <utility>

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

bool comp (pll a, pll b) {
    return a.s < b.s;
}

void solve() {
    int n; cin >> n; 

    vector<pll> m;

    for (int i = 0;  i < n; i++) {
        ll a, b; cin>> a >> b;
        m.push_back({a, b});
    }
    
    int c = 0; 
    sort(m.begin(), m.end(), comp);
    ll l = 0; 

    for (int i = 0; i < n; i++) {
        if (m[i].f >= l) {
            c++;
            l = m[i].s;
        }
    }

    cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

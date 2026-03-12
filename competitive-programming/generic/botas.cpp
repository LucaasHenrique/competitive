#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> p(61, {0, 0});
    while (n--) {
        int e; cin >> e;
        char a; cin >> a;
        
        if (a == 'E') {
            p[e].first++;
        } else p[e].second++;
    }

    int ans = 0;

    for (int i = 0; i < p.size(); i++) {
        ans += min(p[i].first, p[i].second);
    }

    cout << ans << '\n'; 
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

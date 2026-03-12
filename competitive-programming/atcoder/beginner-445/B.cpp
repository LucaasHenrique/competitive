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

    vector<string> ts(n);
    
    int mxl = 0;
    for (int i = 0; i <n; i++) {cin >> ts[i];
        mxl = max(mxl, (int) ts[i].size());
    }
    
    for (int i = 0; i < n; i++) {
        int df = mxl - (int) ts[i].size();

        for (int j = 0; j < df / 2; j++) {
            ts[i] = "." + ts[i] + ".";
        }

        cout << ts[i] << '\n';
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

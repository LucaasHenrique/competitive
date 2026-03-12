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
#define MAXN 100

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> ju(MAXN, vector<int>(MAXN));
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            ju[i][j] = x;
        }
    }

    bool chos[MAXN]; memset(chos, 0, sizeof(chos));
    int chosen[MAXN]; memset(chosen, 0, sizeof(chosen));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ju[i].size(); j++) {
            if (!chos[ju[i][j]] && ju[i][j] != 0) {
                chos[ju[i][j]] = true;
                chosen[i] = ju[i][j];
                break;
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        cout << chosen[i] <<"\n";
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

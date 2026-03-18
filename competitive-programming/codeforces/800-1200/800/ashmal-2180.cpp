#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define dbg(x) cout << #x << " = " << x << endl;

void solve() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<string> a(n);

        string s;
        while (n--) {
            string ai; cin >> ai;
            a.push_back(ai);
        }
        
        for (int i = 0; i < n; i++) {
            s = min(s + a[i], a[i] + s);
        }

        cout << s << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

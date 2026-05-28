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

// i = 1;
// 1 -> 001, i >> 1 => 100
// 001 ^ 000 = 001;
//
// 011
// 000
// 000 
//
//

void solve() {
    int n; cin >> n;
    
    vector<string> r;
    for (int i = 0; i < (1 << n); i++) {
        int gray = i ^ (i >> 1);
        string code = "";
        // constroi a string bit a bit
        for (int j = n - 1; j >= 0; j--) {
            code += (gray & (1 << j)) ? "1" : "0";
        }
        r.pb(code);
    }

    for (auto c: r) cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

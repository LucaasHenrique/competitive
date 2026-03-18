#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n, p, q; cin >> n;

    set<int> a;
    
    cin >> p;
    for (int i = 0; i < p; i++) {
        int b; cin >> b; a.insert(b);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int b; cin >> b; a.insert(b);
    }

    if (a.size() == n) cout << "I become the guy." << '\n';
    else cout << "Oh, my keyboard!";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

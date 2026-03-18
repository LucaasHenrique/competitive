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

bool distinct(int y) {
    
    set<int> s;
    while (y > 0) {
        int d = y % 10;
        y /= 10;

        if (s.count(d)) return false;

        s.insert(d);
    }
    
    return true;
}

void solve() {
    int y; cin >> y;
    
    y++;
    while (!distinct(y)) {
        y++;
    }

    cout << y << "\n";
}   

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

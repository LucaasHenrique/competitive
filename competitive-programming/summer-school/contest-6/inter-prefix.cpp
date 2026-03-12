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
    string t; cin >> t;
    string r = "";

    int c = 0;
    for (int i = 0; i < t.size(); i++) {
        int a = (int) t[i];
        if (a >= 48 && a <= 57) {c++; r += t[i];}
        else break;
    }

    cout << (c == 0 ? "-1" : r) << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

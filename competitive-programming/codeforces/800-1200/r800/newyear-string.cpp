#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        if (s.find("2026") != string::npos) cout << 0 << "\n"; 
        else if (s.find("2025") != string::npos) {
            int pos = s.find("2025");
            s[pos+3] = '6';
            cout << 1 << '\n'; 
        } else {
            cout << 0 << "\n";
        }
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

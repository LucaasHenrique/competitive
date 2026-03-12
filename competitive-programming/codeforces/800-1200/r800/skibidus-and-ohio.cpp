#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    string s; cin >> s;    
        
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i+1]) {
            cout << "1\n";
            return;
        }
    }

    cout << s.size() << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}

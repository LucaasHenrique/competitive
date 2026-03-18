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

        int c = 0;
        for (int i = s.size()-1; i >= 1; i--) {
            if (s[i - 1] != s[i]) {
                s[i-1] = s[i];
                c++;
            }
        }
    
        cout << c << '\n';
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

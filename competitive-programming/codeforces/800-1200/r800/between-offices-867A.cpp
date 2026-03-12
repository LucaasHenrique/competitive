#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n; cin >> n;

    string s = "";
    for (int i = 0; i < n; i++) {
        char a; cin >> a;
        s += a;
    }

    int sf = 0;
    int fs = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'S' && s[i+1] == 'F') sf++;
        else if (s[i] == 'F' && s[i+1] == 'S') fs++;
    }

    if (sf > fs) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}

























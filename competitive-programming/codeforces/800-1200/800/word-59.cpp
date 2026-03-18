#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (ll i = 0; i < n; i++)
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

bool is_uppercase(char c) {
    return c >= 65 && c <= 90; 
}

void to_upper(string& s) {
    for (char& c: s) {
        if (c >= 'a' && c <= 'z') c = c - 32;
    }
} 

void to_lower(string& s) {
    for (char& c: s) {
        if (c >= 'A' && c <= 'Z') c = c + 32;
    }
}

void solve() {
    string s; cin >> s;

    int up = 0, low = 0;
    for (int i = 0; i < s.size(); i++) {
        if (is_uppercase(s[i])) up++;
        else low++;
    }

    if (up > low) to_upper(s);
    else if (up == low) to_lower(s);
    else if (low > up )to_lower(s);
    
    cout << s << '\n';

}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

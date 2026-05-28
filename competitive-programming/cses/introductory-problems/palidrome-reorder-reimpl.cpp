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

void solve() {
    
    string s; cin >> s;
    string ans(s.size(), ' ');
    
    int freq[26] = {};
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'A']++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i]&1) cnt++; 
    }

    if (cnt > 1) {cout << "NO SOLUTION" << "\n"; return;}
    
    int l = 0, r = s.size() - 1;

    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]-'A']&1) {
            ans[s.size()/2] = s[i];
            freq[s[i] - 'A']--;
        }
        while (freq[s[i] - 'A'] > 0) {
            ans[l++] = ans[r--] = s[i];
            freq[s[i] - 'A'] -= 2;
        }
    }

    cout << ans << "\n";
}   

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

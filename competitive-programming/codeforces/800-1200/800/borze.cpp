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
    string s; cin >> s;

    
    for (int i = 0; i < s.size();) {
        if (s[i] == '-' && s[i+1] == '.') {cout << 1; i += 2;}
        else if (s[i] == '-' && s[i+1] == '-') {cout << 2; i += 2;}
        else if (s[i] == '.') {cout << 0;i++;} 
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

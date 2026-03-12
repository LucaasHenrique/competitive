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
    int n; cin >> n;
    
    string s; cin >> s; 
    int max_blocks = 0;
    
    for (int i = 0; i < n; i++) {
        int c = 0;
        string t = "";
        
        for (int j = i + 1; j < n; j++) {
            t += s[j];
        }  
        for (int k = 0; k <= i; k++) {
            t += s[k];
        }
        string s = t;
        t = " " + t + " ";
        for (int i = 1; i <= n; i++) {
            if (t[i] != t[i+1] && t[i ] != t[i-1]) c++;
            if (t[i] == t[i-1] && t[i] != t[i+1]) c++;
        }

        cout << t << " - " << c << '\n';
       
        max_blocks = max(max_blocks, c);
    }

    cout << max_blocks << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
    return 0;
}

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

bool jump(string& s, int d) {
    int pos = 0;
    int n = s.size();
    
    if (d >= n + 1) return true;
    
    int i = 0;
    int distancia = 0;
    while (i < n) {
        if (s[pos] == 'R') {
            distancia = i - pos;
            if (distancia > d) return false;
            else pos = i;
        }
        i++;
    }
    
    distancia = (n+1) - pos;
    if (distancia > d) return false;
    return true;


}

void solve() {
    string s; cin >> s;
    s = " " + s;
    int l = 1, r = s.size()-1;

    while (l < r) {
        int m = (l + r) / 2;
        if (jump(s, m)) r = m - 1;
        else l = m + 1;
    }

    cout << l << '\n';
}

int main (int argc, char *argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}

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
const int maxn = 1e5+10;

int n, c, t; 
int pipocas[maxn];

bool possible(ll chute) {
    int comp = 1;
    ll resta = t*chute;

    for (int i = 0; i < n; i++) {
        if (resta >= pipocas[i]) resta -= pipocas[i];
        else {
            comp++;
            resta = t*chute;
            i--;
        }
        if (comp > c) return 0;
    }

    return 1;
}

void solve() {
    cin >> n >> c >> t;
    
    for (int i =0; i < n; i++) cin >> pipocas[i];    
    
    int l = 0, r = 1e9+1;

    while (l < r) {
        int m = (l+r)/2;

        if (!possible(m)) l = m+1;
        else r = m;
    }

    cout << l << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

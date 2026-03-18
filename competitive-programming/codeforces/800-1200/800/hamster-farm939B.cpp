#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    ll n, k; cin >> n >> k;

    double ant = 0;
    ll res = 0;
    int p = 0;
    ll melhor = INF64;
    for (int i = 1; i <= k; i++) {
        ll a; cin >> a;
        
        ll r = n % a; 
        if (r == 0) {
            p = i;
            res = (ll) n / a;
            break;
        } else {
            if (r < melhor) {
                melhor = r;
                p = i;
                res = n / a;
            }
        }   
    }

    cout << p << " " << res;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

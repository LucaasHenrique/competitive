#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {

    int n, k; cin >> n >> k;
    ll a; cin >> a;

    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    ll tot = 0;
    for (int i = 0; i < p.size(); i++) {
        tot += p[i];
        k -= 1;

        if (k == 0 && tot <= a){
            cout << tot;
            return;
        }
    }
    
    cout << "Nao e possivel";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

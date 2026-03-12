#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

ll sum_digits(ll x) {
    ll soma = 0;

    while (x > 0) {
        soma += x % 10;
        x /= 10;
    }

    return soma;
}

void solve() {
    ll n; cin >> n;
    ll m = n;
    int k = 0;

    vector<ll> t;

    for (int i = max(1LL, n - 90); i <= n; i++) {        
        if (i + sum_digits(i) == m) {
            k++;
            t.push_back(i);
        }
    } 
    
    sort(t.begin(), t.end());
    cout << k << "\n";
    for (auto p: t) {
        cout << p << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

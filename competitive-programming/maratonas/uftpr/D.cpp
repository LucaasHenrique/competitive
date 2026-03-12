#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n, m, l;
    
    vector<ll> f(m);
    vector<ll> tyc(n);

    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> tyc[i];
    }

    int i = 0, j = l - 1;

    ll sum = 0;
    while (i <= j) {
        sum += f[tyc[i] - 1];
        i++;
    }

    cout << sum;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

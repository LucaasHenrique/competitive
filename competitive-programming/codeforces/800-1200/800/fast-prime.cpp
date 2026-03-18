#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    ll n; cin >> n;

    for (int i = 0; i < n; i++) {
       ll x; cin >> x;

       bool primo = true;

       for (ll k = 2; k*k <= x; k++) {
           if (x % k == 0) {
               primo = false;
           }
       }

       if (primo) cout << "prime" << '\n';
       else cout << "not prime" << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

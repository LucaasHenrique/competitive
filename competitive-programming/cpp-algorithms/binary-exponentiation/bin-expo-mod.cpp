#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }

        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << binpow(50, 2, 3);

    return 0;
}

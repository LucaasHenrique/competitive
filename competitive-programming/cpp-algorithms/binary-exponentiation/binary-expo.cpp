#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

ll binpowr(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpowr(a, b / 2);
    if (b % 2) 
        return res * res * a;
    else 
        return res * res;
}

ll binpow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }

        a = a * a;
        b >>= 1;
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << binpow(50, 2); 

    return 0;
}

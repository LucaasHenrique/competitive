#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (ll i = 0; i < n; i++)
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

bool equalZero(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) return false;
    }

    return true;
}

void solve() {
    
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n & 1) {
        cout << "4" << "\n";
        cout << "1" << ' ' << n - 1 << "\n";
        cout << "1" << ' ' << n - 1 << "\n";
        cout << n - 1 << ' ' << n << "\n";
        cout << n - 1 << ' ' << n << "\n";
    } else {
        cout << "2" << '\n';
        cout << "1" << ' ' << n << "\n";
        cout << "1" << ' ' << n << "\n";
    }
}

// o xor de uma sequncia n, onde n é par, conseguimos igualar todos os elemento em 0 fazendo o xor de todos os elementos duas vezes..

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

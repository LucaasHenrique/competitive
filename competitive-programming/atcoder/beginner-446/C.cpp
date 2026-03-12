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

void solve() {
    int n, d; cin >> n >> d;

    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; cin >> b[i];
    }

    vector<int> stock(100);
    int discarded = 1 + d;
    for (int i = 1; i <= n; i++) {
        stock[i] = a[i];

        int max_stock = 0;
        int pos = 0;
        for (int j = 1; j <= i-1; j++) {
            if (stock[j] > max_stock) {
                max_stock = stock[j];
                pos = j;
            }
        }

        //cout << "i: " << i << " max_stock: " << max_stock << " pos: " << pos << '\n';
        if (max_stock >= b[i]) {
            max_stock -= b[i];
            stock[pos] = max_stock;
            stock[i] = a[i];
        } else if (stock[i-1] < b[i]) {
            stock[i] -= b[i];
        }

        if (i == discarded && i > 1) {
            discarded = i + d;
            stock[i-1] = 0;
        }
    }


   int sum = 0;

   for (int i = 1; i <= n; i++) {
        sum += stock[i];
   }

   cout << (sum >= 0 ? sum : 0) << '\n';
}

int main (int argc, char *argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}

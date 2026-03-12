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

int digit_sum(int k) {
    int sum = 0;
    while (k > 0) {
        sum += k % 10;
        k /= 10;
    }

    return sum;
}

void solve() {
    
    int n, k; cin >> n >> k;

    int c =0;
    for (int i = k; i <= n; i++) {
        if (digit_sum(i) == k){
            c++;
        }       
    }

    cout << c << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

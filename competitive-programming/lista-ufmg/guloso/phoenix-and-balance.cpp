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

   int n; cin >> n; 
    
   vector<int> a(n);
   a[0] = 2;
   for (int i = 1; i < n; i++) a[i] = a[i-1] * 2;

   int p1 = a[n-1], p2 = a[n - 2];
   int i = 0, j = n - 3;
    
   while (i < j) {
       p1 += a[i];
       p2 += a[j];
       i++; j--;
   }

   cout << p1 - p2 << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
    return 0;
}

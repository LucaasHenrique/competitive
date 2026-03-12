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
#define maxn 300100

void solve() {
    int n, x; cin >> n >> x;

    vector<int> a(n+1);
    vector<int> vet(maxn+1); 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vet[a[i]] = i;
    }

    int i = 1, j = n;
    int r = 0, r1 = 0;
    sort(a.begin(), a.end());
    while (i < a.size() && j > 1) {
        if (a[i] + a[j] == x) {
            cout << vet[a[i]] << " " << vet[a[j]] << "\n";
            return;
        }   
        j--; i++;
    }

    cout << "IMPOSSIBLE" << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

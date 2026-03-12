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
    int n, m, k; cin >> n >> m >> k;

    vector<int> dsize(n);
    vector<int> sizes(m);

    for (int i = 0; i < n; i++) cin >> dsize[i];
    for (int i = 0; i < m; i++) cin >> sizes[i];

    sort(dsize.begin(), dsize.end());
    sort(sizes.begin(), sizes.end());

    int i = 0, j = 0, c = 0;
    while (i < dsize.size() && j < sizes.size()) {
        if (abs(sizes[j] - dsize[i]) <= k) {c++, i++; j++;}
        else if (sizes[j] < dsize[i]) j++;
        else i++;
    }

    cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

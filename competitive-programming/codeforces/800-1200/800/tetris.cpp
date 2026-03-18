#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n, m; cin >> n >> m;
    
    int tot = 0;
    vector<int> vet(n);

    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        vet[a-1]++;
    }
    
    cout << *min_element(vet.begin(), vet.end()); 
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}

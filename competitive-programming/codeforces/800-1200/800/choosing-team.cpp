#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    
    sort(a.begin(), a.end());
    int c = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (5 - a[i] >= k) {
            c++;   
        }

        if (c == 3) {
            t++;
            c = 0;
        } 
    }

    cout << t << '\n';
}


int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

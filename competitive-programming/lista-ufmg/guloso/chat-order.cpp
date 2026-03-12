#include <bits/stdc++.h>
#include <deque>

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
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    set<string> log;
    for (int i = n-1; i >= 0; i--) {
        if (!log.count(a[i])) cout << a[i] << "\n";
        log.insert(a[i]);
    }
}

// darya, ekaterina, maria, alina -> ekaterina, darya, maria, alina -> maria, ekateriana, darya, alina -> alina, maria, ekaterina,darya; 

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve(){

    int h, m, s, t1, t2; cin >> h >> m >> s >> t1 >> t2;

    int ans = 0;
    
    if (t1 > t2) swap(t1, t2);
    if (h >= t1 && h < t2) ans++;
    if (m >= t1*5 && m < t2*5) ans++;
    if (s >= t1*5 && s < t2*5) ans++;

    if (ans == 0 || ans == 3) cout << "YES";
    else cout << "NO";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}

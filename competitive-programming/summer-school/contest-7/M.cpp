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
    string t, s; cin >> t >> s;

    //reverse(t.begin(), t.end());

    int i = 0, j = t.size()-1;
    int c = 0; string sub = "";
    while (i <= s.size() && s[i] == t[i]) i++;
    while (j >= 0 && s[j] == t[j]) j--;
    
    reverse(t.begin() + i, t.begin() + j + 1);
    
    cout << (t == s  ? "YES" : "NO");
}

// abvcedfba
// abvdecfba
// YES
// abvdcefba
// abvcedfba
// YES
// ahvgdefbf
// ahvgfdebf
// NO
int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

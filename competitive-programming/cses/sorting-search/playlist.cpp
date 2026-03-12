#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll songs[n];

    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }
    
    ll l = 0;
    umap<ll, ll> mp;
    ll r = 0;
    for (ll i = 0; i < n; i++) {
        if (mp.find(songs[i]) != mp.end()) {
            l = max(l, mp[songs[i]] + 1);
        } 
        mp[songs[i]] = i;
        r = max(r, i - l + 1);
    }

    cout << r << "\n";
    return 0;
}

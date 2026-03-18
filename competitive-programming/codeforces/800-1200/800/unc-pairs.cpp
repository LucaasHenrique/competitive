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
#define maxn 1e9 

int t, n;

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> t;
    while (t--) {
        vector<ll> ar;
        cin >> n;
        while (n--) {
            ll a; cin >> a;
            ar.push_back(a);
        }   

        sort(ar.begin(), ar.end());
        
        int l = 0, r = 1;

        ll diff =  0;
        while (l < ar.size() && r < ar.size()) {
            ll sum = abs(ar[l] - ar[r]);
            if (sum > diff) {
                diff = sum;
            }

            r += 2; l += 2;
        }
    
        cout << diff << "\n";
    }
    

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, n;
    string t, s;

    cin >> q;

    while (q--) {
        cin >> n;

        cin >> t >> s;

        map<char, int> ts;
        map<char, int> st;

        string resp = "NO";

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < n; i++) {
            ts[t[i]]++;
            st[s[i]]++;
        }
        
        if (ts == st) resp = "YES";
        cout << resp << "\n";
    }

    return 0;
}

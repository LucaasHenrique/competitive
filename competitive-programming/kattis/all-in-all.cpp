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

    string s, t;
    while (cin >> s >> t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }

        if (i == s.length()) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }


    return 0;
}

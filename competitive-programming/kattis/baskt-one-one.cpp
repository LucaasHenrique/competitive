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


    string s; cin >> s;

    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == 'A') {
            a += s[i+1] - '0';
        } else b += s[i+1] - '0';
    }

    cout << (a > b ? 'A' : 'B');
    return 0;
}

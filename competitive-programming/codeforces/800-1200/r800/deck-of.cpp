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

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        char ch[n];

        int topi = 0, bi = n - 1;
        deque<int> d;
        for (int i = 1; i <= n; i++) d.push_back(i);

        string op;
        cin >> op;

        if (op.length() > k) break;

        for (int i = 0; i < n; ++i) ch[i] = '+';

        for (char s: op) {
            if (s == '0') ch[topi++] = '-';
            else if (s == '1') ch[bi--] = '-'; 
        }

        for (char s: op) {
            if (s == '2') {
                ch[topi++] = '?';
                ch[bi--] = '?';
            } else if (s == '2' && n == 1) {
                ch[topi++] = '-';
            }
        }
    
        for (char c: ch) {
            cout << c;
        } 
        cout << "\n";
    }

    return 0;
}

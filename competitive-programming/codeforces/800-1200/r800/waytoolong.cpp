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

string waytoolong(string s) {
    
    int comp = ((s.length() - 2) - 1) + 1;
    string sub = s.substr(1, comp);

    return s[0] + to_string(sub.length()) + s[s.length() - 1];
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    while (n--) {
        string s; cin >> s;
        
        if (s.length() > 10) {
            cout << waytoolong(s) << "\n";        
        } else cout << s << "\n";
    }

    return 0;
}

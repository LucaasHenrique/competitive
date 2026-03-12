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

int soma (string s) {
    int i = 0;
    string a = "";
    int num = 0;
    while (i < s.size()) {
        if (s[i] == '+') {
            num += stoi(a);
            a = "";
        } else {
            a += s[i];
        }

        i++;

    }

    if (!a.empty()) {
        num += stoi(a);
    }

    return num;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    while (n--) {
        string s; cin >> s;

        if (s == "P=NP") cout << "skipped" << '\n';
        else {
            cout << soma(s) << "\n"; 
        }
    }

    return 0;
}

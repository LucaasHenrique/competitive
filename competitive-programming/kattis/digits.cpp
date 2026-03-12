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
    
int countDigits(int x) {
    return x == 0 ? 1 : (int)log10(abs(x)) + 1;
}

int recurrence(string s) {
    int i = 1, at, ant = 0;

    if (s == "1") return i;
    
    at = s.length();
    while (true) {
        if (at == ant) {
            return i; 
        }
        
        ant = at;
        at = countDigits(at);
        i++;
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        string s; cin >> s;

        if (s == "END") break;
        cout << recurrence(s) << "\n";
    }

    return 0;
}

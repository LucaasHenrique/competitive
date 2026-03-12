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

string reverse(string s) {
    int i = 0, j = s.length() - 1;
    string x; 
    while (i < j) {
        swap(s[i], s[j]); 
        
        i++;
        j--;
    }

    return s;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    cin >> x >> y;

    if (x[2] > y[2]) {
        cout << reverse(x);
    } else if (y[2] > x[2]) {
        cout << reverse(x);
    } else {
        cout << reverse(y);
    }

    return 0;
}

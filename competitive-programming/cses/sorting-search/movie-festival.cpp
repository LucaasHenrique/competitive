#include <bits/stdc++.h>

using namespace std;

#define ll long long 

struct movie {
    int s;
    int e;
};

bool cmp (movie x, movie y) {return x.e < y.e;} 

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<movie> m;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        m.push_back({x, y});
    }

    sort(m.begin(), m.end(), cmp);
    int livre = 0;
    int c = 0;

    for (int i = 0; i < n; i++) {
        movie e = m[i];

        if (e.s >= livre) {
            livre = e.e;
            c++;
        }
    }
    
    cout << c << "\n";

    return 0;
}

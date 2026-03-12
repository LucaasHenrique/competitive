#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int h, w, n; cin >> h >> w >> n;

    vector<vector<int>> mat(h, vector<int>(w));

    vector<int> max;
    vector<int> vet(n);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            cin >> mat[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    
    for (int i = 0; i < h; i++) {
        int c = 0;

        for (int j = 0; j < w; j++) {
            for (int k = 0; k < vet.size(); k++) {
                if (mat[i][j] == vet[k]) {
                    c++;
                    break;
                }
            }
        }

        max.push_back(c);
    }   
    
    cout << *max_element(max.begin(), max.end()) << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

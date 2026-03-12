#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
   
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, Q;    
    int c = 1;
    while (true) {
        cin >> N >> Q;
    
        if (N == 0 && Q == 0) {
            break;
        }

        vector<int> l;

        for (int i = 0; i < N; i++) {
            int n; cin >> n; l.push_back(n);
        } 

        sort(l.begin(), l.end());

        cout << "CASE# " << c++ << ":" << endl;

        for (int i = 0; i < Q; i++) { 
            int n; cin >> n;
                    
            auto it = lower_bound(l.begin(), l.end(), n);
            
            if (it != l.end() && *it == n) cout << n << " found at " << (it - l.begin() + 1) << "\n";
            else cout << n << " not found\n";
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

using std::vector;
using std::cout;


int32_t main() {
    int n = 4;
    vector<int> p;
    for (int i = 1; i <= n; i++) p.push_back(i);
    
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) subset.push_back(p[i]);
        }

        cout << "{";
        for (int x: subset) cout << x << " ";
        cout << "}";

        cout << "\n";
    }
    return 0;
}

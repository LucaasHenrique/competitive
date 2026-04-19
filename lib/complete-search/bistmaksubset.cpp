#include <iostream>
#include <vector>

using std::vector;
using std::cout;


int32_t main() {
    int n = 5; 
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) subset.push_back(i);
        }

        cout << "{";
        for (int x: subset) cout << x << " ";
        cout << "}";

        cout << "\n";
    }
    return 0;
}

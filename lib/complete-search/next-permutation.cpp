#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::next_permutation;

int32_t main () {
    
    vector<int> permutation;

    int n = 5; permutation = {2, 1, 0,3,0};
    //for (int i = 0; i < n; i++) permutation.push_back(i);

    do {
        cout << "{";
        for (auto x: permutation) cout << x << " ";
        cout << "}";
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));

    return 0;
}

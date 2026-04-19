#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int n;
vector<int> permutation;
vector<bool> chosen(1000);

void search() {
    
    if (permutation.size() == n) {
        cout << "{";
        for (int x : permutation) cout << x << " ";
        cout << "}";
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int32_t main () {
    n = 3;
    search();
    return 0;
}

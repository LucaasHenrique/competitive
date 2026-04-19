#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int n;
vector<int> subset;

void search(int k) {
    if (k == n) {
        cout << "{ ";
        for (int x: subset) cout << x << " ";
        cout << "}";
    } else {
        search(k+1); // não incluir k
        subset.push_back(k);
        search(k+1); // incluir k
        subset.pop_back(); // desfaz - backtrack
    }
}

int32_t main () {
   
    n = 3;
    search(0);
    return 0;
}

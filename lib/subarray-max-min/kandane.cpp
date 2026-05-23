#include <iostream> 
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::max;

void solve() {
    
    vector<int> a = {-2, 3, -1, 5};
    int ans = a[0], sum = 0;

    for (int r = 0; r < a.size(); ++r) {
        sum += a[r];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }    

    cout << ans << "\n";
}

int32_t main () {
    solve();
}

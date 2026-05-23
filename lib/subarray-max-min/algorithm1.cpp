#include <iostream> 
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::min;
using std::max;

void solve() {
    
    vector<int> a = {-2, 3, -1, 5};
    int ans = a[0], sum = 0, min_sum = 0;

    for (int r = 0; r < a.size(); ++r) {
        sum += a[r];
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }    

    cout << ans << "\n";
}

int32_t main () {
    solve();
}

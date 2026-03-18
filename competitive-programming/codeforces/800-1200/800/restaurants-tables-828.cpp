#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

// que tipo de grupo entrou?
// existe mesa para esse grupo?

void solve(){
    int n, a, b; cin >> n >> a >> b;
   
    int tot = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        
        if (e == 1 && a >= 1) a--;
        else if (e == 1 && b >= 1) {b--; c++;}
        else if (e == 1 && b < 1 && a < 1 && c >= 1) c--;
        else if (e == 1 && b < 1 && a < 1 && c < 1) tot++;

        if (e == 2 && b >= 1) {
            b--;
        } else if (e == 2 && b <= 1) tot += 2;
    }

    cout << tot;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

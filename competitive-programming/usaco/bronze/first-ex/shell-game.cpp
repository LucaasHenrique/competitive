#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream arq("shell.txt");
    int n;

    arq >> n;

    vector<int> shell_at_pos(n);
    vector<int> c(3, 0);
	for (int i = 0; i < 3; i++) { shell_at_pos[i] = i; }
    
    for (int  i = 0; i < n; i++) {
        int a, b, g;
        arq >> a >> b >> g;
        a--, b--, g--;
        swap(shell_at_pos[a], shell_at_pos[b]);
        
        c[shell_at_pos[g]]++;
    }
    
    cout << max({c[0], c[1], c[2]});
    return 0;
}

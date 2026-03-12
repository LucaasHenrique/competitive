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
    
    //ifstream cin("promote.in");
    //ofstream cout("promote.out");

    int bb, ba, sb, sa, gb, ga, pb, pa;
    cin >> bb >> ba >> sb >> sa >> gb >> ga >> pb >> pa;

    cout << (pa + ga + sa) - (pb + gb + sb) << "\n";
    cout << (pa + ga) - (pb + gb) << "\n";
    cout << (pa) - (pb);

    return 0;
}

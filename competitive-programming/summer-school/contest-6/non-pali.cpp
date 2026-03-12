#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100

int isPalindrome(string & s, int left=0){
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}


void solve() {
    
    string s; cin >> s;
    string t;
    if (isPalindrome(s)) {cout << s; return;} 
    
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isPalindrome(s, i)) {
            pos = i;
            break;
        }
    }
    
    string p = "oi";
    t = s.substr(0, pos);
    reverse(t.begin(), t.end());
    cout << s+t << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

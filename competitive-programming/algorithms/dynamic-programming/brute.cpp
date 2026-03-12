#include <bits/stdc++.h>

using namespace std;

using namespace std;

const int maxn = 100000;
#define ll long long

int dp[maxn];
bool mark[maxn];

int solve(int i, int n, bool l) {
    
     if (i == n) return 1;
     if (i > n) return 0;
    
     if (mark[i] && l == false) return dp[i];
        
     int ans = 0;
     if (l) {
        ans = solve(i+1, n, true);    
     }
     else ans = solve(i + 1, n, false) + solve(i + 2, n, true); 

     
     mark[i] = 1;
     dp[i] = ans;
     return ans;
}

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", solve(0, n, false));
}

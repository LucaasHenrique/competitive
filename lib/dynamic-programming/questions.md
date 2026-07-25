# Questions
***

1. Book Shop

```
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
```

1. A solução é apenas uma implementação classica de um knapsack 0-1: 

```c++
void solve() {
    
    int n, x; cin >> n >> x;
 
    ll dp[x+1];
 
    vector<int> books(n);
    vector<int> pages(n);
        
    for (int i = 0; i < n; i++) {
        cin >> books[i]; 
    }
    
    for (int i = 0; i < n; i++) {
        cin >> pages[i]; 
    }
 
    memset(dp, 0, sizeof dp);
    
    for (int i = 0; i < n; i++) {
        for (int p = x; p >= books[i]; p--) {
            dp[p] = max(dp[p], dp[p - books[i]] + pages[i]); 
        }
    }
    
    cout << dp[x] << "\n";
}
```

2. Grid Path

```
Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
```

Solution:

1. Considerando a posição (y, x), quantos caminhos chegam ate essa posição? 
2. Se um caminho que chega em (y, x) vem da posição (0, 0) ele é considerado valido
3. Faça a soma de todos os caminhos que chegam em (y, x)

```c++
vector<string> g(MAXN);
ll dp[MAXN+4][MAXN+4];
const ll MOD = 1e9 + 7;
 
ll solve(int y, int x) {
    
    if (x < 0 || y < 0 || g[y][x] == '*') return 0;
    if (y == 0 && x == 0) return 1;
    if (dp[y][x] != -1) return dp[y][x];
 
    dp[y][x] = (solve(y - 1, x) + solve(y, x - 1)) % MOD;
 
    return dp[y][x];
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    forn (i, n) {
        cin >> g[i]; 
    }
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        if (g[i][0] == '*') break;
        dp[i][0] = 1;
    }
    
    
    for (int i = 0; i < n; i++) {
        if (g[0][i] == '*') break;
        dp[0][i] = 1;
    }
    
    cout << solve(n - 1, n - 1) << "\n";
 
    return 0;
}
```

ou bottom up: 

```c++
vector<string> g(MAXN);
ll dp[MAXN+4][MAXN+4];
const ll MOD = 1e9 + 7;
int n;
 
ll solve(int y, int x) {
    for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
        if (g[i][j] == '*') {
            dp[i][j] = 0;
            continue;
        }
 
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    }
}
 
    return dp[y-1][x-1];
}
```

3. Removing Digits

```
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
```

1. Qual o menor numero de passos para sair de N para 0?
2. Qual o numero de passos para sair de N - 1 para 0?
3. Itere sobre todos os valores de 1 ate N, calculando os passos necessarios

```c++  
ll solve(int n) {
    //if (n < 0) return 0;
    vector<ll> dp(n+1, INF32);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int nu = i;
        while (nu > 0) {
            int d = nu % 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
            nu /= 10;
        }
    }
    return dp[n];
}
```

ou top down:

```c++
nt dp[MAXN+4];
bool vis[MAXN];
 
int solve(int n) {
    //if (n < 0) return 0;
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
 
    dp[n] = INF32;
    int t = n;
    while (t > 0) {
        int d = t % 10;
        if (d) dp[n] = min(dp[n], solve(n - d) + 1);
        t /= 10;
    }
 
    return dp[n];
}
```

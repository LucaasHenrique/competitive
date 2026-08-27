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
***

```
Given an a x b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
```

approach:

1. Temos um retangulo a * b 
2. O retangulo pode ser cortado tanto na vertical quanto na horizontal, quando cortado novos retangulos ou quadrados são gerados.
3. Quando um novo retangulo é gerado temos que descobrir o quantidade de cortes para gerar todos os quadrados, assim definimos o subproblema.
4. Estado: Definimos o estado `dp[a][b]` => numero minimo de cortes para gerar todos os quadrados no retangulo a * b;
5. Então podemos iterar sobre todas as possiblidades de cortes e pegar a minima possivel.
6. Com a possiblidade de cortes horizontais e verticais definimos a recorrencia como:

cortes verticais  => `dp[i][j] = min(dp[i][j], dp[i][j - x] + dp[i][x] + 1)`, onde x é o tamanho do corte.

cortes horizontal  => `dp[i][j] = min(dp[i][j], dp[i - x][j] + dp[x][j] + 1)`, onde x é o tamanho do corte.

```c++
void solve() {
    int a, b; cin >> a >> b;
    
    int dp[a+1][b+1];

    memset(dp, INF, sizeof dp);
    
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            // horizontal
            for (int k = 1; k <= i - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            } 
            //vertical
            for (int k = 1; k <= j - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    cout << dp[a][b] << '\n';
}
```
***

```
Your task is to count the number of ways numbers 1,2,...,n can be divided into two sets of equal sum.
```
1. calculamos a soma de todos os números `S = 1 + 2 + ... + n`; se `S` for ímpar, não é possível dividi-la igualmente entre dois conjuntos, então a resposta é `0`.

2. dividimos a soma por `2`, pois queremos encontrar dois conjuntos cuja soma seja `S / 2`.

3. então nossa resposta será a quantidade de subconjuntos cuja soma é igual a `S / 2`.

4. definimos o estado da DP como:

```cpp
dp[x] => número de maneiras de formar a soma x.
```

5. se utilizássemos todos os números `1...n`, cada divisão seria contada duas vezes (um conjunto e seu complemento). Para evitar isso, fixamos o número `n` em um dos conjuntos e fazemos a DP apenas com os números `1...n-1`.

```c++
const ll MOD = 1e9 + 7;

void solve() {
    
    int n; cin >> n;

    ll s = n * (n + 1) / 2;
    if (s&1) {
        cout << 0 << '\n';
        return;
    }

    ll target = s / 2;
    
    ll dp[target+1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << dp[target]<< "\n";
}
```
***

Removal Game => 

```
There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?
```

input => 
```
4 
4 5 1 3
```

output => `8`

[interval dp, difference dp]

1. Se temos um array `[4, 5, 1, 3]` que elemento devemos pegar primeiro? o maior entre 3 e 4?
2. Essa abordagem gulosa não necessariamente leva o melhor resultado 
3. Se voce considerar o intervalo `a[L...R]` vai perceber q temos duas escolhas:

pegar `a[L]`
pegar `a[R]`

apos sua escolha seu oponente vai jogar de forma otima.
4. A solução da questão vai ser pensar na vantagem que voce consegue obter encima de seu oponente.
5. definimos o estado `dp[l][r]` => a maior diferenca de pontos que conseguimos obter (current plauyer - other player) no intervalo `[L, R]`
6. Caso base: se resta apenas um numero, pegamos ele, então `dp[i][i] = a[i]`
7. `dp[l][r]` não guarda a resposta final apenas a diferenca entre os jogadores, para obter a resposta final fazemos:

sabemos q cada numero é escolhido apenas uma vez logo:

first + second = total_sum

a difenca entre os jogadores é:

first - second = x;

ou seja, duas equações:

total = 19
x = 5;

first + second = 19
first - second = 5 

2 * first = 24 
first = 12

```c++
int main() {
    int n;
    cin >> n;

    vector<ll> a(n);

    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n));

    // Base case
    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];

    // Interval length
    for (int len = 2; len <= n; len++) {

        for (int l = 0; l + len - 1 < n; l++) {

            int r = l + len - 1;

            dp[l][r] = max(
                a[l] - dp[l + 1][r],
                a[r] - dp[l][r - 1]
            );
        }
    }

    ll answer = (total + dp[0][n - 1]) / 2;

    cout << answer << '\n';
}
```
Elevator Rides =>

dp bitmask problem

```
There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides?
```

input and output => 
```
4 10
4 8 6 1 

2
```

approach:

1. Podemos usar uma mascara de bits (1011) para representar cada viagem 

cada bit ligado significa que a pessoa na posição foi levado na viagem

2. Com isso iteramos sobre todos os subconjuntos possiveis, cada subconjunto representa uma forma de viagem 

geramos os subconjuntos com 2^N 

3. Definimos o estado da `dp[mask] = {numero de viagens, ultimo peso total da ultima viagem}`
4. Para cada pessoa de 1 a N verificamos:

verificamos se a pessoa ja esta na viagem:
    se não:
        verificamos se o peso da viagem + o peso da pessoa <= a capacidade do elevador: 
            se sim: 
                colocamos a pessoa nessa viagem e somamos o peso total
            se não: 
                uma nova viagem deve ser feita

5. Criamos uma nova mask incluindo a nova pessoa 
6. O resultado final é:
    `dp[new_mask] = min(dp[new_mask], mask_atual)`


```c++
void solve() {
    
    int n; cin >> n;
    ll x; cin >> x;

    vector<ll> w(n);
    forn (i, n) cin >> w[i];

    int tot_mask = 1 << n;
    vector<pair<int, ll>> dp(tot_mask, {n+1, 0});
    dp[0] = {1, 0};

    for (int mask = 0; mask < tot_mask; mask++) {
        
        for (int p = 0; p < n; p++) {
            if ((mask & (1 << p)) == 0) {
                auto atual = dp[mask];

                if (atual.s + w[p] <= x) {
                    atual.s += w[p];
                } else {
                    atual.f++;
                    atual.s = w[p];
                }

                auto new_mask = mask | (1 << p);
                dp[new_mask] = min(dp[new_mask], atual);
            }
        }
    }

    cout << dp[tot_mask - 1].f << "\n";
}
```
***

LCS 

```
You are given strings s and t. Find one longest string that is a subsequence of both s and t.
```

1. queremos maior string que:   
    - aparece em S matendo a ordem
    - aparece em T mantendo a ordem
2. Estado:
    `dp[i][j] => longest commom subsequence usndo os i primeiros elementos de S e os j primeiros elementos de T`
3. Temos dois casos:
    - 1: iguais
        `s[i-1] == t[j-1]`
        adicionamos esse caracter na nossa lcs 
        `dp[i][j] = dp[i-1][j-1] + 1`
    - 2: diferentes
        `s[i-1] != t[j-1]`
        escolhemos um e ignoramos outro:
        `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

```c++
void solve() {
    string s, t; cin >> s >> t;
        
    int n = s.size();
    int m = t.size();

    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans;

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(all(ans));

    cout << ans << "\n";
}
```
***

consecutive subsequence

```
You are given an integer array of length n. You have to choose some subsequence of this array of maximum length such that this subsequence forms a increasing sequence of consecutive integers. In other words the required sequence should be equal to [x,x+1,…,x+k−1] for some value x and length k.
```

1. Para cada elemento x podemos escolher:
    - continuar uma subsequencia que terminou em x - 1;
    - começar uma nova subseqeuncia em x;

```c++

void solve() {
    
    int n; cin >> n;
    vector<ll> a(n);
    
    forn (i, n) cin >> a[i];
    
    map<int, int> dp; // longest subseqe ends on value x;
    
    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        dp[x] = dp[x-1] + 1;

        if (ans < dp[x]) {
            ans = dp[x];
            last = x;
        }
    }

    vector<int> answer;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == last) {
            answer.pb(i);
            last--;
        }
    }   

    reverse(all(answer));
    
    cout << answer.size() << "\n";
    for (auto x: answer) cout << x + 1 << " ";

    cout << "\n";
}

```

``` 
Vladik often travels by trains. He remembered some of his trips especially well and I would like to tell you about one of these trips:

Vladik is at initial train station, and now n people (including Vladik) want to get on the train. They are already lined up in some order, and for each of them the city code ai is known (the code of the city in which they are going to).

Train chief selects some number of disjoint segments of the original sequence of people (covering entire sequence by segments is not necessary). People who are in the same segment will be in the same train carriage. The segments are selected in such way that if at least one person travels to the city x, then all people who are going to city x should be in the same railway carriage. This means that they can’t belong to different segments. Note, that all people who travel to the city x, either go to it and in the same railway carriage, or do not go anywhere at all.

Comfort of a train trip with people on segment from position l to position r is equal to XOR of all distinct codes of cities for people on the segment from position l to position r. XOR operation also known as exclusive OR.

Total comfort of a train trip is equal to sum of comfort for each segment.

Help Vladik to know maximal possible total comfort.
```

1. um vagão só é valido se todo mundo que vai para a cidade x estão nele.
    `a = [1, 3, 2, 5, 2, 7]` => `[2, 5, 2]` é valido.
2. para toda cidade x podemos armazenar:
    `first[x]` => primeira ocorrencia dessa cidade no array.
    `last[x]` => ultim ocorrencia dessa cidade no array 

    e temos que para um vagão ser valido:

    `L <= first[x] and last[x] <= R`, ou seja todo mundo que vai para cidade x tem q estar contido no intervalo `[l, r]`;
3. definimos a dp como:
    `dp[i]` => maior conforto usando as i primeiras pessoas.
4. testaremos todos os intervalos, em cada teste guardamos a menor o ocorrencia da cidade e a maior ocorrencia da cidade x em termo de posição.
5. Para cada cidade q ainda não apareceu fazemos o curr ^= x;
6. Para cada estado temos duas possibilidades: 
    1. A pessoa nao entra em nenhum vagão => `dp[r] = dp[r-1]`

    2. Existe um vagão terminando em i, ou seja, um vagão valido no intervalo `[l, r]` => `dp[r] = max(dp[r], dp[l-1] + curr)`;

```c++
void solve() {
    int n; cin >> n;
 
    vector<int> a(n+1);
    const int m = 5000;
    
    vector<int> first(m+1, n+1);
    vector<int> last(m+1);
 
    for (int i = 1; i<= n; i++) {
        cin >> a[i];
 
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = i;
    }
 
    int dp[n+1];
    memset(dp, 0, sizeof dp);
 
    for (int r = 1; r <= n; r++) {
        dp[r] = dp[r-1];
        vector<bool> used(m+1, 0);
 
        int mfirst = n + 1, mlast = 0, cur = 0;
 
        for (int l = r; l >= 1; l--) {
            
            int x = a[l];
 
            if (!used[x])  {
                used[x] = 1;
                cur ^= x;
 
                mfirst = min(mfirst, first[x]);
                mlast = max(mlast, last[x]);
            }
 
            if (mfirst >= l && mlast <= r) {
                dp[r] = max(dp[r], dp[l-1] + cur);
            }
        }
    }
 
    cout << dp[n] << "\n";
}
```

caesar legions:

```
Gaius Julius Caesar, a famous general, loved to line up his soldiers. Overall the army had n1 footmen and n2 horsemen. Caesar thought that an arrangement is not beautiful if somewhere in the line there are strictly more that k1 footmen standing successively one after another, or there are strictly more than k2 horsemen standing successively one after another. Find the number of beautiful arrangements of the soldiers.

Note that all n1 + n2 warriors should be present at each arrangement. All footmen are considered indistinguishable among themselves. Similarly, all horsemen are considered indistinguishable among themselves.
```

1. considere que temos a string `FFHHF` o que precisamos saber para adiconar a proxima letra?
    1. quem foi o ultimo tipo letra adicionada, qual sequencia consecutiva que essa letra apareceu, o quanto ainda resta dessa letra para ser adicionada.
2. Definimos nossa dp como, `dp[f][h][t][c]` => quantidade de sequencias validas usando F footmen, H horseman, sabendo que o ultimo char foi do tipo T (H, F) e existe uma sequencia consequitiva de tamanho C do tipo T;
3. Temos as possibilidades:
    Ultimo igual F:
        1. adicione F se C < K1 e F < N1;
        2. adicione H se H < N2;
    Ultimo igual H:
        1. adicione H se C < K2 e H < N2;
        2. adicione F se F < N1;

```c++
const int MOD = 1e8;
int dp[101][101][2][11];
 
void solve() {
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    
    dp[1][0][0][1] = 1;
    dp[0][1][1][1] = 1;
 
    for (int f = 0; f <= n1; f++) {
        for (int h = 0; h <= n2; h++) {
            for (int c = 1; c <= 10; c++) {
                
                if (dp[f][h][0][c] != 0) {
                    
                    if (f < n1 && c < k1) {
                        dp[f+1][h][0][c + 1] += dp[f][h][0][c];
                        dp[f+1][h][0][c+1] %= MOD;
                    }  
 
                    if (h < n2) {
                        dp[f][h+1][1][1] += dp[f][h][0][c];
                        dp[f][h+1][1][1] %= MOD;
                    }
                }
 
                if (dp[f][h][1][c] != 0) {
                    if (h < n2 && c < k2) {
                        dp[f][h+1][1][c+1] += dp[f][h][1][c];
                        dp[f][h+1][1][c+1] %= MOD;
                    }
 
                    if (f < n1) {
                        dp[f+1][h][0][1] += dp[f][h][1][c];
                        dp[f+1][h][0][1] %= MOD;
                    }
                }
            }
        } 
    }
    
    int ans = 0;
    for (int c = 1; c <= k1; c++) {
        ans += dp[n1][n2][0][c];
        ans %= MOD;
    }
    
    for (int c = 1; c <= k2; c++) {
        ans += dp[n1][n2][1][c];
        ans %= MOD;
    }
 
    cout << ans << "\n";
}
```

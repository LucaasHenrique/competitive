# Subarrays

temos um array e queremos saber todas os subarrays que contem a soma == x.

calculamos o prefix sums do array

se em determinado prefixo a soma é igual a x, para saber quais subarray contribuem para essa soma basta fazer:

y = Pi - x;

se existir um prefix com soma igual a y, então esse prefixo contribui para o prefixo com soma igual a x. Assim, basta somar a frequencia de todos os prefixos com soma igual a y;

exemplo:

```c++

void solve() {

    int n; cin >> n;

    ll x; cin >> x;
    vector<ll> a(n);

    forn (i, n) cin >> a[i];
    map<ll, ll> pref;
    pref[0] = 1;

    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];

        ans += pref[sum - x];
        pref[sum]++;
    }

    cout << ans << "\n";
}
```
***

A logica acima tbm é valida para quando queremos contar todos os subarray que contem soma divisivel por N;

calculamos o prefx sums do array.

Sabemos que para o prefixo em Pi ser divisivel por N a condição `Pi % N == 0` tem que ser verdade, podemos rescrever essa codição como `Pi = N*k + r`, onde `r` é o resto da divisão de Pi por N.

Se em determindo momento a soma é divisivel por N, podemos contar quantos subarray contribuem para isso.

Pj -> prefixos anteriores.

`x = Pi - Pj`;

onde `Pj = N*k' + r`;

temos que:

`x = N * (k - k')` -> logo, x é um multiplo de N;

Com isso podemos contar todos os prefixos em que: 

`Pi MOD N = Pj MOD N`;

exemplo: 
```c++

void solve() {
    
    int n; cin >> n;
    vector<ll> a(n);

    forn (i, n) cin >> a[i];
    
    map<ll, ll> psums;
    psums[0] = 1;

    ll c_rr = 0;
    ll tot = 0;
    
    for (int i = 0; i < n; i++) {
        c_rr += a[i];
        ll mod = (c_rr % n + n) % n;

        tot += psums[mod];
        psums[mod]++;
    }

    cout << tot << "\n";
}
```

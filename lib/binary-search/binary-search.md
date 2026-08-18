# Binary Search
***

Quando temos um array ordenado, podemos usar a técnica de `Binary Search` para buscar um elemento em `O(log N)`.

A ideia principal é dividir o intervalo de busca pela metade a cada passo.

## Método básico

```cpp
int a = 0, b = n - 1;

while (a <= b) {
    int mid = (a + b) / 2;

    if (array[mid] == x) {
        // achamos o elemento x na posição mid
    }
    if (array[mid] > x)
        b = mid - 1;
    else
        a = mid + 1;
}
```

## Como funciona?

A cada iteração:

- Calculamos o elemento do meio:

```cpp
mid = (a + b) / 2;
```

- Se `array[mid] == x`, encontramos o elemento.
- Se `array[mid] > x`, então o valor procurado está na metade esquerda.
- Se `array[mid] < x`, então o valor procurado está na metade direita.

Ou seja:

- Procuramos na faixa `[a, mid - 1]` quando o valor do meio é maior que `x`.
- Procuramos na faixa `[mid + 1, b]` quando o valor do meio é menor que `x`.

Como o intervalo é reduzido pela metade a cada passo, a complexidade é:

```text
O(log N)
```

***

## Evitando overflow

Em problemas com números muito grandes, é mais seguro calcular o meio assim:

```cpp
int mid = a + (b - a) / 2;
```

Isso evita overflow de inteiros ao fazer `a + b`.

***

# Funções da STL

A STL possui funções prontas que utilizam `Binary Search`.

⚠️ Todas exigem que o array esteja ordenado.

## lower_bound

```cpp
lower_bound(begin, end, x)
```

Retorna um iterador para o primeiro elemento:

```text
>= x
```

Exemplo:

```cpp
vector<int> v = {1, 2, 2, 2, 4, 5};

auto it = lower_bound(v.begin(), v.end(), 2);
```

`it` apontará para o primeiro `2`.

***

## upper_bound

```cpp
upper_bound(begin, end, x)
```

Retorna um iterador para o primeiro elemento:

```text
> x
```

Exemplo:

```cpp
vector<int> v = {1, 2, 2, 2, 4, 5};

auto it = upper_bound(v.begin(), v.end(), 2);
```

`it` apontará para o `4`.

***

## equal_range

```cpp
equal_range(begin, end, x)
```

Retorna um `pair` contendo:

```text
{lower_bound(x), upper_bound(x)}
```

Ou seja:

- primeiro elemento `>= x`
- primeiro elemento `> x`

Exemplo:

```cpp
vector<int> v = {1, 2, 2, 2, 4, 5};

auto p = equal_range(v.begin(), v.end(), 2);
```

- `p.first` → primeiro `2`
- `p.second` → `4`

***

# Binary Search na resposta

Nem sempre usamos Binary Search para buscar valores diretamente.

Também podemos usar para encontrar a **menor resposta válida** de um problema.

Esse tipo de problema normalmente possui uma propriedade chamada de **monotonicidade**.

## Monotonicidade

Imagine uma função que responde apenas:

```text
true ou false
```

Se existir um ponto onde:

```text
false false false true true true
```

ou:

```text
true true true false false false
```

então podemos usar Binary Search.

Isso acontece porque, depois de certo ponto, a resposta nunca mais muda.

***

# Find the Smallest Solution

Exemplo:

Dado um array ordenado:

```text
[1, 2, 3, 4, 5, 6, 7, 8, 9]
```

Queremos encontrar o menor elemento maior que:

```text
x = 5
```

Se analisarmos elemento por elemento:

```text
1 -> false
2 -> false
3 -> false
4 -> false
5 -> false
6 -> true
7 -> true
8 -> true
9 -> true
```

Podemos representar isso como:

```text
[false, false, false, false, false, true, true, true, true]
```

Observe que:

- antes da resposta → `false`
- depois da resposta → `true`

O primeiro `true` é a menor solução válida.

Nesse caso:

```text
6
```

é a resposta.

***

# Find the Maximum Value

Tbm podemos usar para encontrar o maximo valor para uma função que esta em crescimento e depois começa a decrescer, ou seja queremos encontrar o pico dessa função. 

a ideia é ir testando se `f(x) < f(x + 1)` se isso for verdade ainda estamos na subida, se não ou ja chegou no pico ou esta decrescendo.

```c++
int left = 0;
int right = n - 1;

while (left < right) {
    int mid = (left + right) / 2;

    if (f(mid) < f(mid + 1)) {
        // ainda está subindo
        left = mid + 1;
    } else {
        // chegou no pico ou já está descendo
        right = mid;
    }
}

int k = left; // posição do máximo
```

# Exemplo genérico

```cpp
int l = 0, r = n - 1;
int ans = -1;

while (l <= r) {
    int mid = l + (r - l) / 2;

    if (check(mid)) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}
```

Onde:

```cpp
check(mid)
```

é uma função monotônica que retorna:

```text
true ou false
```

- Se `check(mid)` for verdadeiro:
  - guardamos a resposta
  - tentamos encontrar uma solução menor

- Caso contrário:
  - buscamos na direita

***
# Exemplo binary search on answer

```c++

bool is_valid(vector<ll>& a, ll x, ll t) {
    ll sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += x / a[i];
        if (sum >= t) return true;
    }

    return sum >= t;
}

void solve() {
    int n; cin >> n;
    ll t; cin >> t;

    vector<ll> a(n);
    forn (i, n) cin >> a[i];

    ll l = 1, r = 1e18;
    ll ans = r;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        
        if (is_valid(a, mid, t)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }

    cout << ans << "\n";
}
```

# Complexidade

A Binary Search reduz o espaço de busca pela metade a cada operação.

Complexidade:

```text
O(log N)
```

Memória:

```text
O(1)
```

question:

```
The organizers of the children's holiday are planning to inflate m balloons for it. They invited nassistants, the i-th assistant inflates a balloon in ti minutes, but every time after zi balloons are inflated he gets tired and rests for yi minutes. Now the organizers of the holiday want to know after what time all the balloons will be inflated with the most optimal work of the assistants, and how many balloons each of them will inflate. (If the assistant has inflated the balloon and needs to rest, but he will not have to inflate more balloons, then it is considered that he finished the work immediately after the end of the last balloon inflation, and not after the rest).

In the first line print the number T, the time it takes for all the balloons to be inflated. On the second line print n numbers, the number of balloons inflated by each of the invited assistants. If there are several optimal answers, output any of them.
```

1. Podemos pensar no ciclo de trabalho para cada assitente;
2. Um ciclo seria a antes de descançar ele pode fazer z balões levando t minutos para cada balão e descançndo y segundos depois da fazer z balões;
    temos a formula fechada: 
        tempo de ciclo tc = t * z + y;
        balões por ciclo bc =  z
3. Com isso sabemos o numero de ciclos completos com:
    numero de ciclos completos c = T / tc, onde t é uma quantidade de tempo chuta na busca binaria
4. Também sabemos o tempo restante com:
    trem = T MOD tc
5. O numero de balões feito por cada assitente é dado por:
    n_t = c * z + min(trem / t);
6. questão da saida do problema:
    - não podemos imprimir o que cada assitente consegue fazer, pois pode ocorrer dessa quantidade ser maior q m;
    - podemos fazer uma distribuição gulosa para achar um quantidade para cada assistente de forma que não supere m;

    temos que: 
        seja rem_m = a quantidade m de baloes que ainda devem ser feitos;
        veja quantos balões ci o assistente pode fazer no tempo t (resposta final);
        pegue o min sem passar da capacidade rem_m => `min(rem_m, ci)`
        imprima a quantidade adequadda do assistenten atual;

```c++
int n;
vector<ll> t_p, t_t, r_t;
// t z y
bool valid(ll t, int m) {
    // ciclo para cada assitente seria
    // tempo de ciclo = t * z * y;
    // balões por ciclo = z;
    // numero de ciclo completo = T / tempo de ciclo
    // tempo restante = T MOD tempo de ciclo
    // numero de balões = numero de ciclo completos * z + min(z, rem / t); 
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll cycle = t_p[i] * t_t[i] + r_t[i];
        ll n_cycles = t / cycle;
        ll trem = t % cycle;
        tot += n_cycles * t_t[i] + min(t_t[i], trem / t_p[i]);
    }

    return tot >= m;
}

ll count_b(ll t, int m, int i) {
    ll cycle = t_p[i] * t_t[i] + r_t[i];
    ll n_cycles = t / cycle;
    ll trem = t % cycle;
    return n_cycles * t_t[i] + min(t_t[i], trem / t_p[i]);
}

void solve() {
    int m; cin >> m >> n;

    t_p.resize(n); t_t.resize(n); r_t.resize(n);
    forn (i, n) {
        cin >> t_p[i] >> t_t[i] >> r_t[i];
    }

    ll l = 0, r = 1e9;
    ll ans = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
    
        if (valid(mid, m)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    ll rem_m = m;

    for (int i = 0; i < n; i++) {
        ll ci = count_b(ans, rem_m, i);
        ll take = min(rem_m, ci);

        cout << take << (i + 1 == n ? "" : " ");
        rem_m -= take;
    }

    cout << "\n";
}
```

# Segment Tree
***

Arvore binaria de consulta;

É uma ds que suporta 2 operações:

- processar uma query em um intervalo
- atualização em um valor do array 

uma segtree pode ter max queries, sum queries, min queries, xor queries e muitos outros tipos de query;

implementation:

Query => O(logN)
update => O(klogN) onde k é o numero de elementos alterados
***

Dado um array a de tamanho n, queremos responder q queries da forma:

dado um intervalo `[l, r]`, qual o valor minimo do subarray `a[l, r]`?

```c++
namespace seg {
    ll seg[4*MAX];
    int n, *v;

    ll build(int p=1, int l=0, int r=n-1) {
        if (l == r) return seg[p] = v[l];

        int m = (l+r)/2;

        return seg[p] = build(2*p, l, m) +
                        build(2*p+1, m+1, r);
    }

    void build(int n2, int *v2) {
        n = n2, v = v2;
        build();
    }

    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        if (b < l || r < a) return 0;

        if (a <= l && r <= b)
            return seg[p];

        int m = (l+r)/2;

        return query(a, b, 2*p, l, m) +
               query(a, b, 2*p+1, m+1, r);
    }

    ll update(int pos, int x, int p=1, int l=0, int r=n-1) {
        if (l == r)
            return seg[p] += x;

        int m = (l+r)/2;

        if (pos <= m)
            update(pos, x, 2*p, l, m);
        else
            update(pos, x, 2*p+1, m+1, r);

        return seg[p] = seg[2*p] + seg[2*p+1];
    }
};
```

# Lazy Propagation

Ajuda fazer atualização de intervalos em O(logN);

ideia é: "Não fazer imediatamento uma atualização que afeta um intervalo inteiro. Guarde essa atualização no nó e śo empurre para os filhos quando necessário"

tenho: `[1, 2, 3, 4, 5, 6, 7, 8]`

queremos atualizar `[2, 7]` somando 10 em cada elemento, dizemos:

```c++
seg[p] += 10 * tamanho_intervalo
lazy[p] = 10;
``` 

todo mundo recebeu 10, mas não iremos atualizar cada filho ainda, guardamos em `lazy[p]`


```c++
namespace seg {
    ll seg[4*MAXN], lazy[4*MAXN];
    int n;
    ll *v;

    ll build(int p=1, int l=0, int r=n-1) {
        lazy[p] = 0;
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    void build(int n2, ll *v2) {
        n = n2, v = v2;
        build();
    }

    void prop(int p, int l, int r) {
        seg[p] += lazy[p]*(r-l+1);
        if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }

    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return 0;
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    ll update(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l and r <= b) {
            lazy[p] += x;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l or r < a) return seg[p];
        int m = (l+r)/2;
        return seg[p] = update(a, b, x, 2*p, l, m) +
                        update(a, b, x, 2*p+1, m+1, r);
    }
};
```


questions:

dado um array a é um numero q de queries, em cada queries responda qual o minimo e sua frequencia no intervalo `[a, b]`;

```c++ 
int v[MAXN];
pair<int, int> seg[4*MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.f < b.f) return a;
    if (b.f < a.f) return b;

    return {a.f, a.s + b.s};
}

pair<int, int> build(int p, int l, int r) {
    if (l == r) return seg[p] = {v[l], 1};
    int m = (l + r) / 2;
    return seg[p] = combine(build(p*2, l, m), build(p*2+1, m+1, r));
}

pair<int, int> query(int a, int b, int p, int l, int r) { 
    if (b < l or r < a) return {INF32, -1};
    if (a <= l and r <= b) return seg[p];

    int m =(l + r) / 2;
    return combine(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

pair<int, int> update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = {x, 1}; 
    
    int m = (l+r) / 2;
    return seg[p] = combine(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

void solve() {

    int n, q; cin >> n >> q; 
    forn (i, n) {
        cin >> v[i];
    }        

    build(1, 0, n-1);
    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            int i, x; cin >> i >> x;
            update(i, x, 1, 0, n-1);
        } else {
            int l, r; cin >> l >> r;
            r--;
            auto [k, v] = query(l, r, 1, 0, n-1);
            cout << k << " " << v << "\n";
        }
    }
}
```
***

quetions 2:

seg + lazy

```
Given an array of n integers, your task is to process q queries of the following types:

1. increase each value in range [a,b] by u
2. what is the value at position k?
```

```c++
#define MAXN 300100
 
ll v[MAXN];
 
namespace seg {
    ll seg[4*MAXN], lazy[4*MAXN];
    int n;
    ll *v;
 
    ll build(int p=1, int l=0, int r=n-1) {
        lazy[p] = 0;
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }
 
    void build(int n2, ll *v2) {
        n = n2, v = v2;
        build();
    }
 
    void prop(int p, int l, int r) {
        seg[p] += lazy[p]*(r-l+1);
        if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }
 
    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return 0;
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }
 
    ll update(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l and r <= b) {
            lazy[p] += x;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l or r < a) return seg[p];
        int m = (l+r)/2;
        return seg[p] = update(a, b, x, 2*p, l, m) +
                        update(a, b, x, 2*p+1, m+1, r);
    }
};
 
void solve() {
    int n, q; cin >> n >> q;
    
    forn (i, n) cin >> v[i];
    
    seg::build(n, v);
    
    while (q--) {
        int t; cin >> t;
 
        if (t == 1) {
            int a, b;
            ll u; cin >> a >> b >> u;
            a--; b--;
            seg::update(a, b, u);
        } else {
            int k; cin >> k; 
            k--;
            cout << seg::query(k, k) << "\n";
        }
    }
}
```

Running a penitentiary

```
The penitentiary at Viana do Castelo is one of the largest ones in Europe. The building has thousands of jail cells, laid out linearly in several levels, and numbered so that adjacent numbers are given to adjacent cells, be it adjacent cells on the same level, or one on top of the other, or connected by an adjacent stairway. It is not really known why, but the jail cells are numbered starting from a negative number, so that cell number zero is right in the middle of the penitentiary, exactly at the center of the middle level of the building. Probably the first warden, who assigned the cells numbering, did this for entertainment …

Each guard in the penitentiary gets an interval of cells to watch. He must go over these cells and check that the inmates did not escape, are doing okay, and so on. The warden does two operations depending on the intervals of cells assigned to each guard:

Given a guard i
, change the interval of cells assigned to him to [ℓ,r]
;
Given an interval of guards [a,b]
, find how many cells are watched by all the guards in this interval at the moment.
Your task in this problem is to read the number N
 of guards in the penitentiary and, for each guard, the interval of cells he is in charge of watching over. Next, you will read the Q
 operations carried out by the warden, by executing an operation of the first type or by answering the query for operations of the second type
```

1. o problema pede que dado um intervalo `[a, b]` qual o maior numero de celulas que são vigiadas por todos os guardas nesse intervalo? basicamente ta pedindo a interseção entre os intervalos de cada guarda.
2. A forma matematica de descobrir essa interseção é:
    pegar o maior L que aparece 
    pegar o menor R que aparece

    agora verificamos se `[L, R]` forma um intervalo valido:

    se L > R => não existe interseção.
    se L == R => existe interseção, exatamente uma celula.
    se L < R => existe interseção, (R - L) + 1 celulas.

3. Para manipulação de forma efieciente criamos uma segment tree que cada Nó guarda o maior L e menor R do intervalo `[a, b]`, cada indice da arvore é um guarda.
4. Em cada query apenas verificamos os casos bases acima.

```c++ 

struct Node {
    ll maxL;
    ll minR;
};

struct Guard {
    ll l, r;
};

Node combine(Node a, Node b) {
    return {
        max(a.maxL, b.maxL),
        min(a.minR, b.minR)
    };
}

Guard v[MAXN];

namespace seg {
    Node seg[4*MAXN];
    int n;
    Guard *v;

    Node build(ll p = 1, ll l = 0, ll r = n - 1) {
        if (l == r) return seg[p] = {v[l].l, v[l].r};

        ll m  = (l + r) / 2;
        return seg[p] = combine(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
    }

    void build(ll n2, Guard *v2) {
        n = n2; v = v2;
        build();
    }

    Node query(ll a, ll b, ll p = 1, ll l = 0, ll r = n - 1) {
        if (b < l || r < a) return {-INF64, INF64};
        
        if (a <= l && r <= b) return seg[p];

        ll m = (l + r) / 2;

        return combine(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
    }

    Node update(int pos, ll newl, ll newr, ll p = 1, ll L = 0, ll R = n - 1) {
        if (L==R) return seg[p] = {newl, newr};

        ll m = (L + R) / 2;

        if (pos <= m) 
            update(pos, newl, newr, 2 * p, L, m);
        else 
            update(pos, newl, newr, 2 * p + 1, m + 1, R);

        return seg[p] = combine(seg[2*p], seg[2*p+1]);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    
    forn (i, n) {
        cin >> v[i].l >> v[i].r; 
    }

    seg::build(n, v);

    while (q--) {
        char c; cin >> c; 
        if (c == 'C') {
            ll i, l, r; cin >> i >> l >> r;
            --i;
            seg::update(i, l, r);
        } else {
            ll a, b; cin >> a >> b;
            --a; --b;
            Node t = seg::query(a, b);

            if (t.maxL == t.minR) cout << 1 << "\n";
            else if (t.maxL < t.minR) cout << (t.minR - t.maxL) + 1 << "\n";
            else if (t.maxL > t.minR) cout << 0 << "\n";
        }
    }
}
```
***

Segment with the maximum sum 

```
you need to write a segment tree to find the segment with the maximum sum.
```

1. Em cada node da seg guardamos 4 informações
2. A soma do intervalo inteiro, a soma do prefix do intervalo, a soma do sufixo do intervalo, e a maior soma que aparece no intervalo.
3. Quando construimos um node temos algumas opções para cada informação do node pai:
    - A soma total do node pai vai ser a soma do node A + node B, seus filhos
    - A soma do prefix do node pai vai pode ser a soma do prefix de A inteiro ou a soma que começa em A e termina no prefix de B, no segundo caso dizemos que a soma a    atravessou o intervalo A e terminou em B.
    - A soma do suffix do node pai pode ser o suffix de B inteiro ou a soma do suffix que começa em A e termina em B.
    - A soma maxima do node pai pode ser: a maior soma A, a maior soma de B ou a soma do suffix que começa em A e termina no prefix de B. 

```c++
struct Node {
    ll sum;
    ll pref;
    ll suff;
    ll maxsum;
};

Node combine(Node A, Node B) {
    Node P;

    P.sum = A.sum + B.sum;

    P.pref = max(A.pref, A.sum + B.pref);

    P.suff = max(B.suff, A.suff + B.sum);

    P.maxsum = max({A.maxsum, B.maxsum, A.suff + B.pref});

    return P;
}

Node mk_node(ll x) {
    return {
        x, max(0LL, x), max(0LL, x), max(0LL, x)
    };
}

namespace seg {
    Node seg[4*MAXN];
    int n;
    ll *v;

    Node build(ll p = 1, ll l = 0, ll r = n - 1) {
        if (l == r) return seg[p] = mk_node(v[l]);

        ll m  = (l + r) / 2;
        return seg[p] = combine(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
    }

    void build(ll n2, ll *v2) {
        n = n2; v = v2;
        build();
    }

    Node query(ll a, ll b, ll p = 1, ll l = 0, ll r = n - 1) {
        if (b < l || r < a) return {0};
        
        if (a <= l && r <= b) return seg[p];

        ll m = (l + r) / 2;

        return combine(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
    }

    Node update(int pos, ll x, ll p = 1, ll L = 0, ll R = n - 1) {
        if (L==R) return seg[p] = mk_node(x);

        ll m = (L + R) / 2;

        if (pos <= m) 
            update(pos, x, 2 * p, L, m);
        else 
            update(pos, x, 2 * p + 1, m + 1, R);

        return seg[p] = combine(seg[2*p], seg[2*p+1]);
    }
}

void solve() {
    int n, m; cin >> n >> m;  

    ll a[n];
    forn (i, n) cin >> a[i];
    
    seg::build(n, a);

    cout << seg::seg[1].maxsum << "\n";
    while (m--) {
        int i; 
        ll v; cin >> i >> v;

        seg::update(i, v);
        cout << seg::seg[1].maxsum << "\n";
    } 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}
```

Number of different  on a segment

```
Given an array a, consisting of small integers (1≤ai≤40). You need to build a data structure that processes two types of queries:

find the number of different elements on a segment,
change the element of the array.
```

1. pense em uma eficiente de dizer quais elementos estão presentes em um determinado node da seg 
2. podemos usar bitmask par tal tarefa, cada bit ligado diz que o numero está presente no node 
    exemplo: 3 
        (1 << 3) = 01000
3. Para cada node pai, dizemos que seus numeros serão a combinação dos elementos distintos do node A e node B:
    1. usamos a operação OR para união dos conjuntos:
        (mask A OR mask B) 
        0100 | 0010 = 0110 => 1 e 2 estão no conjunto final
4. Em cada contamos a quantidade de bits ligados

```c++
struct Node {
    ll mask;
};
 
Node comb(Node a, Node b) {
    return {a.mask | b.mask}; 
}
 
namespace seg {
    Node seg[4*MAXN];
    int n;
    ll *v;
 
    Node build(ll p = 1, ll l = 0, ll r = n - 1) {
        if (l == r) return seg[p] = {(1LL << v[l])};
 
        ll m  = (l + r) / 2;
        return seg[p] = comb(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
    }
 
    void build(int n2, ll *v2) {
        n = n2; v = v2;
        build();
    }
 
    Node query(ll a, ll b, ll p = 1, ll l = 0, ll r = n - 1) {
        if (b < l || r < a) return {0};
        
        if (a <= l && r <= b) return seg[p];
 
        ll m = (l + r) / 2;
 
        return comb(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
    }
 
    Node update(int pos, ll x, ll p = 1, ll L = 0, ll R = n - 1) {
        if (L==R) return seg[p] = {(1LL << x)};
 
        ll m = (L + R) / 2;
 
        if (pos <= m) 
            update(pos, x, 2 * p, L, m);
        else 
            update(pos, x, 2 * p + 1, m + 1, R);
 
        return seg[p] = comb(seg[2*p], seg[2*p+1]);
    }
}
 
void solve() {
    int n, q; cin >> n >> q;
    ll a[n];
 
    forn (i, n) cin >> a[i];
    
    seg::build(n, a);
    
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            x--; y--;
            cout << __builtin_popcountll(seg::query(x, y).mask) << "\n";
        } else {
            int x, y; cin >> x >> y;
            x--;
            seg::update(x, y);
        }
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}
```

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

# BIT 
***

Uma variação dinamica de um prefix sum array.

suporta duas operações em O(logN);

- processa a soma de um intervalo do array.
- atualiza um elemento da array.

```c++
struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	
    void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	
    ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	
    ll query(int l, int r) { // soma [l, r]
		return pref(r) - pref(l - 1);
	}
	
    int upper_bound(ll x) {
    int p = 0;
		for (int i = __lg(n); i+1; i--)
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};
```

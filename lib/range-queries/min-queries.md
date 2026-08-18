Range Minimum Queries
***

RMQ (Range Minimum Query) é o problema de encontrar o menor elemento em um intervalo [l, r].

A Sparse Table pré-calcula mínimos de intervalos de tamanho potência de 2 (1, 2, 4, 8...). Assim, cada consulta pode ser respondida em O(1) usando dois intervalos pré-calculados.

Build: O(n log n)
Query: O(1)
Memória: O(n log n)

É indicada quando o vetor é estático e existem muitas consultas.

# Implementation

```c++
#include <bits/stdc++.h>
using namespace std;



class SparseTable {
    vector<vector<int>> st;
    vector<int> lg;

public:
    SparseTable(vector<int>& a) {
        int n = a.size();
        lg.resize(n + 1);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        st.resize(K, vector<int>(n));

        // ranges of length 1
        for (int i = 0; i < n; i++) {
            st[0][i] = a[i];
        }

        // ranges of length 2, 4, 8, ...
        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {

                st[k][i] = min(
                    st[k - 1][i],
                    st[k - 1][i + (1 << (k - 1))]
                );

            }
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;

        int k = lg[len];

        return min(
            st[k][l],
            st[k][r - (1 << k) + 1]
        );
    }
};

int main() {
    vector<int> a = {1, 3, 4, 8, 6, 1, 4, 2};

    SparseTable st(a);

    cout << st.query(1, 6) << '\n';
    cout << st.query(0, 3) << '\n'; 
    cout << st.query(3, 4) << '\n'; 
}
```

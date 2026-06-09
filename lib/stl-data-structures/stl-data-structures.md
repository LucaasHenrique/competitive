# STL Data Structures
***

# Iteradores

Iteradores são objetos usados para percorrer containers da STL.

Eles funcionam de forma parecida com ponteiros.

Exemplo:

```cpp
vector<int> v = {1, 2, 3};

for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << "\n";
}
```

## Principais funções

```cpp
v.begin() // início
v.end()   // posição após o último elemento
```

## Operador `*`

```cpp
*it
```

Acessa o valor apontado pelo iterador.

***

# Set

`set` é uma estrutura que armazena elementos únicos em ordem crescente.

Internamente usa uma árvore balanceada.

Complexidade:

```text
Inserção: O(log N)
Busca: O(log N)
Remoção: O(log N)
```

## Exemplo

```cpp
set<int> s;

s.insert(5);
s.insert(2);
s.insert(8);
s.insert(5); // ignorado
```

Resultado:

```text
2 5 8
```

## Funções úteis

```cpp
s.insert(x)
s.erase(x)
s.count(x)
s.find(x)
```

## Percorrendo um set

```cpp
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << "\n";
}
```

ou:

```cpp
for (int x : s) {
    cout << x << "\n";
}
```

***

# Iteradores de Set

Como `set` não possui índices, acessamos elementos usando iteradores.

## find

```cpp
auto it = s.find(5);
```

- Se existir:
  
```cpp
it != s.end()
```

- Se não existir:
  
```cpp
it == s.end()
```

## next e prev

```cpp
next(it)
prev(it)
```

Permitem avançar ou voltar iteradores.

Exemplo:

```cpp
auto it = s.find(5);

cout << *next(it);
```

***
# Multiset

`multiset` é parecido com `set`, mas permite elementos repetidos.

Os elementos também ficam em ordem crescente.

Internamente usa uma árvore balanceada.

Complexidade:

```text
Inserção: O(log N)
Busca: O(log N)
Remoção: O(log N)
```

-> Funçõs uteis

```
ms.insert(x)
ms.erase(x)
ms.count(x)
ms.find(x)
```

erase() -> remove todas as ocorrencis de um valor

use: 

ms.erase(ms.find(5)) -> remove apenas uma ocorrencia.
***
# Map

`map` armazena pares:

```text
chave -> valor
```

As chaves ficam ordenadas.

Complexidade:

```text
Inserção: O(log N)
Busca: O(log N)
Remoção: O(log N)
```

## Exemplo

```cpp
map<string, int> idade;

idade["Lucas"] = 20;
idade["Ana"] = 18;
```

## Acessando valores

```cpp
cout << idade["Lucas"];
```

## Percorrendo

```cpp
for (auto [nome, valor] : idade) {
    cout << nome << " " << valor << "\n";
}
```

## Funções úteis

```cpp
m.count(x)
m.find(x)
m.erase(x)
```

***

# Bitset

`bitset` é uma estrutura para armazenar bits.

Muito útil para operações binárias.

## Exemplo

```cpp
bitset<8> b("10110011");
```

Resultado:

```text
10110011
```

## Operações úteis

```cpp
b.count() // quantidade de bits 1
b.any()   // existe algum 1?
b.none()  // todos são 0?
b.flip()  // inverte bits
```

## Acessando bits

```cpp
cout << b[0];
```

***

# Deque

`deque` significa:

```text
double ended queue
```

Permite inserir e remover elementos tanto no início quanto no fim.

Complexidade:

```text
push_front: O(1)
push_back: O(1)
```

## Exemplo

```cpp
deque<int> d;

d.push_back(5);
d.push_front(2);
```

Resultado:

```text
2 5
```

## Funções úteis

```cpp
d.push_back(x)
d.push_front(x)

d.pop_back()
d.pop_front()
```

## Acesso por índice

```cpp
cout << d[0];
```

***

# Stack

`stack` segue a lógica:

```text
LIFO
Last In First Out
```

O último elemento inserido é o primeiro a sair.

## Exemplo

```cpp
stack<int> s;

s.push(1);
s.push(2);
s.push(3);
```

Estado:

```text
topo -> 3
```

## Funções úteis

```cpp
s.push(x)
s.pop()
s.top()
s.empty()
```

## Exemplo

```cpp
cout << s.top(); // 3
```

***

# Queue

`queue` segue a lógica:

```text
FIFO
First In First Out
```

O primeiro elemento inserido é o primeiro a sair.

## Exemplo

```cpp
queue<int> q;

q.push(1);
q.push(2);
q.push(3);
```

Estado:

```text
frente -> 1
```

## Funções úteis

```cpp
q.push(x)
q.pop()
q.front()
q.back()
```

## Exemplo

```cpp
cout << q.front(); // 1
```

***

# Priority Queue

`priority_queue` mantém o maior elemento no topo.

Internamente usa heap.

Complexidade:

```text
Inserção: O(log N)
Remoção: O(log N)
Topo: O(1)
```

## Exemplo

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(5);
pq.push(20);
```

Topo:

```text
20
```

## Funções úteis

```cpp      
pq.push(x)
pq.pop()
pq.top()
```

## Min Heap

Por padrão ela é max heap.

Para criar min heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Agora o menor elemento ficará no topo.
***
# Policy Based Data Structures (PBDS)

São estruturas de dados que não fazem parte da stl do c++.

a ideia é usar policies como parametros da template para customizar o comportamento da estrututra.

exemplo: 
```c++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    
    int n; cin >> n;
    ll k; cin >> k;
    
    ordered_set nums;
    for (int i = 1; i <= n; i++) nums.insert(i);
    
    int pos = 0;
    while (!nums.empty()) {
        pos = (pos + k) % nums.size();
        
        auto it = nums.find_by_order(pos);
        cout << *it << " ";
        nums.erase(it);
    }

    cout << "\n";
}
```
a estrutura do exemplo é um `set`, porem possui algumas funçoes extras:

`find_by_order(idx)` -> busca um elemento com base em um indice é retorna um ponteiro.
`order_of_key(value)` -> retorna o número de elementos estritamente menores que value

***
# Resumo

| Estrutura | Ordenado | Duplicados | Busca |
|---|---|---|---|
| set | Sim | Não | O(log N) |
| map | Sim | Chave não | O(log N) |
| deque | Não | Sim | O(1) índice |
| stack | Não | Sim | topo |
| queue | Não | Sim | frente |
| priority_queue | Parcial | Sim | topo |
| bitset | Bits | - | O(1) |
| multiset | Sim | Sim | O(log N) |

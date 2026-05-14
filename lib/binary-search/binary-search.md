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

# Complexidade

A Binary Search reduz o espaço de busca pela metade a cada operação.

Complexidade:

```text
O(log N)
```

Memória:

```text
O(1)
````[false, false, false, false, false, true, true, true, true]`

ou seja a partir de sexto, todos os elementos satisfazem a condição esperada, então podemos dizer que 6 e a menor solução valida.



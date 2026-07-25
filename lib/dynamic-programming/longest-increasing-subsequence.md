# Longest Increasing Subsequence (LIS)
***

O problema trata de encontrar a **maior subsequência crescente** em um array, isto é, a maior sequência da esquerda para a direita em que cada elemento é maior que o anterior.

Considere o array:

```text
array = {6, 2, 5, 1, 7, 4, 8, 3}
```

Seja `length(k)` a maior LIS que termina na posição `k`. Vamos calcular `length(k)` para todo `k`, onde `0 <= k <= n - 1`.

### Exemplo

No array acima:

```text
length(0) = 1
length(1) = 1
length(2) = 2
length(3) = 1
length(4) = 3
length(5) = 2
length(6) = 4
length(7) = 2
```

Formando a subsequência:

```text
2 5 7 8
```

## Como calcular `length(k)`

Para calcular `length(k)`, temos que encontrar uma posição `i < k` em que:

- `array[i] < array[k]`;
- `length(i)` seja o maior possível.

Então:

```text
length(k) = length(i) + 1
```

Se não existe nenhuma posição `i` que satisfaça essas condições, então:

```text
length(k) = 1
```

## Implementação O(n²)

```cpp
for (int k = 0; k < n; k++) {
    length[k] = 1;
    for (int i = 0; i < k; i++) {
        if (array[i] < array[k]) {
            length[k] = max(length[k], length[i] + 1);
        }
    }
}
```

Cada posição percorre todas as posições anteriores para encontrar a melhor subsequência que pode ser estendida.

**Complexidade:**

- Tempo: **O(n²)**
- Memória: **O(n)**

## Solução O(n log n)

A ideia é manter um vetor `lis`, onde:

- `lis[i]` representa o **menor valor possível que pode terminar uma subsequência crescente de tamanho `i + 1`**.

Esse vetor **não representa necessariamente uma subsequência do array original**, mas ele guarda a melhor possibilidade para estender subsequências futuras.

Percorremos o array da esquerda para a direita.

Para cada elemento:

- Se ele é maior que o último elemento de `lis`, podemos estender a maior subsequência encontrada até agora.
- Caso contrário, procuramos a primeira posição em `lis` cujo valor seja **maior ou igual** ao elemento atual e substituímos esse valor.

Essa busca é feita com `lower_bound`, que executa em **O(log n)**.

### Exemplo

Considere:

```text
array = {6, 2, 5, 1, 7, 4, 8, 3}
```

Estado de `lis` após cada elemento:

| Elemento | lis |
|----------|----------------|
| 6 | {6} |
| 2 | {2} |
| 5 | {2, 5} |
| 1 | {1, 5} |
| 7 | {1, 5, 7} |
| 4 | {1, 4, 7} |
| 8 | {1, 4, 7, 8} |
| 3 | {1, 3, 7, 8} |

Observe que o vetor termina como:

```text
{1, 3, 7, 8}
```

Ele **não é necessariamente a LIS do array**. A LIS original poderia ser:

```text
2 5 7 8
```

O importante é que o tamanho de `lis` é exatamente o tamanho da maior subsequência crescente.

## Implementação

```cpp
vector<int> lis;

for (int x : array) {
    auto it = lower_bound(lis.begin(), lis.end(), x);

    if (it == lis.end())
        lis.push_back(x);
    else
        *it = x;
}

cout << lis.size() << '\n';
```

### Por que isso funciona?

Sempre tentamos manter o menor valor possível no final de cada subsequência de determinado tamanho.

Quanto menor for esse último elemento, maiores são as chances de conseguir estender essa subsequência no futuro.

Por isso, quando encontramos um valor menor, preferimos substituir em vez de criar uma nova subsequência.

**Complexidade:**

- Tempo: **O(n log n)**
- Memória: **O(n)**

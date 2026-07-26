# DP em Arrays - Estado = Posição + Valor
***

## Quando usar?

Quando:

- O array deve ser construído posição por posição;
- A decisão na posição `i` depende apenas do valor da posição anterior;
- É necessário contar o número de formas válidas.

## Estado

```cpp
dp[i][x]
```

> Número de maneiras de preencher as posições `0...i`, de forma que o valor da posição `i` seja `x`.

Onde:

- `i` = posição do array;
- `x` = valor da posição (`1 ≤ x ≤ m`).

---

## Transição

Se a posição pode assumir qualquer valor:

```cpp
dp[i][x] = dp[i-1][x];

if (x > 1)
    dp[i][x] += dp[i-1][x-1];

if (x < m)
    dp[i][x] += dp[i-1][x+1];

dp[i][x] %= MOD;
```

Caso exista um valor fixo na posição:

```cpp
if (a[i] != 0 && x != a[i])
    continue;
```

Assim apenas o valor permitido é calculado.

---

## Caso base

Se o primeiro elemento é livre:

```cpp
for (int x = 1; x <= m; x++)
    dp[0][x] = 1;
```

Se ele é fixo:

```cpp
dp[0][a[0]] = 1;
```

---

## Resposta

Se o último elemento é conhecido:

```cpp
answer = dp[n-1][a[n-1]];
```

Caso contrário:

```cpp
answer = 0;

for (int x = 1; x <= m; x++)
    answer = (answer + dp[n-1][x]) % MOD;
```

---

## Complexidade

- Tempo: `O(n · m)`
- Memória: `O(n · m)` (ou `O(m)` usando apenas duas linhas).

---

## Como reconhecer esse padrão?

Faça estas perguntas:

1. Estou construindo um array da esquerda para a direita?
2. A decisão atual depende apenas do elemento anterior?
3. Preciso contar quantas formas existem?

Se as três respostas forem **sim**, provavelmente o estado será:

```cpp
dp[posição][valor]
```

---

## Exemplo

**CSES - Array Description**

Entrada:

```text
0 0 2
```

A DP fica:

```text
Posição 0

1 1 1

↓

Posição 1

2 3 2

↓

Posição 2 (valor fixo = 2)

0 7 0
```

Resposta:

```cpp
dp[2][2] = 7
```


Insight: dp[i][x] não representa um único array, mas sim quantos arrays diferentes chegam até a posição i terminando com o valor x. Como cada estado é construído apenas a partir de estados válidos, não é necessário verificar novamente as restrições do array durante a resposta final.

# Edit Distance

***

O **Edit Distance** é o menor número de operações necessárias para transformar uma string em outra.

As operações permitidas são:

- **Insert** um caractere
  - `ABC → ABCA`
- **Remove** um caractere
  - `ABC → AC`
- **Modify (Replace)** um caractere
  - `ABC → ABD`

### Exemplo

Transformar:

```text
LOVE → MOVIE
```

Uma solução ótima é:

```text
LOVE
 ↓ modify (L → M)
MOVE
 ↓ insert (I)
MOVIE
```

Logo,

```text
Edit Distance = 2
```

***

# Solution

Sejam:

- `x` uma string de tamanho `n`;
- `y` uma string de tamanho `m`.

Queremos calcular o menor número de operações para transformar `x` em `y`.

Definimos o estado:

```cpp
dp[i][j]
```

como:

> O menor número de operações para transformar os **primeiros `i` caracteres de `x`** nos **primeiros `j` caracteres de `y`**.

---

## Casos base

Se queremos transformar uma string em uma string vazia, basta remover todos os caracteres.

```cpp
dp[i][0] = i;
```

Se queremos transformar uma string vazia em outra string, basta inserir todos os caracteres.

```cpp
dp[0][j] = j;
```

---

## Transição

A ideia principal é responder a seguinte pergunta:

> **De qual estado poderíamos ter vindo?**

Ou, equivalentemente:

> **Qual foi a última operação realizada?**

Considere o exemplo:

```text
ab → ac
```

Queremos calcular:

```cpp
dp[2][2]
```

As únicas possibilidades para a **última operação** são:

### 1. Inserção

Se a última operação foi inserir o último caractere de `y`, então antes já havíamos resolvido:

```text
ab → a
```

Esse é o estado:

```cpp
dp[i][j-1]
```

Depois inserimos o último caractere de `y`.

---

### 2. Remoção

Se a última operação foi remover o último caractere de `x`, então antes tínhamos:

```text
a → ac
```

Esse é o estado:

```cpp
dp[i-1][j]
```

Depois removemos o último caractere de `x`.

---

### 3. Substituição

Se a última operação foi substituir o último caractere de `x`, então antes tínhamos:

```text
a → a
```

Esse é o estado:

```cpp
dp[i-1][j-1]
```

Depois substituímos o último caractere de `x` pelo último caractere de `y`.

---

## Caracteres iguais

Se os últimos caracteres são iguais,

```cpp
x[i-1] == y[j-1]
```

não precisamos realizar nenhuma operação.

Basta copiar a diagonal:

```cpp
dp[i][j] = dp[i-1][j-1];
```

---

## Caracteres diferentes

Caso contrário, escolhemos a melhor das três possibilidades:

```cpp
int insert  = dp[i][j-1] + 1;
int remove  = dp[i-1][j] + 1;
int replace = dp[i-1][j-1] + 1;

dp[i][j] = min({insert, remove, replace});
```

---

## Complexidade

- **Tempo:** `O(nm)`
- **Memória:** `O(nm)`

***

# Implementação

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    // dp[i][j] = menor número de operações para transformar
    // os primeiros i caracteres de 'a'
    // nos primeiros j caracteres de 'b'
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Transformar os i primeiros caracteres em string vazia
    // => remover todos
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    // Transformar string vazia nos j primeiros caracteres
    // => inserir todos
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    // Preenche a tabela
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // Últimos caracteres iguais
            if (a[i - 1] == b[j - 1]) {

                // Não precisamos fazer nenhuma operação
                dp[i][j] = dp[i - 1][j - 1];

            } else {

                // Inserir o último caractere de b
                int insert = dp[i][j - 1] + 1;

                // Remover o último caractere de a
                int remove = dp[i - 1][j] + 1;

                // Trocar o último caractere de a
                // pelo último caractere de b
                int replace = dp[i - 1][j - 1] + 1;

                dp[i][j] = min({insert, remove, replace});
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
```

> **Resumo da ideia:** diferente da maioria das DPs, no Edit Distance não pensamos em "qual decisão tomar agora?", mas sim **"qual foi a última operação realizada?"**. Essa perspectiva leva naturalmente às três transições: **inserção**, **remoção** e **substituição**.

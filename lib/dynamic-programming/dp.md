# Dynamic Programming
***

Programação dinâmica é uma técnica que combina a exatidão das buscas completas e a eficiência dos algoritmos gulosos.

Pode ser aplicada quando o problema pode ser dividido em **subproblemas sobrepostos** que podem ser resolvidos de forma independente.

Exemplo:

Para calcular `fib(5)` preciso calcular `fib(4)` e `fib(3)`. Porém, `fib(4)` também precisa de `fib(3)`, ou seja, `fib(3)` é um subproblema sobreposto, pois aparece mais de uma vez.

Podemos perceber que `fib(3)` sempre tem a mesma resposta, então podemos calculá-lo somente uma vez e guardar o resultado.

***

Existem duas formas de usar DP:

1. **Encontrar uma solução ótima:** queremos encontrar uma solução que seja a maior possível ou a menor.
2. **Contar o número de soluções:** queremos encontrar o número de possíveis soluções.

# Classic Problems

## 1. Coin Problem

```text
Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n, our task is to
form the sum n using as few coins as possible.
```

É possível resolver usando algoritmo guloso, mas ele não necessariamente funciona para todos os casos.

Com DP iremos produzir todas as possíveis soluções, assim como em um backtracking, porém calculamos cada subproblema somente uma vez e guardamos esse resultado. Isso é conhecido como **memoization**, o que faz a DP ser tão eficiente.

A ideia é formular uma solução recursiva para o problema, de modo que a solução possa ser calculada com base na solução dos subproblemas.

> "Qual o menor número de moedas para formar a soma `x`?"

Definimos:

`solve(x)` → mínimo de moedas para formar `x`.

Se:

```text
coins = {1, 3, 4}
```

Então:

```text
solve(10) = 3
```

pois:

```text
3 + 3 + 4 = 10
```

A propriedade essencial de `solve` é que seu valor pode ser calculado a partir de valores menores.

A ideia é focar na **primeira moeda escolhida** para formar a soma.

Suponha que a primeira moeda seja `1`, ou seja:

```text
x - 1 = 9
```

O que precisamos agora?

Encontrar o menor número de moedas para formar `9`.

Podemos pensar em uma fórmula recursiva que represente isso:

```text
solve(x) = min(
    solve(x - 1) + 1,
    solve(x - 3) + 1,
    solve(x - 4) + 1
)
```

O caso base da recursão é:

```text
solve(0) = 0
```

Então temos o caso geral:

```cpp
solve(x):

return INF se x < 0
return 0   se x == 0
return min(solve(x - c) + 1) se x > 0
```

onde `c` é a moeda escolhida.

Podemos notar que a variável `c` irá iterar sobre todas as possibilidades de escolha de moeda.

O fluxo é o seguinte:

A primeira chamada recursiva vai até o menor valor possível e calcula seus resultados. Assim, caso esses valores se repitam nas próximas chamadas, eles já estarão calculados e prontos para serem reutilizados.

### Implementação

```cpp
bool ready[N]; // valor de x já foi visitado?
int value[N];  // resposta para x

int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;

    if (ready[x]) return value[x];

    int best = INF;

    for (int c : coins) {
        best = min(best, solve(x - c) + 1);
    }

    value[x] = best;
    ready[x] = true;

    return best;
}
```

***

# Formas de implementar DP

Existem duas formas de implementar programação dinâmica.

## 1. Top-Down (Memoization)

Olhar de cima para baixo.

Começamos com o problema original e vamos quebrando-o em subproblemas de forma recursiva.

## 2. Bottom-Up (Tabulation)

Olhar de baixo para cima.

Começamos pelo menor estado possível e vamos construindo as respostas até chegar ao estado desejado.

```text
0 → 1 → 2 → 3 → 4 → ... → N
```

Cada estado utiliza apenas estados que já foram calculados anteriormente.

### Exemplo

Para o Coin Problem:

```text
value[x] -> menor número de moedas para formar x
```

```cpp
coins = {1, 3, 4};
value[0] = 0;

for (int x = 1; x <= n; x++) {
    value[x] = INF;

    for (auto c : coins) {
        if (x - c >= 0) {
            value[x] = min(value[x], value[x - c] + 1);
        }
    }
}
```

Recorrência:

```text
dp(x) = min(dp(x - c) + 1)
```

***

# Recuperando a solução

Se o problema perguntar **quais moedas foram usadas** para construir a solução, basta guardar a moeda escolhida em cada estado.

```cpp
int n = 10;

coins = {1, 3, 4};

value[0] = 0;
int ans[N];

for (int x = 1; x <= n; x++) {
    value[x] = INF;

    for (auto c : coins) {
        if (x - c >= 0 && value[x - c] + 1 < value[x]) {
            value[x] = value[x - c] + 1;
            ans[x] = c;
        }
    }
}

while (n > 0) {
    cout << ans[n] << "\n";
    n -= ans[n];
}
```

***

# Contando o número de soluções

Outro problema clássico é procurar o número de soluções possíveis que formem o valor `x`.

Exemplo:

```text
x = 5
coins = {1, 3, 4}
```

Possíveis soluções:

```text
1 + 1 + 1 + 1 + 1
3 + 1 + 1
4 + 1
1 + 4
1 + 1 + 3
1 + 3 + 1
```

Total:

```text
6 soluções
```

Para isso modelamos a seguinte recorrência:

```text
solve(x) =
    solve(x - c1) +
    solve(x - c2) +
    ...
    solve(x - ck)
```

Ou seja, estamos fazendo uma busca completa e usando DP como poda.

## Bottom-Up

### Permutações (a ordem importa)

```cpp
count[0] = 1;

for (int x = 1; x <= n; x++) {
    for (auto c : coins) {
        if (x - c >= 0) {
            count[x] += count[x - c];
        }
    }
}
```

### Combinações (a ordem não importa)

```cpp
count[0] = 1;

for (auto c : coins) {
    for (int x = 1; x <= n; x++) {
        if (x - c >= 0) {
            count[x] += count[x - c];
        }
    }
}
```

## Top-Down

```cpp
const int MOD = 1e9 + 7;

int count[N];
bool ready[N];

int solve(int x) {

    if (x < 0) return 0;
    if (x == 0) return 1;

    if (ready[x]) return count[x];

    int ways = 0;

    for (auto c : coins) {
        if (x - c >= 0) {
            ways += solve(x - c);
            ways %= MOD;
        }
    }

    count[x] = ways;
    ready[x] = true;

    return count[x];
}
```

*** 

Observe que, para problemas de **minimização**, normalmente usamos:

```text
dp(x) = min(dp(x - c) + 1)
```

Já para problemas de **contagem**, usamos:

```text
dp(x) += dp(x - c)
```

A diferença está justamente no objetivo do problema: encontrar a melhor solução ou contar todas as soluções possíveis.

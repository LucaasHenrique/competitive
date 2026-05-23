
# Procurando o subarray com maior/menor soma
***
Dado um array de numeros `a[1...n]`, queremos encontrar o array `a[l...r]` com maior/menor soma.

- se o array é composto de numeros não negativos, a maior soma será encontrada em `a[1...N]`;

## Algoritmo 1 

esse algoritmo basicamente faz um prefix sum + menor prefixo anterior;

a soma de um subarray l..r é:

`sum(l, r) = prefix[r] - prefix[l-1]`

entao para cada `r` queremos maximizar:

`sum - min_sum`

onde: 

`sum = prefix ate r atual`
`min_sum = menor prefixo antes de r`

ou seja, para obter a maior soma ate r, pegamos o prefixo atual e subtraimos o menor prefixo que apareceu.

exemplo:

`a = [-2, 3, -1, 5]`

```
r=0: sum=-2
ans=max(-2, -2-0) = -2
min_sum=min(0,-2) = -2

r=1: sum=1
ans=max(-2, 1-(-2)) = 3
min_sum=-2

r=2: sum=0
ans=max(3, 0-(-2)) = 3
min_sum=-2

r=3: sum=5
ans=max(3, 5-(-2)) = 7
```

ans = 7;

```c++
int ans = a[0], sum = 0, min_sum = 0;

for (int r = 0; r < n; ++r) {
    sum += a[r];
    ans = max(ans, sum - min_sum);
    min_sum = min(min_sum, sum);
}
```

para encontrar os indices do intervalo:

```c++
int ans = a[0], ans_l = 0, ans_r = 0;
int sum = 0, min_sum = 0, min_pos = -1;

for (int r = 0; r < n; ++r) {
    sum += a[r];
    int cur = sum - min_sum;
    if (cur > ans) {
        ans = cur;
        ans_l = min_pos + 1;
        ans_r = r;
    }
    if (sum < min_sum) {
        min_sum = sum;
        min_pos = r;
    }
}
```

para encontrar a menor soma: 

```c++
int ans = a[0], sum = 0, max_sum = 0;

for (int r = 0; r < n; r++) {
    sum += a[r];
    ans = min(ans, sum - max_sum);
    max_sum = max(max_sum, sum);
}
```

```c++ 
int ans = a[0], ans_l = 0, ans_r = 0;
int sum = 0, max_sum = 0, max_pos = -1;

for (int r = 0; r < n; ++r) {
    sum += a[r];

    int cur = sum - max_sum;

    if (cur < ans) {
        ans = cur;
        ans_l = max_pos + 1;
        ans_r = r;
    }

    if (sum > max_sum) {
        max_sum = sum;
        max_pos = r;
    }
}
```
***

# Algoritmo de Kadane

Nesse algoritmo vamos fazendo a soma acumulada de todo o array e se em algum ponto o elemento atual for negativos reiniciamos a soma para 0 e começamos a acumular denovo;

ideia central é:

`se a soma acumulada ficou negativa, nunca vale a pena continuar carregando ela para frente`

exemplo: 

`a = [-2, 3, -1, 5, -4]`

```
x -> elemento atual
curr -> soma acumulada atual
best -> melhor soma q ja apareceu

x = -2
curr = -2
best = -2

curr < 0 -> zera

----------------

x = 3
curr = 3
best = 3

----------------

x = -1
curr = 2
best = 3

----------------

x = 5
curr = 7
best = 7

----------------

x = -4
curr = 3
best = 7
```

Por que podemos jogar fora quando fica negativo?

imagine que `a = [-5, 10]`

se considerarmos o -5 a soma ficaria `s = -5 + 10`, logo `s = 5`

se ignorarmos o -5 temos que `s = 10`

implementation:

```c++
int ans = a[0], sum = 0;

for (int r = 0; r < n; ++r) {
    sum += a[r];
    ans = max(ans, sum);
    sum = max(sum, 0);
}
```

with indices

```c++
int ans = a[0], ans_l = 0, ans_r = 0;
int sum = 0, minus_pos = -1;

for (int r = 0; r < n; ++r) {
    sum += a[r];
    if (sum > ans) {
        ans = sum;
        ans_l = minus_pos + 1;
        ans_r = r;
    }
    if (sum < 0) {
        sum = 0;
        minus_pos = r;
    }
}
```
***

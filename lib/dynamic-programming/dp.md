Dynamic Programming
***

Programação dinamica é uma tecnica que combina a exatidão das buscas completas e a eficiencia dos algoritmos gulosos

Pode ser aplicada quando o problema pode ser divido em subproblemas sobrepostos que podem ser resolvidos de forma independente.

exemplo: 

para calcular `fib(5)` preciso calcular `fib(4)` e `fib(3)`, porem `fib(4)` tbm precisa de `fib(3)`, ou seja, `fib(3)` é um subproblema sobreposto pois aparece mais de uma vez. Podemos perceber que `fib(3)` sempre tem a mesma resposta, então podemos calcular somente uma vez e guardar o resultado.
***

Existem duas formas de usar DP:

1. Encontrar uma solução otima: Queremos encontrar uma solução que é a maior possivel ou a menor.
2. Contar o numero de soluções: Queremos encontrar o numero de possiveis soluções.

# Classics Problems

1. Coin Problem:

```
Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n, our task is to
form the sum n using as few coins as possible
```

é possivel resolver usando guloso, mas não necessariamente funciona para todos os casos

com dp iremos produzir todas as possiveis soluções igual em um backtracking, porem calculamos cada subproblema somente uma vez e guardamos esse resultado. Isso é conhecido como `memoization`, o que faz a dp ser tão eficiente.

a ideia é formular uma solução recursiva para o problema, de modo que a solução poder ser calculada com base na solução dos subproblemas.

"Qual o menor numero de moedas para formar a soma `x`";

`solve(x)` -> minimo de moedas para formar `x`;

se `coins = {1, 3, 4}`;

`solve(10) = 3`

pois 3 + 3 + 4 = 10

a propriedade essencial de `solve` é que seu valor pode ser calculado a partir de seu valores menores.

a ideia é focar na primeira moeda que escolhemos para a soma.

suponha que seja 1, ou seja, `x - 1 = 9`, o que precisamos agora? escolher moedas que formem uma `soma = 9`. 

Podemos pensar em uma formula recursiva que represente isso, por exemplo:

`solve(x) = min(solve(x - 1) + 1, solve(x - 3) + 1, solve(x - 4) + 1)`

o caso base da recursão é `solve(0) = 0`

então temos o caso geral:

```c+++
solve(x) => 

return INF se x < 0
return 0 se x == 0
return min(solve(x - c) + 1) se x > 0; onde c é a moeda escolhida.
```

podemos notar que a variavel c vai iterar sobre todas as possibilidades de escolha de moeda.

o fluxo de é o seguinte:

a primeira chamada recursiva vai iterar ate o menor valor possivel e calcular seus resultados, assim as caso esses valores se repitam nas proximas chamadas eu ja tenho o valor calculado e pronto para ser usado.

implementation:

```c++
bool ready[N]; // valor de x ja foi visitado?
int value[N]; // se ja foi visitado retorne value[x];

int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;

    if (ready[x]) return value[x];

    int best = INF;
    for (int c: coins) {
        best = min(best, solve(x - c) + 1);
    }

    value[x] = best;
    ready[x] = true;

    return best;
}
```
***

existem duas formas implementar dp:

1. Top-Down (Memoization) - Olhar de cima para baixo

começo com o valor original e vou quebrando em subproblemas de forma recursiva.

2. Bottom-Up (Tabulation) - Olhar de baixo para cima.

começamos do menor possivel e vamos construindo as repostas ate o maior.

0 -> 1 -> 2 -> 3 -> 4 -> ... -> > N 

cada estado usa estados ja calculados anteriomente

exemplo:

para o coin problem

`value[x]` -> menor valor de moedas para formar x;

```c++
coins = {1, 3, 4};
value[0] = 0;

for (int x = 1; x <= n; x++) {
    value[x] = INF;

    for (auto c: coins) {
        if (x - c >= 0) {
            value[x] = min(value[x], value[x - c] + 1);
        }
    }
}
```

`dp(x) = min(dp(x - c) + 1)`
***

Se o problema perguntar quais moedas foram usadas para construir a solução.


```c++
int n = 10;
coins = {1, 3, 4};
value[0] = 0;
int ans[N];

for (int x = 1; x <= n; x++) {
    value[x] = INF;

    for (auto c: coins) {
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

Outra problema classico é procurar a numero de soluções possiveis que formem o valor x

exemplo: x = 5;
coins = {1, 3, 4};

1 + 1 + 1 + 1 + 1
3 + 1 + 1 
4 + 1 
1 + 4 
1 + 1 + 3 
1 + 3 + 1

6 soluções.

Para isso modelamos de formar recursiva:

`solve(x) = solve(x - Ci) + solve(x - Ci+1) + solve(x - Ci+2) + solve(x - Ci+n)` 

ou seja, estamos fazendo um busca completa e usando dp como poda.


```c++
count[0] = 0;

// permutações: a ordem importa
for (int x = 1; x <= n; x++) {
    for (auto c: coins) {
        if (x - c >= 0) {
            count[x] += count[x - c];
        }
    }
}
```


```c++
count[0] = 0;

// combinação: a ordem não importa
for (auto c: coins) {
    for (int x = 1; x <= n; x++) {
        if (x - c >= 0) {
            count[x] += count[x - c];
        }
    }
}
```

or recursive:

```c++
ll m = 1e9 + 7;

int count[N];
bool ready[N];

int solve(x) {
        
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (ready[x]) return count[x];
    
    int n_ways = 0;
    for (auto c: coins) {
        if (x - c >= 0) {
            n_ways += solve(x - c);
            n_ways %= m;
        }
    }
   
    
    count[x] = n_ways;
    ready[x] = true;

    return count[x];
}
```
***


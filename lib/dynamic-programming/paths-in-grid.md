# Paths in a grid
***

O problema é: temos uma grid, cada celula da grid possui um numero inteiro e nosso objetivo é sair do canto superior mais a esquerda é chegar no canto inferior mais a direita, de modo que a soma das celulas que aparecem no caminho seja a maior possivel;

nessa grid, só podemos ir para celular a direita ou para a celula abaixo.

seja sum(y, x) a maior soma em um caminho que sai da celula mais a esquerda, sum(n, n) denota a maior para chegar no canto mais a direita.

então o que devemos responder é:

cheguei na celula (y, x) qual o maior caminho possivel que chega nessa celula? calulamos isso olhando para a esquerda e para cima com (y, x - 1) e (y - 1, x);

então a formula fica:

`sum(y, x) = max(sum(y, x - 1), sum(y - 1, x)) + value[y][x];` 

implementation:

```c++
int dp[N][N];
int grid[N][N];

dp[0][0] = grid[0][0];

// iniciando a primeira linha
for (int x = 1; x < n; x++)
    dp[0][x] = dp[0][x-1] + grid[0][x];

// iniciando a primeira coluna
for (int y = 1; y < n; y++)
    dp[y][0] = dp[y-1][0] + grid[y][0];


for (int y = 1; y < n; y++) {
    for (int x = 1; x < n; x++) {
        dp[y][x] = max(dp[y][x-1], dp[y-1][x]) + grid[y][x];
    }
}
```



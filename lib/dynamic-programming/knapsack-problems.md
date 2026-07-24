# KnapSack Problems
***

A estrutura comum de um problem de knapsack:

Dado um conjunto de objetos, encontre um subconjunto com determinada propriedade

# Knapsack 0-1 

Imagine que voce tem uma mochila com capacidade limita é varios itens. Cada item pode ser escolhidouma unica vez (1) ou não escolhido(0). O objetivo é maximizar o valor total sem ultrapassar a capacidade da mochila.

1 -> pega o item
0 -> não pega o item

exemplo:

mochila com capacidade 6;

item  Peso   Valor

1        2       3
2        3       4
3        4       5
      

a pergunta que dememos fazer é:

`dp[i][w] -> usando i itens, qual o maior vlaor que consigo obter com capacidade w`;

então imagine o estado `dp[3][6]`:

usando os tres primeiros itens, qual o melhor valor para capacidade 6?

agora vemos as opções:

opção 1: não pegar o item 3 ->

então a resposta será usar o item anterior que ja pegamos, assim:

`dp[i][w] = dp[i - 1][w]` -> qual era a melhor resposta usando apenas dois itens?

opção 2: pegar o item 3 ->

se pegamos o item 3 ele ocupa uma capacidade 4, então subtraimos:

capacidade atual = 6 - 4;

restando uma capacidade 2, o que fazemos agora? 

se o item 3 ja foi escolhido não podemos escolhe-lo de novo, então o que fazemos é olhar para o estado anterior:

`Qual a melhor opção usando apenas os dois primeiro itens e com uma capacidade 2?`

essa resposta provavelmente ja foi calculada, sendo:

`dp[2][2]`;

então apenas somamos ao valor do item 3;

`dp[i][w] = dp[2][2] + value[3]`;

então temos que a formula do knapsack 0 - 1 é:

`dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[w]] + value[i])`;

classical implementation:

```c++
vector<int> weight = {2, 3, 4, 5};
vector<int> value  = {3, 4, 5, 6};

int n = weight.size();
int W = 8;

int dp[n+1][W+1];
memset(dp, 0, sizeof dp);

for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {

        // Não pegar o item i
        dp[i][w] = dp[i - 1][w];

        // Pegar o item i (se couber)
        if (w >= weight[i - 1]) {
            dp[i][w] = max(
                dp[i][w],
                dp[i - 1][w - weight[i - 1]] + value[i - 1]
            );
        }
    }
}

cout << dp[n][W] << endl;
```

Versão otimizada (1D):

```c++
vector<int> dp(W + 1, 0);

for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```
***




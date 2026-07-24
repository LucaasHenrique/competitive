# Knapsack

A estrutura comum de um problema de **Knapsack**:

> Dado um conjunto de objetos, encontre um subconjunto com determinada propriedade.

---

# Knapsack 0-1

Imagine que você tem uma mochila com capacidade limitada e vários itens. Cada item pode ser escolhido **uma única vez (1)** ou **não escolhido (0)**. O objetivo é maximizar o valor total sem ultrapassar a capacidade da mochila.

- **1** → pega o item
- **0** → não pega o item

## Exemplo

Mochila com capacidade **6**.

| Item | Peso | Valor |
|:----:|:----:|:-----:|
| 1 | 2 | 3 |
| 2 | 3 | 4 |
| 3 | 4 | 5 |

---

A pergunta que devemos fazer é:

```text
dp[i][w] -> usando i itens, qual o maior valor que consigo obter com capacidade w?
```

Então imagine o estado:

```text
dp[3][6]
```

Ou seja:

> Usando os três primeiros itens, qual o melhor valor para capacidade 6?

Agora vemos as opções.

---

## Opção 1: Não pegar o item 3

Então a resposta será usar o estado anterior:

```cpp
dp[i][w] = dp[i - 1][w];
```

Ou seja:

> Qual era a melhor resposta usando apenas dois itens?

---

## Opção 2: Pegar o item 3

Se pegamos o item 3, ele ocupa uma capacidade **4**, então subtraímos:

```text
capacidade atual = 6 - 4
```

Restando uma capacidade **2**, o que fazemos agora?

Se o item 3 já foi escolhido, não podemos escolhê-lo de novo. Então o que fazemos é olhar para o estado anterior:

> Qual a melhor opção usando apenas os dois primeiros itens e com uma capacidade 2?

Essa resposta provavelmente já foi calculada:

```cpp
dp[2][2]
```

Então apenas somamos ao valor do item 3:

```cpp
dp[i][w] = dp[2][2] + value[3];
```

---

Portanto, temos que a fórmula do Knapsack 0-1 é:

```cpp
dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
```

---

## Implementação clássica (2D)

```cpp
vector<int> weight = {2, 3, 4, 5};
vector<int> value  = {3, 4, 5, 6};

int n = weight.size();
int W = 8;

int dp[n + 1][W + 1];
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

---

## Versão otimizada (1D)

```cpp
vector<int> dp(W + 1, 0);

for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

### Por que iteramos de trás para frente?

```cpp
for (int w = W; w >= weight[i]; w--)
```

Iteramos de trás para frente porque cada item só pode ser escolhido **uma única vez**.

Se percorrêssemos de frente para trás, quando atualizássemos `dp[w]`, poderíamos acabar usando um valor que já foi atualizado pelo próprio item atual, permitindo escolhê-lo mais de uma vez.

Percorrendo de trás para frente, sempre usamos os valores da iteração anterior, garantindo que cada item seja utilizado no máximo uma vez.

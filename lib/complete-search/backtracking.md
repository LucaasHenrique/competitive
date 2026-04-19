# Backtracking

um algoritmo de backtracking começa com a solução vazia e estende passo a passo.
a busca acontece de forma recursiva percorrendo por todas as possiveis maneiras que uma solução pode ser construida.

É uma busca exaustiva, mas que abandona um caminho assim que percebe que ele não levará a uma solução válida. Isso é chamado de poda (pruning).

***
Um exemplo classico é o problema de contar todas as formas que $N$ rainhas podem ser colocadas em tabuleiro de Xadrez $N X N$

> exatamente uma rainha será colocada em cada fileira para que nenhuma rainha ataque qualquer das rainhas colocadas antes. Uma solução foi encontrada quando todas as $N$ rainhas foram colocadas no quadro

possivel solução:

```c++
int n;
int count = 0;

bool column[100];
bool diag1[200]; // x + y
bool diag2[200]; // x - y + (n - 1)

void search(int y) {
    if (y == n) {
        count++;
        return;
    }

    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x + y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }   
}
```

é importante dizer que o numero soluções cresce de forma exponencial, então o algoritmo é otimo para casos pequenos

no pior caso o algoritmo possui complexidade de $O(N!)$

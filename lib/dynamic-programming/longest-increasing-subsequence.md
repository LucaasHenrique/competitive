Longest Increasing Subsequence
***

o problema trata de encontrar a maior subsequencia crescente em um array, isso é a maior sequencia da esquerda para a direita de um array em que cada elemento é maior que o anterior;

considere o array = {6, 2, 5, 1, 7, 4, 8, 3};

seja `length(k)` a maior LIS que termina na pos k, vamos calcular `length(k)` para todo k, onde 0 <= k <= n - 1;

por exemplo:

no array acima:

length(0) = 1;
length(1) = 1;
length(2) = 2;
length(3) = 1;
length(4) = 3;
length(5) = 2;
length(6) = 4;
length(7) = 2;

formando a subseq = 2 5 7 8

para calcular length(k) temos que encotrar um pos i < k em que `array[i] < array[k]` and length(i) seja o maior possivel.

então length(k) = length(i) + 1; se nao existe uma posição i que satisfaça => length(k) = 1;

implementation O(n²):

```c++
for (int k = 0; k < n; k++) {
    length[k] = 1;
    for (int i = 0; i < k; i++) {
        if (array[i] < array[k]) {
            length[k] = max(length[k], length[i] + 1);
        }
    }
}
```

porem existe uma solução em O(n log n):






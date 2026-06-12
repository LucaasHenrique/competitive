# Sliding window 

Sliding Window é um subarray de tamanho N que pode se mover para a direita ou esquerda no array.

basicamente a "janela" `[l, r]` vai deslizando pelo array evitando reprocessamento.

exemplo de problema: 

```
Given an array of n positive integers, your task is to count the number of subarrays having sum x.
```

solução: 

```c++
int i = 0;
    int j = 0;
    int sum = 0;
    int c = 0;
 
    while (i < n && j < n) {
        //cout << sum << "\n";
        sum += a[j];
        
        while (i <= j && sum > x) {
            sum -= a[i];
            i++;
        }
 
        if (sum == x) {
            c++;
            if (i <= j) {
                sum -= a[i];
                i++;
            }
        }
 
        j++;
    }
```

- Começamos a janela em (0, 0)
- Fazemos a soma acumulativa
    - Se soma ficou maior que o x desejado, movemo nossa janela a fim de diminuir a soma atual
    - Caso contrario, verificamos se soma == x, se sim, aumentamos novamente nossa janela procurando outro subarray de soma == x;
   

Esse algoritmo funciona apenas com elementos positivos, a soma da janela tem comportamento monotomico.

se aumentamos o ponteiro `r` -> a soma aumenta;
se aumentamos o ponteiro `l` para a direita -> a soma diminui, pois estou removendo o elemento da esquerda.
***
# Sliding Window Minimum

Nessa janela queremos descobrir o menor elemento presente.

Esse algoritmo é parecido com `Nearest Smaller Value`.

Aqui usamos uma queue onde cada elemento é maior que o anterior, é o primeiro elemento da queue sempre corresponde ao minimum elemento da janela atual.

Depois que a janela se move, removemos elementos do fim da queue ate que o ultimo elemento na fila seja menor que o novo elemento adicionado na janela ou queue ficar vazia.

Também removemos o primeiro elemento da fila caso ele não faça mais parte da janela atual.

Depois adicionamos o novo elemento da janela no fim da fila.

implementação:

```c++
vector<int> slidingWindowMinimum(vector<int>& a, int k) {
    deque<int> q; // armazenar indices dos elementos
    vector<int> result; // resultado para cada janela

    for (int i = 0; i < a.size(); i++) {
        while (!q.empty() && a[q.back()] >= a[i]) q.pop(); // elemento no final da fila é maior q o novo elemento da window.

        while (!q.empty() && q.front() <= i - k) q.pop_front(); // se o primeiro elemento da queue ja saiu da janela.

        q.push_back(i);

        if (i >= k - 1) result.push_back(a[q.front()]); // se a janela de tamanho k ja está completa.
    }

    return result;
}
```

A deque mantém uma sequência monotonicamente crescente de valores (mas armazena índices). O invariante é: `nums[dq[0]] ≤ nums[dq[1]] ≤ ... ≤ nums[dq.back()]`. 
Assim, o mínimo da janela está sempre no dq.front().

Quando um novo elemento x entra, qualquer elemento na cauda que seja ≥ x nunca mais poderá ser o mínimo — x está mais à frente no array e é menor ou igual. Podem ser descartados com segurança.

Complexidade: O(N);

implementação maximum element window

```c++
vector<int> slidingWindowMaximum(vector<int>& a, int k) {
    deque<int> q;
    vector<int> result;
    for (int i = 0; i < (int)a.size(); i++) {
        while (!q.empty() && a[q.back()] <= a[i]) q.pop_back(); // ✓
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        q.push_back(i);
        if (i >= k - 1) result.push_back(a[q.front()]);
    }
    return result;
}
```

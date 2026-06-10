# Nearest Smaller Value
***
O Nearest Smaller Value é um algoritmo que para cada elemento de um array, encontra o elemento mais proximo (à esquerda ou à direita) que seja estritamente menor.

- base de problemas como o `largest rectangle in histogram` e `sum of subarray minimums`.

approach:

quando `arr[i]` chega e o topo é >= `arr[i]`, o topo nunca será a resposta de ninguem daqui para frente, pois `arr[i]` está mais à direita e é menor, então sempre será uma resposta melhor do que o topo para qualquer elemento futuro.

menor a direita: 

Manter uma pilha monotônica crescente (do fundo ao topo). Sempre que um novo elemento `arr[i]` chega e é menor que o topo da pilha, o topo já tem sua resposta: `arr[i]` é o primeiro elemento menor que apareceu à sua direita. O topo é desempilhado e recebe `arr[i]` como resposta.
***

Implementação (Menor à esquerda):

```c++
vector<int> nearestSmallerLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        
        while (!s.empty() && s.top >= arr[i]) s.pop();

        if (!s.empty()) nse[i] = s.top();
        s.push(arr[i]);
    }

    return nse;
}
```

Menor à direita: 

```c++
vector<int> nearestSmallerRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1); 
    stack<int> st; 

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            ans[st.top()] = arr[i]; // arr[i] é a resposta do topo
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
```
***

# Next Greater Element

Mantemos uma pilha monotomica decrescente é dar um pop quando encontrar algo maior

approach:

quando `arr[i] > arr[topo]`, o topo finalmente encontrou seu "próximo maior", ele é `arr[i]`. Desempilhe e registre a resposta.

```c++
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1); 
    stack<int> st;           

    for (int i = 0; i < n; i++) {
        // enquanto topo for MENOR que arr[i], encontrei o NGE dele
        while (!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}
```

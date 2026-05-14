# Prefix Sum
***

`Prefix Sum` é uma técnica usada para calcular rapidamente a soma de qualquer subarray de um array.

A ideia é pré-calcular as somas acumuladas do array em `O(N)`, permitindo responder consultas de soma em `O(1)`.

---

# Indexação começando em 0

Dado o array:

```c++
A = [1, 4, 2, 7, 10]
```

Construímos o array de prefixos:

```c++
pref = [0, 1, 5, 7, 14, 24]
```

Onde:

```c++
pref[i] = soma dos i primeiros elementos
```

Ou seja:

```c++
pref[0] = 0
pref[1] = 1
pref[2] = 1 + 4 = 5
pref[3] = 1 + 4 + 2 = 7
pref[4] = 1 + 4 + 2 + 7 = 14
pref[5] = 1 + 4 + 2 + 7 + 10 = 24
```

A fórmula de construção é:

```c++
pref[i] = pref[i - 1] + A[i - 1]
```

para `i >= 1`.

***

## Soma de um intervalo `[L, R]`

Para descobrir a soma do intervalo `[L, R]`:

```c++
soma = pref[R + 1] - pref[L]
```

Exemplo:

```c++
A = [1, 4, 2, 7, 10]
```

Soma do intervalo `[1, 3]`:

```c++
4 + 2 + 7 = 13
```

Usando prefix sum:

```c++
pref[4] - pref[1]
= 14 - 1
= 13
```

***

## Implementação

```cpp
void solve() {
    int n = 5;

    vector<int> a = {1, 4, 2, 7, 10};

    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int L = 1, R = 3;

    int sum = pref[R + 1] - pref[L];

    cout << sum << "\n";
}
```

---

# Indexação começando em 1

Também podemos usar indexação começando em `1`.

Dado:

```c++
A = [1, 4, 2, 7, 10]
```

Construímos:

```c++
pref = [0, 1, 5, 7, 14, 24]
```

Agora:

```c++
pref[i] = soma dos elementos de 1 até i
```

A construção fica:

```c++
pref[i] = pref[i - 1] + A[i]
```

para `i >= 1`.

***

## Soma de um intervalo `[L, R]`

Nesse caso:

```c++
soma = pref[R] - pref[L - 1]
```

Exemplo:

```c++
A = [1, 4, 2, 7, 10]
```

Soma do intervalo `[2, 4]`:

```c++
4 + 2 + 7 = 13
```

Usando prefix sum:

```c++
pref[4] - pref[1]
= 14 - 1
= 13
```

***

## Implementação

```cpp
void solve() {
    int n = 5;

    vector<int> a(n + 1);

    a[1] = 1;
    a[2] = 4;
    a[3] = 2;
    a[4] = 7;
    a[5] = 10;

    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    int L = 2, R = 4;

    int sum = pref[R] - pref[L - 1];

    cout << sum << "\n";
}
```

***

## Complexidade

- Construção: `O(N)`
- Consulta de soma: `O(1)`

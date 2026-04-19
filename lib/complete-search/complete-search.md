## Gerando subconjuntos

Existem dois métodos comuns para gerar subconjuntos: podemos realizar uma busca recursiva ou explorar a representação de bits de inteiros.

Metodo 1: Recursão
```c++
void search(int k) {
	if (k == n) {
		// processa subconjunto
	} else {
		search(k+1);
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
	}
}
```

Quando a função search é chamada com o parâmetro k, ela decide se inclui
o elemento k no subconjunto ou não, e em ambos os casos, então chama a si
mesma com o parâmetro k +1. No entanto, se k = n, a função percebe que todos os elementos foram processados e um subconjunto foi gerado

Metodo 2: Representação de bits

Cada subset de um set de tamanho $N$ pode ser representado como uma sequencia de $N$ bits, que corresponde a um inteiro entre 0...$2^n -1$. Cada bit = 1 na sequencia representa o numero que está no subset, por exemplo:

{${0, 3, 4}$} pode ser representado como $11001$, por convenção lemos da direita para esquerda começando do 0.

```c++
for (int b = 0; b < (1<<n); b++) {
	vector<int> subset;
	for (int i = 0; i < n; i++) {
		if (b&(1<<i)) subset.push_back(i);
	}
}
```

## Gerando permutações

uma permutação é uma sequencia de tamanho $N$ onde aparecem 1....$N$ elementos de forma arbitraria, então:

$N=4$
{${1, 2, 3, 4}$} é uma permutação

gerando uma permutação de forma recursiva:

```c++
int n;
vector<int> permutation;
vector<bool> chosen(1000);

void search() {
    
    if (permutation.size() == n) {
        cout << "{";
        for (int x : permutation) cout << x << " ";
        cout << "}";
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
```



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

no pior caso o algoritmo possui complexidade de O(N!)

esse problema do CSES pode ser resolvido com essa ideia

```txt
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?
```

```
input: 

........
........
..*.....
........
........
.....**.
...*....
........


output: 65
```

minha solução:

```c++
int c = 0;
int n = 8;
 
bool column[100];
char diag1[200];
char diag2[200];
vector<string> grid(8);
 
void search(int y) {
    
    if (y == n) {
        c++;
        //for (int i = 0; i < 8; i++) {
        //    for (int j = 0; j < 8; j++) {
        //        cout << grid[i][j] << "";
        //    }
        //    cout << "\n";
        //}
        return;
    } 
    for (int x = 0; x < n; x++) {
        if (column[x] || grid[y][x] == '*' || grid[y][x] == 'd' || diag1[x+y] == 'd' || diag2[x-y+n-1] == 'd') continue;
        grid[y][x] = diag1[x+y] = diag2[x-y+n-1] = 'd'; column[x] = 1;
        search(y+1);
        grid[y][x] = diag1[x+y] = diag2[x-y+n-1] = '.'; column[x] = 0;
    }
 
}
 
void solve() {
    
    for (int i = 0; i < 8; i++) {
        getline(cin, grid[i]);
    }
    search(0);
    cout << c << "\n";
}
```

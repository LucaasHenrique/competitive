# Greddy Algorithms (Algoritmos Gulosos)

- Um algoritmo guloso construi a solução fazendo a escolha que parece ser a melhor no momento,
acreditando que isso vai levar a melhor solução global. Esse algoritmo nunca volta atras com sua escolha, mas continua construindo a solução mesmo q seja errada

- A pricipal dificuldade é encontrar uma estrategia gulosa que produza uma solução otima para o problema. As escolhas otimas locais também deve ser a escolha global otima

# Coin problem

temos um conjunto de moedas é nossa tarefa formar um determinado valor `x` usando o minimo de moedas possivel

set_of_coins = {1,2,5,10,20,50,100,200}

x = 520

a menor quantidade de moedas é 4 -> 200 + 200 + 100 + 20 = 520

é facil ver que a estrategia gulosa é sempre ir escolhendo o maior valor possivel de moeda, se `valor da moeda` <= `x` 
***

Nem sempre um algoritmo guloso produz uma solução otima, isso pode ser provado com o seguinte contraexemplo:

A = {1, 3, 4}

objetivo: Obter a soma 6 utlizando o menor de numeros de moedas possiveis.

Seguindo o algoritmo classico de pegar primeiro o maior elemento vamos obter como resposta a soma 4 + 1 + 1, porém a real solução otima seria 
3 + 3, usando o menor número de moedas. Em casos como esses podemos optar por uma solução usando Dynamic Programming.
***

# Scheduling

Problemas de agendamento podem ser resolvidos usando guloso.

problem: Dado N eventos com hora de inicio e hora de fim, encontre a maior quantidade de eventos que podem ser realizados sem que um evento começo no meio ou ao mesmo tempo que outro.

basicamente quero que seja de forma sequencial, uma acaba e outro começa.


| event | starting | ending |
|---|---|---|
| A | 1 | 3 |
| B | 2 | 5 |
| C | 3 | 9 |
| D | 6 | 8 |

nesse caso somente 2 eventos podem ser escolhidos.

nesse caso a solução ideal é ordenar todos eventos pelo horario de termino, e depois comparar o horario de incio do proximo com o horario de termino do atual

exemplo A e B;

A termina 3h e B começa 2h, logo B não pode ser escolhido

O problema classico desse tipo é o `Dentista` que caiu na OBI

minha resolução:

```c++
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.s < b.s;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> p;
    int o = n;
    while (n--) {
        int x, y; cin >> x >> y;
        p.pb({x, y});
    }
    
    sort(p.begin(), p.end(), comp);
    
    int t = 1;
    int x = p[0].f, y = p[0].s;
    for (int i = 1; i < o; i++) {
        if (p[i].f >= y) {
            t++;
            y = p[i].s;
        } 
    }

    cout << t << "\n";
}
```

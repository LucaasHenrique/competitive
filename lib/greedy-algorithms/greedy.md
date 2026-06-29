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

a solução ideal é ordenar todos eventos pelo horario de termino, e depois comparar o horario de incio do proximo com o horario de termino do atual

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
***
# Task and Deadlines 

Imagine que temos N tarefas com tempo de duração e prazo de termino e queremos encontrar uma ordem para fazer as tarefas. Para cada tarefa feita
ganhamos `D - X` pontos onde `D` é o prazo de termino e `X` o momento em que terminamos a tarefa. Qual o maior numero de pontos que podemos alcançar? 

Answer: 


| task | duration | deadline |
|---|---|---|
| A | 4 | 2 |
| B | 3 | 5 |
| C | 2 | 7 |
| D | 4 | 5 |


A solução otima é ordenar as tarefas pelo tempo de duração é pegar sempre a com menor tempo de duração no momento.

então a ordem fica:

2 -> 3 -> 4 -> 4 

a soma de pontos fica:

(7 - 2) + (5 - 5) + (2 - 9) + (5 - 13) = -10
***
# Minimizing Sums

Dado uma sequencia de numero de tamanho N onde `a1, a2, a3...aN`, nossa tarefa é encontrar um valor `x` que minimize a soma

`[a1 - x]^c + [a2 - x]^c + [a3 - x]^c ... + [aN - x]^c`

se `C = 1`:

temos que minimizar `[a1 - x] + [a2 - x] + ... + [aN - x]`

considere o array `[1,2,9,2,6]`, nesse caso a melhor solução é escolher `2`, pois:

`|1−2| +|2−2| +|9−2| +|2−2| +|6−2| = 12`

Nesse caso a melhor escolhar é pegar a mediana dos numeros de depois de aplicar uma ordenação 

`[1, 2, 2, 6, 9]`

A mediana garante a solução otima, pq se x for menor que a mediana a soma se torna minima ao aumentar x, e se x for maior que a mediana
a soma se torna menor ou diminuir x. se a sequencia tiver tamanho par ela possui 2 medianas basta escolha uma das duas é teremos a resposta otima.
***

Caso `C = 2`

Queremos minimizar a soma:

`(a1 − x)² + (a2 − x)² + ··· + (aN − x)²`

se o array for `[1,2,9,2,6]`, a melhor solução é escolher `x = 4`

que produz a soma: 

`(1−4)² +(2−4)² +(9−4)² +(2−4)² +(6−4)² = 46.`

nesse caso a melhor solução para x é escolher a media de todos os numeros, `[1 + 2 + 2 + 9 + 6] / 2 = 4`

para obter o resultado a soma pode ser representada como:

`nx² + 2x(a1 + a2 + a3 + .... + an)`

isso forma uma função quadratica nx² + 2xs, onde `s = (a1 + a2 + a3 + .... + an)`, isso forma uma parabola com concavidade virada para cima
nesse o ponto onde o minimo acontece é no X do vertice, que é dado pela formula x = -b/2a, fazendo os calculos chegaremos em x = s / n que é a media dos numeros.
***
# Another interval problem

```c++
void solve() {
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> a;

    forn (i, n) {
        ll aa, b; cin >> aa >> b;
        a.pb({aa, b, i});
    }

    sort(a.begin(), a.end());

    auto [st, et, idx] = a[0];
    vector<int> rooms(n);
    multiset<pair<int, int>> e_r;

    rooms[idx] = 1;
    e_r.emplace(et, 1);

    for (int i = 1; i< n; i++) {
        auto [st, et, idx] = a[i];
        
        auto [smaller, rid] = *begin(e_r);
        if (smaller < st) {
            e_r.erase(e_r.begin());
            rooms[idx] = rid;
            e_r.emplace(et, rid);
        } else {
            rooms[idx] = len(e_r) + 1;
            e_r.emplace(et, rooms[idx]);
        }
    }

    cout << *max_element(rooms.begin(), rooms.end()) << "\n";
    for (auto r: rooms) cout << r << " ";
    cout << "\n";
}
```

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

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




# Bit Manipulation
***

shift operators:

>> desloca os bits para a direita, cada deslocamento representa um divisão por 2. Um deslocamento por k representa um divisão inteira por 2^k

5 >> 2 => 101 >> 2 => 1 

<< desloca os bits para a esquerda, cada deslocamento representa uma multiplicação por 2. Deslocamento por k é igual uma multiplicação por 2^k 
***


check if a bit is set 

para checar se o x-th bit está ligado fazemos o deslocamento do numero em x posições para a direita.

```c++
bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}
```

ex: verficar se o numero da segunda posição está ligado.

number = 5 
x = 2 

5 >> 2 
101 >> 2 

``` 
001 
001 & 
---
001
```

o bit esta ligado
***

verifcar se um numero é divisivel por potencia de  2: 

```c++ 
bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}
```

2^k => 1 seguido de k zeros 

2¹ - 1 => 01
2² - 1 => 011
2³ - 1 => 0111
2^k - 1 => k bits 1 seguidos 

quando n & 2^k - 1, se os ultimos k bits forem 0, n é divisivel.
***

verificar se um inteiro é potencia de 2 

```c++
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}
```
***

retornar o bit menos significativo 

```c++
int lsb(int x){
  return x & -x;
}

lsb(5); // 1 
```
***

contar numero de bits 1 

```c++
int count_bits(int x){
  int ret = 0;
  while(x != 0){
    ++ret;
    x -= x&-x;
  }
  return ret;
}

count_bits(5); // 2 
```
*** 

bits necessarios para representar um numero 

```c++
int number_of_bits(int number) {
  int count = 0;
  while (number > 0) {
    number >>= 1;
    count++;
  }
  return count;
}

number_of_bits(5); // 3
```

ligar e desligr um bit 

```c++
int x = 5; // 101 em binário

x |= (1 << 1); // x = 7 (111 em binário) 


int x = 5; // 101 em binário

x |= (1 << 2) // garantimos que o terceiro bit está ligado

x ^= (1 << 2) // x = 1 (001 em binário)
```

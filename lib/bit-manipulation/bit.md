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
***

questions:

```
In the final of the Tengo-lengo-tengo Football World Cup, the stadium light show is the highlight of halftime while several artists perform on stage. Each spotlight configuration is represented by a binary number with exactly 3
 bits: bit 0
 means a light is off, and bit 1
 means a light is on.

To make the halftime show look smooth, the organizers want the lights to change calmly. Therefore, from one configuration to the next, exactly one spotlight must change state.

You are given an initial configuration X0
. Your task is to produce a sequence that starts at X0
, visits all 8
 configurations of 3
 bits exactly once, and then returns to X0
.
```

```
input:

010

output:

010
110
111
101
100
000
001
011
010
```

1. o proximo binario deve ter exatemente um bit diferente em relação ao anterior e nao pode ser repetido
2. podemos pegar o binario e testar uma inversão em cada um de seus bits.
3. Para saber se difere em um bit, bastar fazer o xor entre o anterior e o atual.
4. Todo binario q possui somente um digito ligado é potencia de 2, se o xor tiver como resultado um binario como 010, então o o binario gerado é valido.

```c++
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}
 
void solve() {
    string s; cin >> s;
 
    cout << s << "\n";
 
    int aux = stoi(s, nullptr, 2);
    int o_aux = aux;
    set<int> st;
    st.insert(aux);
    
    for (int i = 1; i <= 9; i++) {
        int diff = 0;
        bool r = false;
        for (int j = 0; j < 3 && !r; j++) {
            int c = aux ^ (1 << j);
            
            diff = c ^ o_aux;
            if (isPowerOfTwo(diff) && !st.count(c)) {
                r = true;
                aux = c;
                o_aux = c;
                st.insert(c);
                break;
            } else diff = 0;
        }
 
        string ts = bitset<3>(o_aux).to_string();
        if (r) cout << ts << "\n";
    }
 
    cout << s << "\n";
}
```

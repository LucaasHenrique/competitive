# Exponenciação rápida

- no c++ existe a função `pow(a, b)` que usada para exponenciação, porem porem possui complexidade `O(n)`
- Em caso de um `n` mt grande essa não será a maneira mais eficiente de calcular a potência.

***
Dado A, N e M, calcule A^N mod M 

solução ingênua O(n):

```c++
int expLenta(int base, int exp, int mod){
  int res = 1;
  for(int i=0; i<exp; i++)
    res = (res*1LL*base)%mod;
  return res;
}
```
***

solução O(log(n))

- dividir a exponenciação em partes, por exeplo em potencias de 2:

A¹⁴ = A⁸ * A⁴ * A²

```c++
int expRapida(int base, long long exp, int mod){
  int res = 1;
  while(exp>0){
    if(exp&1LL) 
      res = (res*1LL*base)%mod;
    base = (base*1LL*base)%mod;
    exp = exp>>1;
  }
  return res;
}
```
***


```c++
int Exp(int x, int n)
{
    // caso base
	if (n == 0) return 1;

	int t = Exp(x, n/2);

	if (n%2 == 1) return a*t*t; // caso ímpar
  
	return t*t; // caso par
}
```


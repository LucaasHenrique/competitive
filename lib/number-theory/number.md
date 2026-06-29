# Number Theory - posniak
***
Soma dos n primeiros elementos:

```Sum = n * (n + 1) / 2;```

***
Encontra todos os divisores de um numero em O(raiz de N):

```c++
vector<long long> buscar_divisores(long long n) {
    vector<long long> divisores;
    
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisores.push_back(i); // i é um divisor

            if (i != n / i) {
                divisores.push_back(n / i);
            }
        }
    }
    
    sort(divisores.begin(), divisores.end());
    
    return divisores;
}
```


# Primos 

Verifica se um numero é primo em O(raiz de N):

```c++
bool is_prime(int n) {
    
    if (int == 1) return false;
    
    int c = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}
```

Teorema fundamental da aritmetica:

- Todo numero inteiro maior que 1 pode ser representado de forma unica como um produto de numeros primos desconsiderando a ordem dos fatores.

60 = 2² * 3 * 5;
11732 = 2² * 7 * 419;
***

se p é primo entao GCD(a, p) é 1 ou p

gcd = 1, não implica que a ou p seja primos. gcd(15, 49) = 1;

se a e p são primos, logo gcd(a, p) = 1;

se a e b são naturais, então gcd(a, b).lcm(a, b) = a, b;

como encontrar o maior expoente de um numero primo p que divide n!?

formula de legendre: 

vp = (n!) = sum(n / p^i) onde i = 1 e vai ate o infinito

porem calculamos somente ate p^i ser maior que o dividendo.

sejam A, B, N numeros inteiros. Dizemos que A é congruente a B modulo N, e escrevemos:

A congruente B (mod N)

exemplo: 

17 congruente 3 (mod 7) porque 3 mod 7 = 17 mod 7

se A congrunte B (mod N), entao A^k congruente B^k (mod N), para todo k pertencente aos naturais.

# Fatorização em primos

```c++
vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}
```

***
# GCD


```c++ 
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
```

# Least common multiple

```c++
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
```

# Dica

usar python para quando o problem exige numeros gigantes.

por exemplo no problema abaixo a entrada é n <= 10¹⁰⁰⁰⁰⁰ o python aguente receber e converter valores desse tamanho:

```python
import sys
sys.set_int_max_str_digits(150000)

n = int(input());

t1 = pow(1, n, 5)
t2 = pow(2, n, 5) 
t3 = pow(3, n, 5)
t4 = pow(4, n, 5)

print((t1+t2+t3+t4) % 5)
```

alem de que o python ja possui implementação de  exponenciação rapida.

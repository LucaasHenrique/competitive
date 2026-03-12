// Curso Noic de Informática - Busca Binária
// Exemplo: Pão a Metro - 2a fase OBI P1 2007
// Lúcio Figueiredo

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int N, M;
int m[maxn]; // comprimentos dos pães

// retorna verdadeiro se f(x) >= N
// onde f(x) = m_1/x + m_2/x + ... + m_M/x
bool ok(int x)
{
	int soma = 0;

	for (int i = 1; i <= M; i++)
		soma += (m[i]/x); // parte inteira de m[i]/x

	return (soma >= N); // retorna true se soma >= N, false caso contrário
}

// calcula a maior fatia do problema
int busca(void)
{
	int ini = 1, fim = 10000;
	int ans; // resposta do problema encontrada pela busca binária

	while (ini <= fim)
	{
		int mid = (ini+fim)/2; // meio do intervalo

		if (ok(mid)) // se f(mid) >= N
		{
			ans = mid; // possível resposta
			ini = mid+1; // reduzo o intervalo para a metade  direita
		}
		else fim = mid-1; // reduzo o intervalo para a metade esquerda, chutei muito alto e f(x) < N
	}

	return ans;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
		scanf("%d", &m[i]);

	printf("%d\n", busca());
}

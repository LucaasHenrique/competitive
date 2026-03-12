// Curso Noic de Informática - Busca Binária
// Exemplo: Lower Bound em O(log n)
// Lúcio Figueiredo

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n; // tamanho do vetor
int V[maxn] = {5, 6, 8, 9, 12, 13, 20, 50, 90};

// responde a pergunta para um valor x
int busca(int x)
{
	int ini = 1, fim = n;
	int ans = -1; // resposta da pergunta, que inicialmente será -1

	while (ini <= fim)
	{
		int mid = (ini+fim)/2; // meio do intervalo

		if (V[mid] >= x)
		{
			ans = V[mid]; // possível resposta
			fim = mid-1; // reduzo o intervalo para a metade esquerda
		}
		else ini = mid+1; // reduzo o intervalo para a metade direita, já que V[mid] < x
	}

	return ans;
}

int main (int argc, char *argv[]) {
    
    cout << busca(8) << "\n";
    return 0;
}

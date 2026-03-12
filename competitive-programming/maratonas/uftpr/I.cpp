#include <bits/stdc++.h>

using namespace std;

int main() {

	int dimensao_matriz, x_resposta, y_resposta;
	char receptor_de_valores;

	cin >> dimensao_matriz;

	x_resposta = 1;
	y_resposta = dimensao_matriz;

	for (int i=1; i<=dimensao_matriz; i++) {
		int posicao_x = i%dimensao_matriz, posicao_y = i/dimensao_matriz;
		cin >> receptor_de_valores;
		if ( receptor_de_valores == '#' && posicao_y < y_resposta && posicao_x > x_resposta ) {
			x_resposta = posicao_x;
			y_resposta = posicao_y;
		}
	}

	cout << "(" << x_resposta << ", " << y_resposta << ")\n";

	return 0;

}


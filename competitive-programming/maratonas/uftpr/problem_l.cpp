#include <bits/stdc++.h>


using namespace std;

int main() {

	int dimensao_matriz, x_resposta, y_resposta;
	char receptor_de_valores[2];

	cin >> dimensao_matriz;

	x_resposta = 1;
	y_resposta = dimensao_matriz;

	for (int i=0; i<dimensao_matriz*dimensao_matriz; i++) {
		int posicao_x = i%dimensao_matriz+1, posicao_y = ceil(i/dimensao_matriz)+1;
		cin >> receptor_de_valores[0];
		if ( receptor_de_valores[0] == '#' && posicao_y <= y_resposta && posicao_x > x_resposta ) {
			x_resposta = posicao_x;
			y_resposta = posicao_y;
		}
	}

	cout << "(" << y_resposta << ", "<< x_resposta << ")" <<endl;

	return 0;

}


#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    
    int idade = 1;
    bool vivo = true;
    char letra = 'a';
    double dolar = 1.5;

    std::cout << dolar << endl;

    vivo = false;
    dolar += 1;

    std::cout << dolar << endl;

    double newDolar;

    cin >> newDolar;

    std::cout << newDolar << endl;

    return 0;
}

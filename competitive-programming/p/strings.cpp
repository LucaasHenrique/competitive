#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    
    string om = "ola";

    string nome;
    cin >> nome;

    om += "in chains";
    
    string sobrenome = "silva";
    nome += " " + sobrenome;

    cout << nome.size() << "\n";

    cout << nome[2] << "\n";

    cout << om << "\n";

    return 0;
}

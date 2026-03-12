#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    // aritimetica modular simples:
    int ana = (1 + A) % 3;
    int bea = (1 + B) % 3;

    // Se cair na cadeira da Ana, ela pula para a próxima no sentido anti-horário
    if (bea == ana)
        bea = (bea + 1) % 3;
    
    // Como há só 3 cadeiras, podemos sempre fazer as contagens com % 3.

    int carol;
    for (int i = 0; i < 3; i++) {
        if (i != ana && i != bea) {
            carol = i;
            break;
        }
    }

    cout << carol << endl;
    return 0;
}


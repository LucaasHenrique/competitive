#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, sum = 0;
    cin >> N;
    

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    cout << sum;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int sum = 0;
    string word;
    cin >> word;
    
    for (int i = 0; i < word.length(); i++) {
        int inversa = 'z' - (word[i] - 'a');
        sum += inversa - 96;
    }
    
    cout << sum;

    return 0;
}

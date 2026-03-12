#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, A;
    cin >> N;

    int sumB = 0, sumA = 0;
    int nums[N];

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int maior = nums[0];   
    int indice = 0;

    for (int i = 0; i < N; i++) {    
        if (nums[i] > maior) {
            indice = i;
            maior = nums[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (i < indice) {
            sumB += nums[i];
        }

        if (i > indice) {
            sumA += nums[i];
        }
    }
    
    cout << sumB << "\n" << sumA << endl;

    return 0;
}

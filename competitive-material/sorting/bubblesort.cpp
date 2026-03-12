#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int n = 8;
    int array[8] = {9, 2, 4 , 1, 10, 3, 15, 12};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}

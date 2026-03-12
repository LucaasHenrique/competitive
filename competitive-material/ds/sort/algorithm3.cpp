#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {5, 1, 4, 2, 3};
    vector<int> B = {3, 6, 5};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end()); 

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            cout << A[i] << " pertence a interseção\n";
            i++; j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
}


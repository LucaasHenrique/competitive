#include <bits/stdc++.h>

using namespace std;

int sumRange(vector<int> values, int left, int right) {
    int sum = 0;
    for (size_t i = left; i <= right; i++) {
        sum += values[i];
    }

    return sum;
}

int main (int argc, char *argv[]) {
    
    vector<int> rr = {5, 6, 7, 1, 10, 2, 4};

    cout << sumRange(rr, 2, 6) << "\n";

    return 0;
}

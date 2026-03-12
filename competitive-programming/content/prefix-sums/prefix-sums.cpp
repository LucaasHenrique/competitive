#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_sum(vector<int> arr) {
    vector<int> prefix(arr.size());
    
    prefix[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

int main (int argc, char *argv[]) {
    
    vector<int> arr = {5, 6, 2, 2, 1, 10};

    for (int m: prefix_sum(arr)) {
        cout << m << " ";
    }

    return 0;
}

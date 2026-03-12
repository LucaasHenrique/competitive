#include <bits/stdc++.h>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {
    
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 6, 5};

    set<int> s(A.begin(), A.end());

    for (int b: B) {
        if (s.find(b) != s.end()) {
            cout << b << " pertence a A\n";
        } else {
            cout << b << " não pertence a A\n";
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

vector<int> applyPermute(vector<int> sequence, vector<int> permutation) {
    vector<int> newSequence(sequence.size());
    for (int i = 0; i < sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }
    
    return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, ll k) {
    while (k > 0) {
        if (k & 1) {
            sequence = applyPermute(sequence, permutation);
        }

        permutation = applyPermute(permutation, permutation);
        k >>= 1;
    }

    return sequence;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {4, 5, 3, 2, 1};
    vector<int> b = {4, 3, 2, 5, 4};
    for (int s: permute(a, b, 7)){
        cout << s << " ";
    }
    return 0;
}

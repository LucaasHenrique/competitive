#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

long pilesOfBoxes(vector<int> boxesInPiles) {
    long c = 0;
    /*for (int i = 0; i < boxesInPiles.size() - 1; i++) {
        if (boxesInPiles[i] > boxesInPiles[i+1]) {
            boxesInPiles[i] = abs(boxesInPiles[i]-boxesInPiles[i+1]);
        }
    }*/

    int i = 0;
    while (i < boxesInPiles.size() - 1) {
        if (boxesInPiles[i] > boxesInPiles[i+1]) {
            boxesInPiles[i] = abs(boxesInPiles[i]-boxesInPiles[i+1]);
            c++;
        }

        i++;

        if (i == boxesInPiles.size() - 1) {
           i = 0; 
           if (boxesInPiles[i] == boxesInPiles[i + 1]) {
                break;
            }    
        }
    }

    return c;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << pilesOfBoxes({4, 5, 5, 2, 4});

    return 0;
}

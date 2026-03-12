#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
     
    int N, tot = 0;
    cin >> N;
    int nums[N];

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < N; i++) {
        if (nums[i] != nums[i + 1]) {
            tot += 1;
        }
    }

    cout << tot;
    return 0;
}

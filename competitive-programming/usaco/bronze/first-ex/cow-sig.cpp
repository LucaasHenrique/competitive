#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, K;
    cin >> M >> N >> K;
    string arr[1000];
    string c;

    for (int i = 0; i < M; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++) {
        string temp = "";
        for (int j = 0; j < N; j++) for (int l = 0; l < K; l++) temp+=arr[i][j];
        for (int j = 0; j < K; j++) c+=temp + '\n';
    } 
    
    cout << c;

    return 0;
}

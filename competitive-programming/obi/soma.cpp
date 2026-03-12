#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+10;
int n, k, x;
int v[maxn], a[maxn];
long long resp;

int buscab(int u) {
    int ini = u, fim = n, meio, resp = -1;

    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (v[meio] - v[u - 1] == k) {
            resp = meio;
            ini = meio + 1;
        } 

        else if (v[meio]-v[u-1] > k) fim = meio - 1;
        else ini = meio + 1;
    }

    return resp;
}

int main (int argc, char *argv[]) {

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x;
        v[i+1] = v[i] + x;
        if (v[i + 1] == v[i]) {
            a[i + 1] = a[i];
        }
        else a[i + 1] = i+1;

    }

    for (int i = 1; i < n; i++) {
        int temp = buscab(i);
        if (temp != -1) {
            resp += (long long) (temp-max(i, a[temp])+1);
        }
    }
    
    cout << resp;
    return 0;
}

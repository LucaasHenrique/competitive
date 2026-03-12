#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    
    int c = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for (int i = 0; i <n; i++) {cin >> a[i];
        if (a[i] == 1) a1++;
        if (a[i] == 2) a2++;
        if (a[i] == 3) a3++;
        if (a[i] == 4) a4++;
    }
    
    c += a4; a4 = 0;
    if (a2 ) {
        int t = a2 >> 1; // desloca um bit para a direta -> o mesmo q fazer a divisão inteira por 2;
        c += t;
        a2 -= t * 2; // se a2 = 4 tenho 4 grupo de 2 pessoas, dividindo por 2 isso significa q posso faze dois grupos de 4;
    }
    if (a1  && a3 ) {
        int minv = min(a1, a3);
        c += minv;
        a1 -= minv;
        a3 -= minv;
        // se a1 = 3 e a3 = 3, isso significa q posso juntar todos em apenas 3 grupos
        // se a1 = 1 e a3 = 2 isso significa q posso forma apenas um grupo de 4 juntando um gp de 1 e outro de 3;
    }
    if (a1 && a2) {
        // vai verificar tenho pares suficinetes de grupos de 1 para usar todos os grupos de 2;
        // se a1 = 6, a1 >> 1 -> 3 | 3 grupos com duas pessoas | se a2 = 2, a2 < 3, entao posso ter 1 taxi com 1 gp de 2 + 1 gp de 2
        // e mais um taxi com um gp de 2 + 1 gp de 2; sobrando ainda um grupo de 2 formado de gps de 1, mas o gp de 2 originais foram todos usados; 
        if (a2 <= a1>>1 && a1 >> 1) {
            c += a2;
            a1 -= a2*2;
            a2 -= a2;
        } else {
            int z = min(a1, a2);
            c += z;
            a1 -= z;
            a2 -= z;
        }
    }

    int y = a1 / 4;
    c += y;
    a1 -= y*4;

    if (a1 < 4 && a1) {
        c+=1;
        a1 = 0;
    }

    c += a1 + a2 + a3 + a4;

    cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

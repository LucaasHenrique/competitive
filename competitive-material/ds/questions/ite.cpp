#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    vector<int> v = {5, 3, 3, 9, 0, 4, 2, 10};

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    //random_shuffle(v.begin(), v.end());

    /*for (auto x: v) {
        cout << x << " ";
    }*/
    
    set<int> s = {3, 4, 2, 1};
    auto it = s.begin();
    
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    
    cout << endl;

    auto ite = s.end(); ite--;
    cout << *ite << endl;

    it = s.find(6);
    if (it == s.end()) {
        // x nao foi encontrado
        cout << 0;
    }

    cout << endl;
    
    int x = 5;

    it = s.lower_bound(x);
    if (it == s.begin()) {
        cout << *it << "\n";
    } else if (it == s.end()) {
        it--;
        cout << *it << "\n";
    } else {
        int a = *it; it--;
        int b = *it;
        
        if (x-b < a-x) cout << b << "\n";
        
        else cout << a << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
#include <ios>
#include <string>

using namespace std;

int binary_search(vector<int> list, int x) {
    int a = 0, b = list.size() - 1;

    while (a <= b) {
        int k = (a+b) / 2;

        if (list[k] == x) {
            return k;
        }
    
        if (list[k] > x) b = k - 1;
        else a = k + 1;
    }

    return -1; 
}

int binary_search2(vector<int> list, int x) {
    int k = 0;
    for (int b = list.size()/2; b >= 1; b /= 2) {
        while (k+b < list.size() && list[k+b] <= x) k += b;
    }
    
    if (list[k] == x) {
        return k;
    }

    return -1; 
}

int main (int argc, char *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> list = {6, 7, 3, 1, 2, 4, 6, 9};
    sort(list.begin(), list.end());
    
    int x; cin >> x;

    int pos = binary_search2(list, x);
    cout << (pos == -1 ? "element not found" : ("element found at position: " + to_string(pos))) << endl; 

    return 0;
}

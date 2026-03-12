#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

int main (int argc, char *argv[]) {
    
    vector<int> v = {5, 6, 2, 1, 2, 9};
    sort(v.begin(), v.end(), comp);
    
    return 0;
}

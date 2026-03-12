#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int n = 6;
    int s[n] = {4, 2, 1, 6, 7, 3};
    sort(s, s+n);

    vector<int> v = {4, 2, 1, 6, 7, 3};
    sort(v.begin(), v.end());

    string st = "monkey";
    sort(st.begin(), st.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } 
    
    cout << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << s[i] << " ";
    }
    
    cout << st;

    //////////////////////////////////////////////
    
    vector<pair<int, int>> p;
    p.push_back({1,5});
    p.push_back({2,3});
    p.push_back({1,2});

    sort(p.begin(), p.end());

    vector<tuple<int,int,int>> t;
    t.push_back({2,1,4});
    t.push_back({1,5,3});
    t.push_back({2,1,3});
    sort(t.begin(), t.end());



    return 0;
}

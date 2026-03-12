#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int M, N; cin >> M >> N;
    
    map<string, int> dic;
    
    for (int i = 0; i < M; i++) {
        string des; cin >> des;
        int s; cin >> s;
        
        dic[des] = s;
    }
    
    string w;
    vector<string> desc;
    int c = 0;    

    while (c != N) {
        cin >> w;
        desc.push_back(w);
        if (w == ".") {
           c++;
        }
    }

    vector<int> soma;
    int s = 0;
    
    for (int i = 0; i < desc.size(); i++) {
        if (dic.find(desc[i]) != dic.end()) {
            s += dic[desc[i]];
        } 

        if (desc[i] == ".") {
            soma.push_back(s);
            s = 0;
        }
    }

    for (auto s: soma) {
        cout << s << endl;
    }

    return 0;
}

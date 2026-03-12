#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    string word;
    cin >> word;

    char alford[26];
    char alfinverso[26];

    for (int i = 0; i < 26; i++) {
        alford[i] = 'a' + i;         
        alfinverso[i] = 'z' - i;
    } 

    //for (int i = 0; word.length(); i++) {
        //for (int j = 0; i < 26; i++) {
            
        //}
    //}

    cout << alford[0] << alfinverso[0];

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int countSubarrays(vector<int>& arr, int k) {
    unordered_map<int, int> freq; 
    freq[0] = 1; 
    
    int count = 0;
    int prefix = 0;
    
    for (int x : arr) {
        prefix += x; 
        
        if (freq.find(prefix - k) != freq.end()) {
            count += freq[prefix - k];
        }
        
        freq[prefix]++;
    }
    
    return count;
}


int main (int argc, char *argv[]) {
    
    vector<int> rr = {1, 1, 1};
    cout << countSubarrays(rr, 2) << "\n";

    return 0;
}

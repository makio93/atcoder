#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> a(n);
        a[0] = first;
        for (int i=0; i<n-1; ++i) a[i+1] = a[i] ^ encoded[i];
        return a;
    }
};

int main(){
    
    return 0;
}

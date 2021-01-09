#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> arr;
        while (n > 0) {
            arr.push_back(n%10);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        if (!next_permutation(arr.begin(), arr.end())) return -1;
        long long number = 0;
        for (int i=0; i<(int)(arr.size()); ++i) {
            number *= 10;
            number += arr[i];
        }
        if (number >= (long long)(1LL<<31)) return -1;
        return (int)(number);
    }
};

int main(){

    return 0;
}

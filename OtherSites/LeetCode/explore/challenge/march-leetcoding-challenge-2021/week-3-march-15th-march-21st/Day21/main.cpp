#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        bool ans = false;
        string ori = to_string(N);
        sort(ori.rbegin(), ori.rend());
        for (int i=0; i<=30; ++i) {
            string tar = to_string((1<<i));
            sort(tar.rbegin(), tar.rend());
            if (tar == ori) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}

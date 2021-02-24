#include <bits/stdc++.h>
using namespace std;

class CreateMixture {
public:
    vector<int> mix(int concentration) {
        vector<int> res;
        if (concentration==0 || concentration==1000) return res;
        int val = concentration;
        for (int i=0; i<3; ++i) {
            if (val == 0) break;
            int ten = 1;
            for (int j=0; j<2-i; ++j) ten *= 10;
            int cval = val / ten;
            val = val % ten;
            for (int j=0; j<10; ++j) {
                if (j < cval) res.push_back(i*2+1);
                else res.push_back(i*2);
            }
            if (i<2) {
                for (int j=0; j<10; ++j) {
                    if (j < cval+1) res.push_back(i*2+1);
                    else res.push_back(i*2);
                }
            }
        }
        return res;
    }
};

int main(){
    return 0;
}

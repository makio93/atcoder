#include <bits/stdc++.h>
using namespace std;

class HouseNumbering {
public:
    vector<int> prepareDigits(int firstHouse, int numberOfHouses) {
        vector<int> res(10);
        for (int i=0,d=0; i<numberOfHouses; ++i,d+=2) {
            int nval = firstHouse + d;
            while (nval > 0) {
                res[nval%10]++;
                nval /= 10;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}

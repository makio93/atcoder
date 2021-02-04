#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        vector<int> zeros;
        if (flowerbed.front() == 0) zeros.push_back(1);
        for (int i=1; i<m; ++i) {
            if (flowerbed[i] == 0) {
                if (flowerbed[i-1] == 0) zeros.back()++;
                else zeros.push_back(1);
            }
        }
        if (flowerbed.front() == 0) zeros.front()++;
        if (flowerbed.back() == 0) zeros.back()++;
        int sum = 0;
        for (int i=0; i<(int)(zeros.size()); ++i) sum += (zeros[i]-1)/2;
        return (n <= sum);
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> m;
    vector<int> flowerbed(m);
    for (int i=0; i<m; ++i) cin >> flowerbed[i];
    cin >> n;
    if (cl.canPlaceFlowers(flowerbed, n)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

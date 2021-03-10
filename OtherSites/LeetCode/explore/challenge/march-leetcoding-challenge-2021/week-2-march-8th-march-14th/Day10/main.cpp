#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> dic = { {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"},
        {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"} };
        string res;
        for (int i=0; i<(int)(dic.size()); ++i) {
            if (dic[i].first > num) continue;
            while (num >= dic[i].first) {
                res += dic[i].second;
                num -= dic[i].first;
            }
        }
        return res;
    }
};

int main(){
    Solution cl;
    int num;
    cin >> num;
    cout << cl.intToRoman(num) << endl;
    return 0;
}

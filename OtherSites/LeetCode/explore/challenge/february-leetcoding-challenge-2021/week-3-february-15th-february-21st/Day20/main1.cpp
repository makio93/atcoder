#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> dic = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        unordered_map<string, int> dic2 = {{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
        int val = 0;
        for (int i=0; i<n; ++i) {
            if (i+1<n && dic2.find(s.substr(i,2))!=dic2.end()) {
                val += dic2[s.substr(i,2)];
                ++i;
            }
            else val += dic[s[i]];
        }
        return val;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    cout <<  cl.romanToInt(s) << endl;
    return 0;
}

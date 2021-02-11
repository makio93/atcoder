#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};

int main(){
    Solution cl;
    string s, t;
    cin >> s >> t;
    if (cl.isAnagram(s, t)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class CoolPairsEasy {
public:
    int count(vector<string> firstname, vector<string> lastname) {
        int n = firstname.size(), cnt = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            if (i == j) continue;
            if (lastname[i] == firstname[j]) ++cnt;
        }
        return cnt;
    }
};

int main(){
    return 0;
}

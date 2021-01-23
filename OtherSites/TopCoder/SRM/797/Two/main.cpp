#include <bits/stdc++.h>
using namespace std;

class OrganicChemistry {
public:
    int countHydrogens(string atoms, vector<int> X, vector<int> Y) {
        int n = atoms.size(), m = X.size();
        vector<int> cnt(n);
        const string tar = "ONC";
        for (int i=0; i<n; ++i) {
            for (int j=0; j<3; ++j) if (atoms[i] == tar[j]) cnt[i] = j+2;
        }
        for (int i=0; i<m; ++i) {
            cnt[X[i]]--;
            cnt[Y[i]]--;
        }
        int sum = 0;
        for (int i=0; i<n; ++i) sum += cnt[i];
        return sum;
    }
};

int main(){
    return 0;
}

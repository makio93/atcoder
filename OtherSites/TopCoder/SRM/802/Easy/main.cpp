#include <bits/stdc++.h>
using namespace std;

class BallotCounting {
public:
    int count(string votes) {
        int n = votes.length(), x = n;
        vector<int> cnt(2);
        for (int i=0; i<n; ++i) {
            if (votes[i] == 'A') cnt[0]++;
            else cnt[1]++;
            if (cnt[0]>n/2 || cnt[1]>n/2) {
                x = i+1;
                break;
            }
        }
        return x;
    }
};

int main(){
    return 0;
}

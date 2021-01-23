#include <bits/stdc++.h>
using namespace std;

class LogiciansAndBeer {
public:
    int bringBeer(string responses) {
        int n = responses.size();
        int cnt = 0;
        bool fin = false;
        for (int i=0; i<n; ++i) {
            if (responses[i]=='+' && i<n-1) return -1;
            if (fin) {
                if (responses[i] != '-') return -1;
            }
            if (!fin) {
                if (responses[i]=='+' && i==n-1) ++cnt;
                else {
                    if (responses[i] == '?') ++cnt;
                    else fin = true;
                }
            }
        }
        return cnt;
    }
};

int main(){
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class BuyOneGetOneFree {
public:
    int buy(vector<int> prices) {
        int n = prices.size();
        sort(prices.rbegin(), prices.rend());
        int sum = 0;
        for (int i=1; i<n; ++i) sum += prices[i];
        return sum;
    }
};

int main(){
    return 0;
}

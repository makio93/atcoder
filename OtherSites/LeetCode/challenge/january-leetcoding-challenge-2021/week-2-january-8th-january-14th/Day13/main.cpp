#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int l = 0, r = n;
        while (l < r) {
            r = distance(people.begin(), upper_bound(people.begin()+l+1, people.begin()+r, limit-people[l])) - 1;
            ++l;
        }
        return (n-min(l,r));
    }
};

int main(){
    
    return 0;
}

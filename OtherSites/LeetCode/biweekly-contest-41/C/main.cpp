#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> sub(n);
        for (int i=0; i<n; ++i) sub[i] = {aliceValues[i]+bobValues[i], i};
        sort(sub.rbegin(), sub.rend());
        int sum1 = 0, sum2 = 0;
        for (int i=0; i<n; ++i) {
            if (i%2==0) sum1 += aliceValues[sub[i].second];
            else sum2 += bobValues[sub[i].second];
        }
        if (sum1 > sum2) return 1;
        else if (sum1 < sum2) return -1;
        else return 0;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vi aliceValues(n), bobValues(n);
    rep(i, n) cin >> aliceValues[i];
    rep(i, n) cin >> bobValues[i];
    int res = cl.stoneGameVI(aliceValues, bobValues);
    cout << res << endl;
    return 0;
}

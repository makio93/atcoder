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
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> run;
        if (nums[0] == 1) run.emplace_back(1, 0);
        for (int i=1; i<n; ++i) {
            if (nums[i] == 0) continue;
            if (nums[i-1] == 1) run.back().first++;
            else run.emplace_back(1, i);
        }
        pair<int, pair<int, int>> mxlen = {0, {-1, -1}}, mxlen2 = {0, {-1, -1}};
        for (int i=0; i<(int)(run.size()); ++i) {
            mxlen = max(mxlen, {run[i].first, {run[i].second, i}});
            if (i>0 && i<(int)(run.size())-1) mxlen2 = max(mxlen2, {run[i].first, {run[i].second, i}});
        }
        if (mxlen.first >= k) return 0;
        vector<int> st, st2;
        int ladd = 0;
        for (int i=mxlen.second.second-1; i>=0; --i) {
            for (int j=run[i].first-1; j>=0; --j) {
                int dist = (mxlen.second.first - ladd) - (run[i].second + j) - 1;
                st.push_back(dist);
                ++ladd;
            }
        }
        int radd = 0;
        for (int i=mxlen.second.second+1; i<(int)(run.size()); ++i) {
            for (int j=0; j<run[i].first; ++j) {
                int dist = (run[i].second + j) - (mxlen.second.first + mxlen.first - 1 + radd) - 1;
                st.push_back(dist);
                ++radd;
            }
        }
        sort(st.begin(), st.end());
        int k1 = k - mxlen.first;
        int cnt = 0;
        for (auto p : st) {
            if (k1 <= 0) break;
            cnt += p;
            --k1;
        }
        bool dbl = false;
        if (mxlen2.first > 0) {
            dbl = true;
            int ladd = 0;
            for (int i=mxlen2.second.second-1; i>=0; --i) {
                for (int j=run[i].first-1; j>=0; --j) {
                    int dist = (mxlen2.second.first - ladd) - (run[i].second + j) - 1;
                    st2.push_back(dist);
                    ++ladd;
                }
            }
            int radd = 0;
            for (int i=mxlen2.second.second+1; i<(int)(run.size()); ++i) {
                for (int j=0; j<run[i].first; ++j) {
                    int dist = (run[i].second + j) - (mxlen2.second.first + mxlen2.first - 1 + radd) - 1;
                    st2.push_back(dist);
                    ++radd;
                }
            }
        }
        if (dbl) {
            sort(st2.begin(), st2.end());
            int k2 = k - mxlen2.first, cnt2 = 0;
            for (auto p : st2) {
                if (k2 <= 0) break;
                cnt2 += p;
                --k2;
            }
            cnt = min(cnt, cnt2);
        }
        return cnt;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n;
    vi nums(n);
    rep(i, n) cin >> nums[i];
    cin >> k;
    int res = cl.minMoves(nums, k);
    cout << res << endl;
    return 0;
}

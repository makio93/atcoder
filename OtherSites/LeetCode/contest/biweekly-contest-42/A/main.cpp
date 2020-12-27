#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        set<pair<int, int>> st;
        for (int i=0; i<n; ++i) st.emplace(i, students[i]);
        int place = 0;
        while (1) {
            bool taken = false;
            for (auto itr=st.begin(); place<n&&itr!=st.end(); ) {
                if (itr->second == sandwiches[place]) {
                    ++place;
                    itr = st.erase(itr);
                    taken = true;
                }
                else ++itr;
            }
            if (place >= n) break;
            if (!taken) break;
        }
        return n-place;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vi students(n), sandwiches(n);
    rep(i, n) cin >> students[i];
    rep(i, n) cin >> sandwiches[i];
    int res = cl.countStudents(students, sandwiches);
    cout << res << endl;
    return 0;
}

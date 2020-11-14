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
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const string ORG = "atcoder";

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        string s;
        cin >> s;
        string s2 = s;
        RSORT(s2);
        if (s2 <= ORG) {
            cout << -1 << endl;
            continue;
        }
        else if (s > ORG) {
            cout << 0 << endl;
            continue;
        }
        int ans = INF, val = 0, l = min(sz(s), sz(ORG));
        rep(i, l) {
            if (s[i] > ORG[i]) {
                ans = min(ans, val);
                break;
            }
            else {
                int eql = INF, low = INF;
                if (s[i] == ORG[i]) eql = 0;
                for (int j=i+1; j<sz(s); ++j) {
                    if (s[j] == ORG[i]) eql = min(eql, j-i);
                    if (s[j] > ORG[i]) low = min(low, j-i);
                }
                if (low==INF && eql==INF) break;
                if (low != INF) ans = min(ans, val+low);
                if (low <= eql) break;
                else val += eql;
                s.erase(i+eql, 1);
                s.insert(i, ORG.substr(i, 1));
            }
        }
        if (ans >= INF) ans = min(ans, val);
        cout << ans << endl;
    }
    return 0;
}

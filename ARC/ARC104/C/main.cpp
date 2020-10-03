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

const string YES = "Yes";
const string NO = "No";

int main(){
    int n;
    cin >> n;
    vpii ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    bool ok = true;
    rep(i, n) {
        if (ab[i].first==-1 || ab[i].second==-1) continue;
        if (ab[i].first >= ab[i].second) ok = false;
    }
    if (!ok) {
        cout << NO << endl;
        return 0;
    }
    rep(i, n) {
        if (ab[i].first==-1 || ab[i].second==-1) continue;
        int len = ab[i].second - ab[i].first;
        rep(j, n) {
            if (i == j) continue;
            if (ab[j].first==-1 && ab[j].second==-1) continue;
            if (ab[j].first==-1 && ab[j].second>ab[i].first) {
                int val = ab[j].second-len;
                if (val <= 0) ok = false; 
                ab[j].first = val;
            }
            else if (ab[j].second==-1 && ab[j].first<ab[i].second) {
                int val = ab[j].first+len;
                if (val > 2*n) ok = false;
                ab[j].second = val;
            }
            else {
                int len2 = ab[j].second - ab[j].first;
                if (len2<=0 || len!=len2) ok = false;
            }
        }
        if (!ok) {
            cout << NO << endl;
            return 0;
        }
    }
    rep(i, n) {
        if (ab[i].first==-1 || ab[i].second==-1) continue;
        int len = ab[i].second - ab[i].first;
        rep(j, n) {
            if (i==j) continue;
            if (ab[j].first==-1 || ab[j].second==-1) continue;
            int len2 = ab[j].second - ab[j].first;
            if (len!=len2) ok = false;
        }
    }
    if (!ok) {
        cout << NO << endl;
        return 0;
    }
    vi cnt(2*n+1);
    rep(i, n) {
        if (ab[i].first != -1) cnt[ab[i].first]++;
        if (ab[i].second != -1) cnt[ab[i].second]++;
    }
    rep1(i, 2*n) if (cnt[i]!=0 && cnt[i]!=1) ok = false;
    if (!ok) {
        cout << NO << endl;
        return 0;
    }
    rep(i, n) {
        if (ab[i].first==-1 && ab[i].second==-1) continue;
        if (ab[i].first==-1) {
            int r = ab[i].second;
            bool tok = false;
            for (int j=r-1; j>0; --j) {
                if (cnt[j] != 0) continue;
                int len = r - j;
                bool tok2 = true;
                rep(k, n) {
                    if (i==k) continue;
                    if (ab[k].first==-1 || ab[k].second==-1) continue;
                    if (ab[k].second>j && ab[k].first<j) {
                        if (ab[k].second-ab[k].first != len) tok2 = false;
                    }
                    if (ab[k].first<r && ab[k].second>r) {
                        if (ab[k].second-ab[k].first != len) tok2 = false;
                    }
                    if (ab[k].second>r && ab[k].first<j) tok2 = false;
                }
                if (tok2) {
                    ab[i].first = j;
                    cnt[j] = 1;
                    tok = true;
                    break;
                }
            }
            if (!tok) ok = false;
        }
        else if (ab[i].second==-1) {
            int l = ab[i].first;
            bool tok = false;
            for (int j=l+1; j<=n; ++j) {
                if (cnt[j] != 0) continue;
                int len = j - l;
                bool tok2 = true;
                rep(k, n) {
                    if (i==k) continue;
                    if (ab[k].first==-1 || ab[k].second==-1) continue;
                    if (ab[k].second>l && ab[k].first<l) {
                        if (ab[k].second-ab[k].first != len) tok2 = false;
                    }
                    if (ab[k].first<j && ab[k].second>j) {
                        if (ab[k].second-ab[k].first != len) tok2 = false;
                    }
                    if (ab[k].second>j && ab[k].first<l) tok2 = false;
                }
                if (tok2) {
                    ab[i].second = j;
                    cnt[j] = 1;
                    tok = true;
                    break;
                }
            }
            if (!tok) ok = false;
        }
    }
    if (!ok) {
        cout << NO << endl;
        return 0;
    }
    VSORT(ab);
    int ncnt = 0;
    rep(i, n) {
        if (ab[i] == pii(-1, -1)) ++ncnt;
        else break;
    }
    vi cans;
    rep1(i, 2*n) if (cnt[i] == 0) cans.pb(i);
    int cn = sz(cans);
    vector<bool> used(cn);
    function<bool(int)> dfs = [&] (int d) {
        if (d == ncnt) return true;
        bool tok = false;
        rep(i2, cn) {
            if (used[i2]) continue;
            used[i2] = true;
            for (int j2=i2+1; j2<cn; ++j2) {
                if (used[j2]) continue;
                bool avail = true;
                for (int i=ncnt; i<n; ++i) {
                    int len = ab[i].second - ab[i].first;
                    if (len != abs(j2-i2)) avail = false;
                }
                if (!avail) continue;
                used[j2] = true;
                if (dfs(d+1)) tok = true;
                used[j2] = false;
            }
            used[i2] = false;
        }
        if (!tok) return false;
        else return true;
    };
    if (dfs(0)) ok = true;
    else ok = false;
    if (!ok) cout << NO << endl;
    else cout << YES << endl;
    return 0;
}

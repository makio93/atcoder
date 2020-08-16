#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

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

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (2e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, q;
    cin >> n >> q;
    vpii hr(n);
    rep(i, n) cin >> hr[i].second >> hr[i].first;
    vector<pair<pii, int>> ba(q);
    rep(i, q) {
        cin >> ba[i].first.second >> ba[i].first.first;
        ba[i].second = i;
    }
    rep(i, n) hr[i].second *= -1;
    rep(i, q) ba[i].first.second *= -1;
    VSORT(ba);
    vi ord(q);
    rep(i, q) ord[i] = ba[i].second;
    vector<pair<pii, bool>> ra(n+q);
    rep(i, n) ra[i] = { hr[i], false };
    rep(i, q) ra[n+i] = { ba[i].first, true };
    VSORT(ra);
    vll dp(n, INF);
    int qcnt = 0;
    vi ans(q);
    rep(i, n+q) {
        if (!ra[i].second) *upper_bound(all(dp), ra[i].first.second) = ra[i].first.second;
        else {
            ans[ord[qcnt]] = (upper_bound(all(dp), ra[i].first.second) - dp.begin());
            ++qcnt;
        }
    }
    rep(i, q) cout << ans[i] << endl;
    return 0;
}

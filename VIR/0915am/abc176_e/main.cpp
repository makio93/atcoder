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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int hi, wi, m;
    cin >> hi >> wi >> m;
    vi h(m), w(m);
    set<pii> st;
    rep(i, m) {
        cin >> h[i] >> w[i];
        h[i]--; w[i]--;
        st.emplace(h[i], w[i]);
    }
    vi cnth(hi), cntw(wi);
    rep(i, m) {
        cnth[h[i]]++;
        cntw[w[i]]++;
    }
    vi lsh, lsw;
    int mxh = 0, mxw = 0;
    rep(i, hi) mxh = max(mxh, cnth[i]);
    rep(i, wi) mxw = max(mxw, cntw[i]);
    rep(i, hi) if (cnth[i] == mxh) lsh.pb(i);
    rep(i, wi) if (cntw[i] == mxw) lsw.pb(i);
    int tms = 0;
    bool ok = false;
    rep(i, sz(lsh)) rep(j, sz(lsw)) {
        ++tms;
        if (st.find({lsh[i], lsw[j]}) == st.end()) {
            ok = true;
        }
        if (tms > (int)3e5) {
            if (ok) cout << (mxh+mxw) << endl;
            else cout << (mxh+mxw-1) << endl;
            return 0;
        }
    }
    if (ok) cout << (mxh+mxw) << endl;
    else cout << (mxh+mxw-1) << endl;
    return 0;
}

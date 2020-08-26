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
    vector<vi> b(2, vi(3));
    vector<vi> c(3, vi(2));
    rep(i, 2) rep(j, 3) cin >> b[i][j];
    rep(i, 3) rep(j, 2) cin >> c[i][j];
    map<vi, int> dp;
    stack<pair<pii, vi>> st;
    st.emplace(pii(0, 0), vi(9, -1));
    while (!st.empty()) {
        auto p = st.top(); st.pop();
        pii d = p.first; vi pt = p.second;
        int da = d.first + d.second;
        if (da == 9) {
            dp[pt] = 0;
            continue;
        }
        if (d.first < 5) {
            pt[da] = 0;
            st.emplace(pii(d.first+1, d.second), pt);
        }
        if (d.second < 4) {
            pt[da] = 1;
            st.emplace(pii(d.first, d.second+1), pt);
        }
    }
    repr(t, 9) {
        map<vi, int> ndp;
        for (auto p : dp) {
            vi pt = p.first; int v = p.second;
            rep(i, 9) {
                if (pt[i] != t%2) continue;
                vi npt = pt; int nv = v;
                if (i/3<=1 && npt[i]==npt[i+3]) nv += b[i/3][i%3];
                if (i%3<=1 && npt[i]==npt[i+1]) nv += c[i/3][i%3];
                npt[i] = -1;
                if (ndp.count(npt)==0) {
                    ndp[npt] = nv;
                }
                else if (t%2==0) {
                    ndp[npt] = max(ndp[npt], nv);
                }
                else {
                    ndp[npt] = min(ndp[npt], nv);
                }
            }
        }
        swap(dp, ndp);
    }
    int ans = 0, ans2 = 0;
    for (auto p : dp) ans = max(ans, p.second);
    rep(i, 2) rep(j, 3) ans2 += b[i][j];
    rep(i, 3) rep(j, 2) ans2 += c[i][j];
    ans2 -= ans;
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}

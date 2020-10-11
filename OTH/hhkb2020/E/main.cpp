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

using mint = modint1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];
    int k = 0;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '.') ++k;
    }
    vector<vi> val(h, vi(w));
    rep(i, h) {
        int now = 0, l = 0;
        rep(j, w) {
            if (s[i][j] == '#') {
                if (now > 0) {
                    for (int j2=l; j2<j; ++j2) {
                        val[i][j2] += now;
                    }
                    now = 0;
                }
                l = j+1;
            }
            else ++now;
        }
        if (now > 0) {
            for (int j2=l; j2<w; ++j2) {
                val[i][j2] += now;
            }
        }
    }
    rep(i, w) {
        int now = 0, u = 0;
        rep(j, h) {
            if (s[j][i] == '#') {
                if (now > 0) {
                    for (int j2=u; j2<j; ++j2) {
                        val[j2][i] += now;
                    }
                    now = 0;
                }
                u = j+1;
            }
            else ++now;
        }
        if (now > 0) {
            for (int j2=u; j2<h; ++j2) {
                val[j2][i] += now;
            }
        }
    }
    rep(i, h) rep(j, w) {
        val[i][j] = max(0, val[i][j]-1);
    }
    map<pii, int> cnt;
    rep(i, h) {
        int now = INF, l = 0;
        rep(j, w) {
            if (val[i][j] == 0) {
                if (l < j) {
                    pii res = { now, (j-l) };
                    cnt[res]++;
                    now = INF;
                }
                l = j+1;
            }
            else now = min(now, val[i][j]);
        }
        if (l < w) {
            pii res = { now, (w-l) };
            cnt[res]++;
        }
    }
    rep(i, w) {
        int now = INF, u = 0;
        rep(j, h) {
            if (val[j][i] == 0) {
                if (u < j) {
                    pii res = { now, (j-u) };
                    cnt[res]++;
                    now = INF;
                }
                u = j+1;
            }
            else now = min(now, val[j][i]);
        }
        if (u < h) {
            pii res = { now, (h-u) };
            cnt[res]++;
        }
    }
    mint sub = 0;
    for (auto p : cnt) {
        int fif = p.first.first, fis = p.first.second, se = p.second;
        if (fis <= 1) continue;
        sub += mint(2).pow(k-fif) * (mint(2).pow(fif-1) - 1) * fis * se;
    }
    ll vsum = 0;
    rep(i, h) rep(j, w) vsum += val[i][j];
    mint ans = mint(2).pow(k-1) * vsum - sub;
    cout << ans.val() << endl;
    return 0;
}

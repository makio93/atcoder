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

// 本番終了後に自力AC　3方向へのいもす法による実装

//const long long mod = 1000000007;
using mint = modint1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];
    vector<vi> r(h), d(w), rd(h+w-1);
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '.') continue;
            r[i].pb(j);
        }
        r[i].pb(w);
    }
    rep(j, w) {
        rep(i, h) {
            if (s[i][j] == '.') continue;
            d[j].pb(i);
        }
        d[j].pb(h);
    }
    rep(i1, h+w-1) {
        int i = (i1<w-1)?0:(i1-w+1), j = (i1>=w-1)?0:-(i1-w+1);
        while (i<h && j<w) {
            if (s[i][j] == '#') rd[i1].pb(i);
            ++i; ++j;
        }
        rd[i1].pb(i);
    }
    vector<vector<mint>> rsum(h, vector<mint>(w+2)), dsum(w, vector<mint>(h+2)), rdsum(h+w+1, vector<mint>(h+2));
    rep1(i, h) rep1(j, w) {
        rsum[i-1][j] += rsum[i-1][j-1];
        dsum[j-1][i] += dsum[j-1][i-1];
        int a = i-j + (w-1), b = (i-j>=0)?j:i;
        rdsum[a][b] += rdsum[a][b-1];
        mint nval = rsum[i-1][j] + dsum[j-1][i] + rdsum[a][b];
        if (i==1 && j==1) nval = 1;
        int ri = distance(r[i-1].begin(), upper_bound(all(r[i-1]), j-1));
        rsum[i-1][j+1] += nval; rsum[i-1][r[i-1][ri]+1] -= nval;
        int di = distance(d[j-1].begin(), upper_bound(all(d[j-1]), i-1));
        dsum[j-1][i+1] += nval; dsum[j-1][d[j-1][di]+1] -= nval;
        int rdi = distance(rd[a].begin(), upper_bound(all(rd[a]), i-1));
        int nb = b + (rd[a][rdi] - (i-1));
        rdsum[a][b+1] += nval; rdsum[a][nb] -= nval;
    }
    int ga = h-w + (w-1), gb = min(h, w);
    mint ans = rsum[h-1][w] + dsum[w-1][h] + rdsum[ga][gb];
    cout << ans.val() << endl;
    return 0;
}

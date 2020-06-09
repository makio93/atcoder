#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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
    int n;
    ll d;
    cin >> n >> d;
    vi es;
    for (int p : { 2, 3, 5 }) {
        int cnt = 0;
        while (d%p==0) {
            d /= p;
            ++cnt;
        }
        es.pb(cnt);
    }
    if (d != 1) {
        cout << 0.0 << endl;
        return 0;
    }
    vector<vector<vector<double>>> dp(es[0]+1, vector<vector<double>>(es[1]+1, vector<double>(es[2]+1, 0.0)));
    dp[0][0][0] = 1.0;
    rep(i, n) {
        vector<vector<vector<double>>> tmp(es[0]+1, vector<vector<double>>(es[1]+1, vector<double>(es[2]+1, 0.0)));
        rep(ai, es[0]+1) rep(bi, es[1]+1) rep(ci, es[2]+1) {
            if (dp[ai][bi][ci] == 0.0) continue;
            const vi da = { 0, 1, 0, 2, 0, 1 }, db = { 0, 0, 1, 0, 0, 1 }, dc = { 0, 0, 0, 0, 1, 0 };
            rep(j, 6) {
                int na = min(ai+da[j], es[0]), nb = min(bi+db[j], es[1]), nc = min(ci+dc[j], es[2]);
                tmp[na][nb][nc] += dp[ai][bi][ci] / 6.0;
            }
        }
        swap(dp, tmp);
    }
    printf("%.10f\n", dp[es[0]][es[1]][es[2]]);
    return 0;
}

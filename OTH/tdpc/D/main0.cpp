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
    int a = 0, b = 0, c = 0;
    while (d%2==0) {
        d /= 2;
        ++a;
    }
    while (d%3==0) {
        d /= 3;
        ++b;
    }
    while (d%5==0) {
        d /= 5;
        ++c;
    }
    if (d != 1) {
        cout << 0.0 << endl;
        return 0;
    }
    vector<vector<vector<long double>>> dp(100, vector<vector<long double>>(100, vector<long double>(100, 0.0)));
    dp[0][0][0] = 1.0;
    rep(i, n) {
        vector<vector<vector<long double>>> tmp(100, vector<vector<long double>>(100, vector<long double>(100, 0.0)));
        rep(ai, 80) rep(bi, 80) rep(ci, 80) {
            if (dp[ai][bi][ci] == 0.0) continue;
            tmp[ai][bi][ci] += dp[ai][bi][ci] / 6.0;
            tmp[ai+1][bi][ci] += dp[ai][bi][ci] / 6.0;
            tmp[ai+2][bi][ci] += dp[ai][bi][ci] / 6.0;
            tmp[ai][bi+1][ci] += dp[ai][bi][ci] / 6.0;
            tmp[ai][bi][ci+1] += dp[ai][bi][ci] / 6.0;
            tmp[ai+1][bi+1][ci] += dp[ai][bi][ci] / 6.0;
        }
        swap(dp, tmp);
    }
    long double ans = 0.0;
    for (int ai=a; ai<80; ++ai) {
        for (int bi=b; bi<80; ++bi) {
            for (int ci=c; ci<80; ++ci) {
                ans += dp[ai][bi][ci];
            }
        }
    }
    printf("%.10Lf\n", ans);
    return 0;
}

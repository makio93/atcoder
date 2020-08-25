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

int a, b;
vi ai, bi, suma, sumb;
vector<vector<vi>> dp;
int valmin(int i, int j, int t) {
    if (dp[i][j][t] != -1) return dp[i][j][t];
    if (i==a && j==b) return (dp[i][j][t] = 0);
    if (i==a) return (dp[i][j][t] = sumb[j] - valmin(i, j+1, 1-t));
    if (j==b) return (dp[i][j][t] = suma[i] - valmin(i+1, j, 1-t));
    int res = INF;
    res = min(valmin(i, j+1, 1-t), valmin(i+1, j, 1-t));
    return (dp[i][j][t] = suma[i] + sumb[j] - res);
}

int main(){
    cin >> a >> b;
    ai = vi(a); bi = vi(b);
    suma = vi(a+1); sumb = vi(b+1);
    rep(i, a) cin >> ai[i];
    rep(i, b) cin >> bi[i];
    repr(i, a) suma[i] = suma[i+1] + ai[i];
    repr(i, b) sumb[i] = sumb[i+1] + bi[i];
    dp = vector<vector<vi>>(a+1, vector<vi>(b+1, vi(2, -1)));
    cout << valmin(0, 0, 0) << endl;
    return 0;
}

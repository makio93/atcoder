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
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// 後日改めて自力提出したコード（さらに研究分）

int n;
vi x, y, z;
int cost(int i, int j) { return abs(x[i]-x[j]) + abs(y[i]-y[j]) + max(0, z[j]-z[i]); }
vector<vi> dp;
int calc(int s, int v) {
    if (dp[s][v] != INF+5) return dp[s][v];
    if (s==(1<<n)-1 && v==0) return (dp[s][v] = 0);
    int res = INF;
    rep(u, n) if (!((s>>u)&1)) {
        res = min(res, calc(s|(1<<u),u)+cost(v,u));
    }
    return (dp[s][v] = res);
}

int main(){
    cin >> n;
    x = vi(n); y = vi(n); z = vi(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    dp = vector<vi>((1<<n), vi(n, INF+5));
    cout << calc(0, 0) << endl;
    return 0;
}

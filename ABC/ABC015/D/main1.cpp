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

int w, n, k;
vi a, b;
vector<vector<vi>> dp;
int dfs(int j, int h, int i) {
    if (i == n) return dp[j][h][i] = 0;
    if (dp[j][h][i] != -1) return dp[j][h][i];
    int res = dfs(j, h, i+1);
    if (h<k && w-j>=a[i]) {
        res = max(res, dfs(j+a[i], h+1, i+1) + b[i]);
    }
    return dp[j][h][i] = res;
}

int main(){
    cin >> w >> n >> k;
    a = vi(n), b = vi(n);
    rep(i, n) cin >> a[i] >> b[i];
    dp = vector<vector<vi>>(w+1, vector<vi>(k+1, vi(n+1, -1)));
    cout << dfs(0, 0, 0) << endl;
    return 0;
}

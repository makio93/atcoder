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

const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

vector<vi> g;
vi x;
int dfs(int v) {
    vector<bool> dp(x[v]+1);
    dp[0] = true;
    int sum = 0;
    for (int t : g[v]) {
        int val = dfs(t);
        if (val == -1) return -1;
        sum += x[t] + val;
        vector<bool> tdp(x[v]+1);
        repr(j, x[v]+1) {
            if (j-x[t] >= 0) tdp[j] = (tdp[j] | dp[j-x[t]]);
            if (j-val >= 0) tdp[j] = (tdp[j] | dp[j-val]);
        }
        dp = tdp;
    }
    int res = x[v];
    while (res >= 0) {
        if (dp[res]) break;
        --res;
    }
    if (res == -1) return -1;
    else return (sum - res);
}

int main(){
    int n;
    cin >> n;
    g = vector<vi>(n);
    rep1(i, n-1) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
    }
    x = vi(n);
    rep(i, n) cin >> x[i];
    if (dfs(0) != -1) cout << YES << endl;
    else cout << NO << endl;
    return 0;
}

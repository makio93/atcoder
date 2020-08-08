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

int main(){
    int n;
    cin >> n;
    vector<vi> g(n);
    rep1(i, n-1) {
        int p;
        cin >> p;
        --p;
        g[i].pb(p);
        g[p].pb(i);
    }
    vi x(n);
    rep(i, n) cin >> x[i];
    queue<int> q;
    vi d(n, -1);
    vi ord;
    q.push(0);
    d[0] = 0;
    ord.pb(0);
    while (!q.empty()) {
        int p = q.front(); q.pop();
        int di = d[p];
        for (int to : g[p]) {
            if (d[to] != -1) continue;
            q.push(to);
            d[to] = di + 1;
            ord.pb(to);
        }
    }
    reverse(all(ord));
    vi val(n, INF);
    rep(i, n) {
        int sum = 0;
        vector<bool> dp(x[ord[i]]+1);
        dp[0] = true;
        for (int to : g[ord[i]]) {
            if (to < ord[i]) continue;
            vector<bool> tdp(x[ord[i]]+1);
            repr(j, x[ord[i]]+1) {
                if (j-x[to]>=0) tdp[j] = (tdp[j] | dp[j-x[to]]);
                if (j-val[to]>=0) tdp[j] = (tdp[j] | dp[j-val[to]]);
            }
            dp = tdp;
            sum += x[to] + val[to];
        }
        int mx = x[ord[i]];
        while (mx >= 0) {
            if (dp[mx]) break;
            --mx;
        }
        if (mx >= 0) val[ord[i]] = sum - mx;
        else {
            cout << NO << endl;
            return 0;
        }
    }
    cout << YES << endl;
    return 0;
}

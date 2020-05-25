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

vi cts(3);
int d;
map<ll, ll> memo;
ll cost(ll n) {
    if (n == 0) return 0;
    if (n == 1) return memo[1] = d;
    if (memo.count(n)!=0) return memo[n];
    ll res = INT64_MAX;
    if (n <= INT64_MAX/d) res = min(res, n * d);
    vi rs = { 2, 3, 5 };
    rep(i, 3) {
        int r = rs[i], ct = cts[i];
        if (n < r) continue;
        ll cnt1 = cost(n/r) + ct + d * llabs(n-n/r*r);
        res = min(res, cnt1);
        ll cnt2 = cost((n+r-1)/r) + ct + d * llabs(n-(n+r-1)/r*r);
        res = min(res, cnt2);
    }
    return memo[n] = res;
}

int main(){
    int t;
    cin >> t;
    rep(i, t) {
        ll n;
        int a, b, c;
        cin >> n >> a >> b >> c >> d;
        memo.clear();
        cts = { a, b, c };
        memo[0] = 0;
        cout << cost(n) << endl;
    }
    return 0;
}

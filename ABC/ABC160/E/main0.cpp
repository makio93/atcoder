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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    multiset<int, greater<int>> p, q, r;
    rep(i, a) {
        int j;
        cin >> j;
        p.insert(j);
    }
    rep(i, b) {
        int j;
        cin >> j;
        q.insert(j);
    }
    rep(i, c) {
        int j;
        cin >> j;
        r.insert(j);
    }
    int xi = x, yi = y;
    ll ans = 0;
    rep(i, x+y) {
        int pd = 0, qd = 0, rd = 0;
        if (a&&xi) pd = *(p.begin());
        if (b&&yi) qd = *(q.begin());
        if (c) rd = *(r.begin());
        if (rd < max(pd, qd)) {
            if (pd > qd) {
                --a; --xi; p.erase(0);
            }
            else {
                --b; --yi; q.erase(0);
            }
        }
        else {
            --c; r.erase(0);
        }
        int m = max((pd>qd?pd:qd), rd);
        ans += m;
    }
    cout << ans << endl;
    return 0;
}

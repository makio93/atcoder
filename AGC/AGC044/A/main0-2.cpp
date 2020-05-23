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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

ull a, b, c, d;
ull dfs(ull s, ull g, ull val, int stat) {
    if (s == g) return val;
    if (val > INF) return INF;
    if (s <= 0) return INF;
    ull res = INF;
    if (s < g) {
        if (stat==1) {
            rep1(i, 10) {
                res = min(res, dfs(s+i, g, val+d*i, 2));
                res = min(res, dfs(s-i, g, val+d*i, 2));
            }
        }
        if (stat==2) {
            ll add;
            if (s*d<a) add = s*d;
            else add = a;
            res = min(res, dfs(s*2, g, val+add, 2));
            if (s*2*d<b) add = s*2*d;
            else add = b;
            res = min(res, dfs(s*3, g, val+add, 3));
            if (s*4*d<c) add = s*4*d;
            else add = c;
            res = min(res, dfs(s*5, g, val+add, 5));
        }
        if (stat==3) {
            res = min(res, dfs(s*3, g, val+b, 3));
            res = min(res, dfs(s*5, g, val+c, 5));
        }
        if (stat==5) res = min(res, dfs(s*5, g, val+c, 5));
    }
    ull sub = llabs(g-s);
    if (INF/sub>=d) res = min(res, val+sub*d);
    return res;
}

int main(){
    int t;
    cin >> t;
    rep(i, t) {
        ull n;
        cin >> n >> a >> b >> c >> d;
        cout << dfs(1, n, d, 2) << endl;
    }
    return 0;
}

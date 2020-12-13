#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

int main(){
    int n, a;
    cin >> n >> a;
    string s;
    cin >> s;
    vi llst, rlst;
    rep(i, n) if (s[i] == '#') {
        if (i+1 < a) llst.pb(i+1);
        else rlst.pb(i+1);
    }
    bool right = true;
    if (sz(llst) >= sz(rlst)) {
        int num = sz(llst) - sz(rlst);
        rep(i, num) rlst.pb(n+1);
        right = false;
    }
    else {
        int num = sz(rlst) - sz(llst) - 1;
        rep(i, num) llst.pb(0);
    }
    VSORT(rlst); RSORT(llst);
    ll ans = 0;
    rep(i, sz(rlst)) ans += abs(a - rlst[i]) * 2;
    rep(i, sz(llst)) ans += abs(a - llst[i]) * 2;
    if (right) ans -= abs(a - rlst.back());
    else ans -= abs(a - llst.back());
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

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

// 本番終了後での自力提出コード

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, n) cin >> a[i];
        if (n <= 5) {
            ll ans = 1;
            rep(i, n) ans *= a[i];
            cout << ans << endl;
            continue;
        }
        vi plus, minus;
        rep(i, n) {
            if (a[i] >= 0) plus.pb(a[i]);
            else minus.pb(a[i]);
        }
        ll ans = 1;
        if (plus.empty()) {
            RSORT(minus);
            rep(i, 5) ans *= minus[i];
        }
        else {
            RSORT(plus);
            VSORT(minus);
            ans = 0;
            for (int i=0; i<=min(5,sz(minus)); i+=2) {
                if (sz(plus) < 5-i) continue;
                ll tval = 1;
                rep(j, i) tval *= minus[j];
                rep(j, 5-i) tval *= plus[j];
                ans = max(ans, tval);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

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

#define INF (1e15)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int t;
    cin >> t;
    rep(i0, t) {
        int n;
        cin >> n;
        vi pos, neg;
        rep(i, n) {
            int a;
            cin >> a;
            if (a >= 0) pos.pb(a);
            else neg.pb(a);
        }
        ll ans = 1;
        if (n == 5) {
            rep(i, sz(pos)) ans *= pos[i];
            rep(i, sz(neg)) ans *= neg[i];
        }
        else if (sz(neg) == n) {
            RSORT(neg);
            rep(i, 5) ans *= neg[i];
        }
        else {
            ans = -INF;
            VSORT(neg); RSORT(pos);
            vll neg2;
            for (int i=0; i+1<sz(neg); i+=2) {
                neg2.pb((ll)neg[i]*neg[i+1]);
            }
            for (int i=0; i<=min(3,sz(neg2)); ++i) {
                if (i*2+sz(pos) < 5) continue;
                ll val = 1;
                rep(j, i) val *= neg2[j];
                rep(j, 5-i*2) val *= pos[j];
                ans = max(ans, val);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

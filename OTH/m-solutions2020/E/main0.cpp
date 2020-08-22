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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct P {
    int x, y;
    P(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const P& p) const {
        return (x < p.x);
    }
    bool operator<=(const P& p) const {
        return (x <= p.x);
    }
};

int main(){
    int n;
    cin >> n;
    vector<pair<int, P>> m(n);
    rep(i, n) cin >> m[i].second.x >> m[i].second.y >> m[i].first;
    RSORT(m);
    vll s(n+1, INF);
    rep(i, 1<<n) {
        ll sum = 0;
        vector<bool> xy(n);
        rep(i2, n) if ((i>>i2)&1) {
            ll tsumx = 0, tsumy = 0;
            rep(j, n) {
                tsumx += abs(m[j].second.x-m[i2].second.x);
                tsumy += abs(m[j].second.y-m[i2].second.y);
            }
            if (tsumx <= tsumy) xy[i2] = false;
            else xy[i2] = true;
        }
        rep(j, n) {
            ll mn = min(abs(m[j].second.x), abs(m[j].second.y));
            rep(i2, n) if ((i>>i2)&1) {
                if (!xy[i2]) {
                    mn = min(mn, llabs(m[j].second.y-m[i2].second.y));
                }
                else {
                    mn = min(mn, llabs(m[j].second.x-m[i2].second.x));
                }
            }
            sum += mn * m[j].first;
        }
        int cnt = __builtin_popcount(i);
        s[cnt] = min(s[cnt], sum);
    }
    rep(i, n+1) cout << s[i] << endl;
    return 0;
}

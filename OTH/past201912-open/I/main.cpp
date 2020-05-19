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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cs(m);
    rep(i, m) {
        string s;
        cin >> s >> cs[i].first;
        int b = 0;
        rep(j, n) {
            if (s[j] == 'Y') b |= (1<<j);
        }
        cs[i].second = b;
    }
    VSORT(cs);
    vector<bool> now(m);
    int okb = 0;
    rep(i, m) {
        if ((~okb)&(cs[i].second)) {
            now[i] = true;
            okb |= cs[i].second;
            continue;
        }
        ll sum = 0;
        int tb = cs[i].second;
        vector<bool> nt = now;
        nt[i] = true;
        rep(j, i-1) {
            if (!now[j]) continue;
            if (!((~tb)&(cs[j].second))) {
                nt[j] = false;
                sum += cs[j].first;
            }
            else tb |= cs[j].second;
        }
        if (sum > cs[i].first) now = nt;
    }
    if (okb!=(1<<n)-1) cout << -1 << endl;
    else {
        ll ans = 0;
        rep(i, m) {
            if (now[i]) ans += cs[i].first;
        }
        cout << ans << endl;
    }
    return 0;
}

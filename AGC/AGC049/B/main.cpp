#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi sum(n+1);
    bool ok = true;
    repr(i, n) {
        sum[i] = sum[i+1] + ((int)(s[i])-(int)(t[i]));
        if (sum[i] < 0) ok = false;
    }
    if (!ok || sum[0]%2!=0) {
        cout << -1 << endl;
        return 0;
    }
    set<int> pos, neg;
    vi sub(n);
    repr(i, n) {
        if (s[i] == t[i]) continue;
        if (s[i]=='1') {
            pos.insert(i);
            sub[i] = 1;
        }
        else {
            neg.insert(i);
            sub[i] = -1;
        }
    }
    ll ans = 0;
    for (auto itr=neg.begin(); itr!=neg.end(); ++itr) {
        auto itr2 = pos.upper_bound(*itr);
        ans += (*itr2) - (*itr);
        sub[*itr] = sub[*itr2] = 0;
        pos.erase(itr2);
    }
    for (auto itr=pos.begin(); itr!=pos.end(); ++itr) {
        int val1 = *itr;
        ++itr;
        int val2 = *itr;
        ans += val2 - val1;
    }
    cout << ans << endl;
    return 0;
}

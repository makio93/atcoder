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
    ll n;
    int x, m;
    cin >> n >> x >> m;
    vi val(m);
    vll sum;
    ll now = x;
    sum.pb(x);
    val[x] = 1;
    ll ans = 0;
    int time = 1;
    while (time<=n) {
        ++time;
        now = now * now % m;
        if (val[now] != 0) {
            ll roop = time - val[now];
            ll mval = sum.back() - sum[val[now]-1];
            ans += (n - (time-1)) / roop * mval;
            n -= time-1;
            n %= roop;
            ans += sum[val[now]-1+n] - sum[val[now]-1];
            cout << ans << endl;
            return 0;
        }
        else {
            val[now] = time;
            ll nsum = sum.back() + now;
            sum.pb(nsum);
        }
    }
    ans += sum.back();
    cout << ans << endl;
    return 0;
}

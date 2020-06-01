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
#define vull vector<ull>
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

int main(){
    int n;
    cin >> n;
    vi a(n+1);
    rep(i, n+1) cin >> a[i];
    if (n==0) {
        if (a[0] == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    vll b2(n+1, 1);
    rep1(i, n) {
        b2[i] = (b2[i-1]*2<INF)?(b2[i-1]*2):INF;
    }
    vll b(n+2);
    repr(i, n+1) {
        b[i] = (b[i+1]+a[i]<=b2[i])?(b[i+1]+a[i]):b2[i];
    }
    ll ans = 1, now = 1;
    rep1(i, n) {
        now *= 2;
        now = min(now, b[i]);
        ans += now;
        now -= a[i];
        if ((i<n&&now<=0)||(i==n&&now<0)) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}

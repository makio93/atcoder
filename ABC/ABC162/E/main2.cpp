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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int mpow(int x, int t) {
    if (!t) return 1;
    ll a = mpow(x, t/2);
    a = a * a % mod;
    if (t%2==1) a = a * x % mod;
    return (int)a;
}

int main(){
    int n, k;
    cin >> n >> k;
    vll d(k+1);
    rep1r(i, k) d[i] = mpow(k/i, n);
    rep1r(i, k) {
        for (int j=i*2; j<=k; j+=i) {
            d[i] -= d[j];
        }
    }
    ll ans = 0;
    rep1(i, k) ans += d[i] * i % mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}

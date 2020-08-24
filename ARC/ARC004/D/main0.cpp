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

const long long MOD = 1000000007;

ll modPow(int a, int b) {
    if (b == 0) return 1;
    if (b%2==0) {
        ll half = modPow(a, b/2);
        return half * half % MOD;
    }
    else return a * modPow(a, b-1) % MOD;
}

ll calcComb(int a, int b) {
    if (b == 0) return 1;
    if (b > a-b) return calcComb(a, a-b);
    ll num = 1, den = 1;
    rep(i, b) num = (num * (a-i)) % MOD;
    rep1(i, b) den = (den * i) % MOD;
    return num * modPow(den, MOD-2) % MOD;
}

int main(){
    int n, m;
    cin >> n >> m;
    vll fact(m+1), inv(m+1);
    fact[0] = 1;
    rep1(i, m) fact[i] = (fact[i-1] * i) % MOD;
    inv[m] = modPow(fact[m], MOD-2);
    rep1r(i, m) inv[i-1] = (inv[i] * i) % MOD;
    vi plis;
    int tmp = abs(n);
    for (int i=2; i*i<=tmp; ++i) {
        if (tmp%i!=0) continue;
        int cnt = 0;
        while (tmp%i==0) {
            tmp /= i;
            ++cnt;
        }
        plis.pb(cnt);
    }
    if (tmp!=1) plis.pb(1);
    ll ans = 1;
    rep(i, sz(plis)) {
        ans = (ans * calcComb(plis[i]+m-1, m-1)) % MOD;
    }
    ll sum = 0;
    if (n > 0) {
        ++sum;
        for (int i=2; i<=m; i+=2) sum = (sum + fact[m] * inv[i] % MOD * inv[m-i]) % MOD;
    }
    else for (int i=1; i<=m; i+=2) sum = (sum + fact[m] * inv[i] % MOD * inv[m-i]) % MOD;
    ans = (ans * sum) % MOD;
    cout << ans << endl;
    return 0;
}

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

int f(ll x) {
    if (x == 0) return 0;
    return f(x%__builtin_popcount(x)) + 1;
}

int main(){
    int n;
    cin >> n;
    string x;
    cin >> x;
    int pcnt = 0;
    rep(i, n) if (x[i] == '1') ++pcnt;
    vll ans(n);
    if (pcnt==0) {
        rep(i, n) cout << 1 << endl;
        return 0;
    }
    vi plus(n), minus(n);
    ll plusx = 0, minusx = 0;
    plus[0] = 1 % (pcnt+1);
    rep(i, n-1) {
        plus[i+1] = plus[i] * 2 % (pcnt+1);
    }
    rep(i, n) {
        if (x[n-i-1] == '1') plusx = (plusx + plus[i]) % (pcnt+1); 
    }
    if (pcnt-1>0) {
        minus[0] = 1 % (pcnt-1);
        rep(i, n-1) {
            minus[i+1] = minus[i] * 2 % (pcnt-1);
        }
        rep(i, n) {
            if (x[n-i-1] == '1') minusx = (minusx + minus[i]) % (pcnt-1); 
        }
    }
    rep(i, n) {
        if (x[i] == '1') {
            if (pcnt == 1) ans[i] = 0;
            else {
                ll next = (minusx - minus[n-1-i] + (pcnt-1)) % (pcnt-1);
                ans[i] = f(next) + 1;
            }
        }
        else {
            ll next = (plusx + plus[n-1-i]) % (pcnt+1);
            ans[i] = f(next) + 1;
        }
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}

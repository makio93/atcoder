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
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    string t;
    cin >> t;
    const ll SLEN = (ll)(1e10);
    ll ans = 0;
    if (n < 2) {
        ans = SLEN;
        if (t == "1") {
            ans *= 2;
        }
    }
    else {
        bool ok = true;
        int p = 0;
        if (t[0] == '0') {
            p = 2;
        }
        else if (t[1] == '0') {
            p = 1;
        }
        else if (n<=2 || t[2]=='0') p = 0;
        else ok = false;
        if (ok) {
            for (int i=3-p; i<n; i+=3) {
                if (n-i >= 3) {
                    if (t.substr(i, 3) != "110") ok = false;
                }
                else {
                    if (n-i==2) {
                        if (t.substr(i, 2) != "11") ok = false;
                    }
                    if (n-i==1) {
                        if (t.substr(i, 1) != "1") ok = false;
                    } 
                }
                if (!ok) break;
            }
        }
        if (!ok) ans = 0;
        else {
            ll val = (p + n + 2) / 3;
            ans = SLEN - val + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

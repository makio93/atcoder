#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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
    int t;
    cin >> t;
    rep(i1, t) {
        int n, k;
        cin >> n >> k;
        vi h(n);
        rep(i, n) cin >> h[i];
        bool ok = true;
        int l = 0;
        bool plus = true;
        rep(i, n-1) {
            if (i==0 || i+1==n-1) {
                if (abs(h[i+1]-h[i]) > k-1) ok = false;
            }
            else {
                if (abs(h[i+1]-h[i]) > 2*(k-1)) ok = false;
            }
            if (i+2 <= n-1) {
                if (plus) {
                    if (h[i+1]<h[i]) {
                        plus = false;
                        l = i;
                    }
                }
                else {
                    if (h[i+1]>h[i]) {
                        plus = true;
                        l = i;
                    }
                }
                int l2 = l;
                while ((ll)(abs(h[i+2]-h[l2])) > (ll)((i+2-l2)*(k-1))) {
                    ++l2;
                    if (l2 > i) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

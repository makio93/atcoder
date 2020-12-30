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
        string s;
        cin >> s;
        int n = sz(s);
        string s2 = "$";
        s2 += s;
        s2 += "$";
        double i = 2.0, c = 1.0, r = 0.5;
        map<double, double> p;
        p[0.5] = 0.0;
        p[n+0.5] = 0.0;
        while (c <= n) {
            double j = 2.0 * c - i;
            while (s2[(int)(i)] == s2[(int)(j)]) {
                i += 1.0; j -= 1.0; r += 1.0;
            }
            p[c] = r;
            double d = 0.5;
            double rl = 0.5;
            while (d <= r) {
                rl = p[c-d];
                if (rl == r-d) break;
                double rr = min(r-d, rl);
                p[c+d] = rr;
                d += 0.5;
            }
            if (d > r) {
                i += 1.0;
                r = 0.5;
            }
            else r = rl;
            c += d;
        }
        vi change(n+2);
        double c2 = 0.5;
        while (c2 <= (double)n) {
            double add = 2.0;
            if (p[c2] >= 0.5) {
                if (p[c2-0.5]>=1.5 && p[c2+0.5]>=1.5) {
                    if (c2+0.5<=n) change[(int)(c2+0.5)] = 1;
                    if (c2-0.5 >= 1) change[(int)(c2-0.5)] = 1;
                }
                else {
                    if (p[c2-0.5] >= 1.5) {
                        if (c2+0.5<=n) change[(int)(c2+0.5)] = 1;
                    }
                    else {
                        if (c2-0.5 >= 1) change[(int)(c2-0.5)] = 1;
                    }
                }
            }
            else {
                if (p[c2-0.5]>=1.5 && p[c2+0.5]>=1.5) {
                    change[(int)(c2-0.5)] = 1;
                    change[(int)(c2+0.5)] = 1;
                }
                else {
                    if (p[c2-0.5] >= 1.5) {
                        if (c2+0.5<=n) change[(int)(c2+0.5)] = 1;
                    }
                    if (p[c2+0.5] >= 1.5) {
                        if (c2-0.5 >= 1) change[(int)(c2-0.5)] = 1;
                    }
                }
            }
            c2 += add;
        }
        int ans = 0;
        rep(i, sz(change)) if (change[i] == 1) ++ans;
        cout << ans << endl;
    }
    return 0;
}

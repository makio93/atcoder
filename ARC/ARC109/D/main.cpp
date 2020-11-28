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
#define INFT (1e9+5)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

vector<pii> dp(4, pii(-INFT, -INFT));
int tark;
pii tarp;
ll calc(ll val, pii p, int k) {
    if (dp[k] != pii(-INFT, -INFT)) 
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        tarp = {(int)(1e9+5), (int)(1e9+5)};
        tarp.first = min({ay, by, cy});
        tarp.second = min({ax, bx, cx});
        const vi dy = {0, 1, 0, 1}, dx = {0, 0, 1, 1};
        rep(i, 4) {
            int ty = tarp.first + dy[i], tx = tarp.second + dx[i];
            if (pii(ay,ax)!=pii(ty,tx) && pii(by,bx)!=pii(ty,tx) && pii(cy,cx)!=pii(ty,tx)) {
                tark = i;
                break;
            }
        }
        ll ans = calc(0, pii(0, 0), 3);
        cout << ans << endl;
    }
    return 0;
}

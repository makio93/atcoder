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
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// 公式解説より解法その２

int main(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    int abmx = 0;
    rep(i, n) abmx = max(abmx, a[i]);
    rep(i, m) abmx = max(abmx, b[i]);
    vi exa(abmx+1), exb(abmx+1);
    rep(i, n) exa[a[i]] = 1;
    rep(i, m) exb[b[i]] = 1;
    bool exist = false;
    rep1(i, abmx) if (exa[i]+exb[i] == 2) {
        cout << i << endl;
        exist = true;
    }
    if (!exist) cout << endl;
    return 0;
}

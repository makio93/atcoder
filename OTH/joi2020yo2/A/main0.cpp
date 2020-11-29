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

// バチャ本番中のコード

int main(){
    int n;
    cin >> n;
    vs s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    vector<vs> t2(4);
    t2[0] = t;
    rep1(i1, 3) {
        vs tmp(n, string(n, '0'));
        rep(i, n) rep(j, n) {
            tmp[j][n-i-1] = t2[i1-1][i][j];
        }
        t2[i1] = tmp;
    }
    int ans = INF;
    rep(i1, 4) {
        int cnt = min(i1, 4-i1);
        rep(i, n) rep(j, n) {
            if (s[i][j] != t2[i1][i][j]) ++cnt;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

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

int main(){
    int d, n;
    cin >> d >> n;
    vi t(d);
    rep(i, d) cin >> t[i];
    vi a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    vi mi(d), ma(d);
    rep(i, d) {
        int mit = INF, mat = -1;
        rep(j, n) if (t[i]>=a[j] && t[i]<=b[j]) {
             mit = min(mit, c[j]);
             mat = max(mat, c[j]);
        }
        mi[i] = mit; ma[i] = mat;
    }
    int sumi = 0, suma = 0;
    rep(i, d-1) {
        int psumi = sumi, psuma = suma;
        bool cmpi = psuma+abs(ma[i]-mi[i+1]) > psumi+abs(mi[i]-mi[i+1]);
        sumi = (cmpi?psuma+abs(ma[i]-mi[i+1]):psumi+abs(mi[i]-mi[i+1]));
        bool cmpa = psuma+abs(ma[i]-ma[i+1]) > psumi+abs(mi[i]-ma[i+1]);
        suma = (cmpa?psuma+abs(ma[i]-ma[i+1]):psumi+abs(mi[i]-ma[i+1]));
    }
    cout << max(sumi, suma) << endl;
    return 0;
}

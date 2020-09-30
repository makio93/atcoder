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

const string YES = "Yes";
const string NO = "No";

int main(){
    int n, d;
    cin >> n >> d;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    two_sat ts(n);
    rep(i, n) for (int j=i+1; j<n; ++j) {
        if (abs(x[i]-x[j]) < d) ts.add_clause(i, false, j, false);
        if (abs(x[i]-y[j]) < d) ts.add_clause(i, false, j, true);
        if (abs(y[i]-x[j]) < d) ts.add_clause(i, true, j, false);
        if (abs(y[i]-y[j]) < d) ts.add_clause(i, true, j, true);
    }
    if (!ts.satisfiable()) cout << NO << endl;
    else {
        cout << YES << endl;
        auto ans = ts.answer();
        rep(i, sz(ans)) cout << (ans[i]?x[i]:y[i]) << endl;
    }
    return 0;
}

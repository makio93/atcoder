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

int main(){
    int n;
    cin >> n;
    vll a(n);
    vs b(n);
    rep(i, n) {
        string s;
        cin >> s;
        string ai, bi;
        bool isa = true;
        rep(j, sz(s)) {
            if (s[j] == '.') {
                isa = false;
                continue;
            }
            if (isa) ai.pb(s[j]);
            else bi.pb(s[j]);
        }
        a[i] = stoi(ai);
        b[i] = bi;
    }
    ll ans = 0;
    rep(i, n) for (int j=i+1; j<n; ++j) {
        ll teni = 1, tenj = 1;
        rep(k, sz(b[i])) teni *= 10;
        rep(k, sz(b[j])) tenj *= 10;
        if (sz(b[i]) == 0) b[i] = "0";
        if (sz(b[j]) == 0) b[j] = "0";
        if ((__int128_t)((a[i])*teni+(stoi(b[i])))*(__int128_t)((a[j])*tenj+(stoi(b[j])))%(teni*tenj)==0) ++ans;
    }
    cout << ans << endl;
    return 0;
}

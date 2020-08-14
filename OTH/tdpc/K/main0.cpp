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
    vpii rx(n);
    rep(i, n) cin >> rx[i].second >> rx[i].first;
    VSORT(rx);
    vi dp(n+1, -1);
    rep(i, n) {
        int l = -1, r = n;
        while (abs(r-l)>1) {
            int c = (l+r)/2;
            if (dp[c] == -1) r = c;
            else {
                int rt = rx[dp[c]].first, xt = rx[dp[c]].second;
                int ri = rx[i].first, xi = rx[i].second;
                if (ri-rt > abs(xi-xt)) l = c;
                else r = c;
            }
        }
        if (!(l==-1&&dp[0]!=-1)) dp[l+1] = i;
    }
    int ans = 0;
    rep(i, n) if (dp[i] != -1) ans = max(ans, i+1);
    cout << ans << endl;
    return 0;
}

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
    string s;
    cin >> s;
    int n = sz(s);
    vector<vi> dp(n+1, vi(n+1));
    rep1(h, n) for (int i=0; i+h<=n; ++i) {
        if (h <= 3) {
            if (s.substr(i, h) == "iwi") dp[i][i+h] = 1;
            else dp[i][i+h] = 0;
        }
        if (h > 3) {
            for (int k=i+1; k<i+h; ++k) dp[i][i+h] = max(dp[i][i+h], dp[i][k]+dp[k][i+h]);
            if (h%3==0) {
                for (int j=i+1; j<i+3; ++j) {
                    if (dp[j][j+h-3] < (h-3)/3) continue;
                    string t = s.substr(i, j-i) + s.substr(j+(h-3), 3-(j-i));
                    if (t == "iwi") dp[i][i+h] = max(dp[i][i+h], h/3);
                }
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}

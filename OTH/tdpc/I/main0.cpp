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
    for (int h=0; h<=n; ++h) for (int i=0; i+h<=n; ++i) {
        for (int j=i; j+3<=i+h; ++j) {
            if (s.substr(j, 3) == "iwi") {
                for (int j2=max(i,j-2); j2+6<=i+h; ++j2) {
                    if (j+3>=i+h) continue;
                    string t = s.substr(j2, j-j2) + s.substr(j+3, (j2+6)-(j+3));
                    if (t == "iwi") dp[i][i+h] = max(dp[i][i+h], dp[i][j2]+dp[j2+6][i+h]+2);
                }
                dp[i][i+h] = max(dp[i][i+h], dp[i][j]+dp[j+3][i+h]+1);
            }
            dp[i][i+h] = max(dp[i][i+h], dp[i][j]+dp[j+3][i+h]);
        }
        for (int k=i+1; k<i+h; ++k) {
            dp[i][i+h] = max(dp[i][i+h], dp[i][k]+dp[k][i+h]);
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}

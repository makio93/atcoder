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
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int a, b, c;
vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101)));
vector<vector<vector<bool>>> checked(101, vector<vector<bool>>(101, vector<bool>(101, false)));
double calc(int x, int y, int z) {
    if (checked[x][y][z]) return dp[x][y][z];
    checked[x][y][z] = true;
    if (x>=100 || y>=100 || z>=100) return (dp[x][y][z] = 0.0);
    double res = 0.0;
    res += (double)x / (x+y+z) * (1.0 + calc(x+1, y, z));
    res += (double)y / (x+y+z) * (1.0 + calc(x, y+1, z));
    res += (double)z / (x+y+z) * (1.0 + calc(x, y, z+1));
    return (dp[x][y][z] = res);
} 

int main(){
    cin >> a >> b >> c;
    double ans = calc(a, b, c);
    printf("%.10f\n", ans);
    return 0;
}

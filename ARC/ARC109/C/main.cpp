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

const string HS = "RPSN";
int n, k1;
string s;
vector<vc> dp;
char calc(int v, int k) {
    if (dp[v][k] != 'N') return dp[v][k];
    char res = 'N';
    if (k<=1) {
        int p1 = v, p2 = (v+1)%n;
        if (s[p2] == s[p1]) res = s[p1];
        else {
            rep(i, 3) {
                if (s[p1] != HS[i]) continue;
                if (s[p2] == HS[(i+1)%3]) res = s[p2];
                else res = s[p1];
            }
        }
        return (dp[v][k] = res);
    }
    else {
        int add = 1;
        rep(i, k-1) add = add * 2 % n;
        int m = (v + add) % n;
        char vall = calc(v, k-1), valr = calc(m, k-1);
        if (vall == valr) res = vall;
        else {
            rep(i, 3) {
                if (vall != HS[i]) continue;
                if (valr == HS[(i+1)%3]) res = valr;
                else res = vall;
            }
        }
        return (dp[v][k] = res);
    }
}

int main(){
    cin >> n >> k1;
    cin >> s;
    dp = vector<vc>(n, vc(k1+1, 'N'));
    char ans = calc(0, k1);
    cout << ans << endl;
    return 0;
}

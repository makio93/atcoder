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

// 本番中に1つ目に書いたコード。実装上は問題無いが、見落としているパターンがあるのでWA

int n;
string s;
vi dp;
int foxlen(int p) {
    if (dp[p] != -1) return dp[p];
    if (n-p < 3) return (dp[p] = 0);
    int res = 0, p1 = p;
    while (1) {
        bool end = false;
        if (n-p < 3) end = true;
        else if (s.substr(p, 3) == "fox") {
            res += 3;
            p += 3;
        }
        else {
            if (s[p] == 'f') {
                if (s[p+1] == 'o') {
                    int tmp = foxlen(p+2);
                    if (p+tmp+2 >= n) end = true;
                    else if (s[p+tmp+2] == 'x') {
                        res += tmp + 3;
                        p += tmp + 3;
                    }
                    else end = true;
                }
                else {
                    int tmp = foxlen(p+1);
                    if (p+tmp+2 >= n) end = true;
                    else if (s.substr(p+tmp+1, 2) == "ox") {
                        res += tmp + 3;
                        p += tmp + 3;
                    }
                    else end = true;
                }
            }
            else end = true;
        }
        if (end) break;
    }
    return (dp[p1] = res);
}

int main(){
    cin >> n >> s;
    if (n <= 3) {
        if (s == "fox") cout << 0 << endl;
        else cout << n << endl;
        return 0;
    }
    dp = vi(n+1, -1);
    int mn = INF;
    int ans = n, i = 0;
    while (i < n) {
        int res = foxlen(i);
        ans -= res;
        i += max(1, res);
    }
    mn = min(mn, ans);
    ans = n, i = 1;
    while (i < n) {
        int res = foxlen(i);
        ans -= res;
        i += max(1, res);
    }
    mn = min(mn, ans);
    ans = n, i = 2;
    while (i < n) {
        int res = foxlen(i);
        ans -= res;
        i += max(1, res);
    }
    mn = min(mn, ans);
    cout << mn << endl;
    return 0;
}

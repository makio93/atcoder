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
    int n;
    ll d;
    cin >> n >> d;
    vi a(3);
    while (d%2==0) {
        d /= 2;
        a[0]++;
    }
    while (d%3==0) {
        d /= 3;
        a[1]++;
    }
    while (d%5==0) {
        d /= 5;
        a[2]++;
    }
    if (d != 1) {
        cout << 0.0 << endl;
        return 0;
    }
    map<vi, ll> dp;
    dp[{0, 0, 0}] = 1;
    rep(i, n) {
        map<vi, ll> tmp = dp;
        for (auto p : dp) {
            vi tar = p.first; tar[0]++;
            tmp[tar] += dp[p.first];
            tar[0]++;
            tmp[tar] += dp[p.first];
            tar = p.first; tar[1]++;
            tmp[tar] += dp[p.first];
            tar = p.first; tar[2]++;
            tmp[tar] += dp[p.first];
            tar = p.first; tar[0]++; tar[1]++;
            tmp[tar] += dp[p.first];
        }
        swap(dp, tmp);
    }
    ll cnt = 0;
    for (auto p : dp) {
        bool ok = true;
        rep(i, 3) {
            if (p.first[i] < a[i]) ok = false;
        }
        if (!ok) continue;
        cnt += p.second;
    }
    double ans = cnt;
    rep(i, n) ans /= 6.0;
    printf("%.10f\n", ans);
    return 0;
}

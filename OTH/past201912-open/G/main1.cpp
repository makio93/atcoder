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
    cin >> n;
    vector<vi> a;
    a = vector<vi>(n, vi(n));
    rep(i, n-1) for (int j=i+1; j<n; ++j) {
        int aa;
        cin >> aa;
        a[i][j] = aa;
        a[j][i] = aa;
    }
    int ans = -INF;
    int t = 1;
    rep(i, n) t *= 3;
    rep(i, t) {
        vector<set<int>> g(3);
        int tmp = i;
        rep(j, n) {
            g[tmp%3].insert(j);
            tmp /= 3;
        }
        int sum = 0;
        rep(k, 3) {
            for (auto itr1=g[k].begin(); itr1!=g[k].end(); ++itr1) {
                auto itr2 = itr1;
                for (++itr2; itr2!=g[k].end(); ++itr2) {
                    sum += a[*itr1][*itr2];
                }
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

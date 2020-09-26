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

const long long mod = 998244353;
using mint = modint998244353;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<mint>> sum(10, vector<mint>(n));
    rep1(i, 9) {
        sum[i][0] = i;
        rep1(j, n-1) {
            sum[i][j] = sum[i][j-1] * 10 + i;
        }
    }
    deque<pair<int, pii>> str;
    str.emplace_back(1, make_pair(0, n-1));
    mint now = sum[1][n-1];
    rep(i, q) {
        int m, l, d;
        cin >> m >> l >> d;
        m = n-m; l = n-l;
        int li = 0, mi = 0;
        rep(j, sz(str)) {
            if (str[j].second.first<=l && str[j].second.second>=l) {
                li = j;
            }
            if (str[j].second.first<=m && str[j].second.second>=m) {
                mi = j;
            }
        }
        mint sub = 0;
        sub += sum[str[li].first][str[li].second.second] - sum[str[li].first][l-1];
        for (int j=li+1; j<mi; ++j) sub += sum[str[j].first][str[j].second.second] - sum[str[j].first][str[j].second.first-1];
        sub += sum[str[mi].first][m] - sum[str[mi].first][str[mi].second.first-1];
        str[li].second.second = l-1;
        str[mi].second.first = m+1;
        str.erase(str.begin()+li+1, str.begin()+mi-1);
        str.insert(str.begin()+li+1, make_pair(d, make_pair(l, m)));
        now -= sub;
        now += sum[d][m] - sum[d][l-1];
        cout << now << endl;
    }
    return 0;
}

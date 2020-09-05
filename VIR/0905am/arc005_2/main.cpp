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

const vs wstr = { "R", "L", "U", "D", "RU", "RD", "LU", "LD" };
const vi dy = { 0, 0, -1, 1, -1, 1, -1, 1 }, dx = { 1, -1, 0, 0, 1, 1, -1, -1 };

int main(){
    int x, y;
    string w;
    cin >> x >> y >> w;
    --x; --y;
    vs c(9);
    rep(i, 9) cin >> c[i];
    int d = distance(wstr.begin(), find(all(wstr), w));
    pii pd = { dy[d], dx[d] };
    string ans;
    rep(i, 4) {
        ans.pb(c[y][x]);
        if (y+pd.first<0 || y+pd.first>=9) pd.first *= -1;
        if (x+pd.second<0 || x+pd.second>=9) pd.second *= -1;
        y += pd.first; x += pd.second;
    }
    cout << ans << endl;
    return 0;
}

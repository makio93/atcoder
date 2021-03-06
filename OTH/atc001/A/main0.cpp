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

const string YES = "Yes";
const string NO = "No";

const vi dx = { 0, 1, 0, -1 }, dy = { -1, 0, 1, 0 };

int hm, wm;
vs c;
vector<vector<bool>> seen;
void dfs(int h, int w) {
    seen[h][w] = true;
    rep(i, 4) {
        int nh = h + dy[i], nw = w + dx[i];
        if (nh<0 || nh>=hm || nw<0 || nw>=wm) continue;
        if (c[nh][nw] == '#') continue;
        if (seen[nh][nw]) continue;
        dfs(nh, nw);
    }
}

int main(){
    cin >> hm >> wm;
    c = vs(hm);
    rep(i, hm) cin >> c[i];
    int sh = -1, sw = -1, gh = -1, gw = -1;
    rep(i, hm) rep(j, wm) {
        if (c[i][j] == 's') sh = i, sw = j;
        if (c[i][j] == 'g') gh = i, gw = j;
    }
    seen = vector<vector<bool>>(hm, vector<bool>(wm));
    seen[sh][sw] = true;
    dfs(sh, sw);
    if (seen[gh][gw]) cout << YES << endl;
    else cout << NO << endl;
    return 0;
}

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

int w, h;
vector<vi> c, ids;
const vi dj = { -1, 0, 1, -1, 1, -1, 0, 1 }, di = { -1, -1, -1, 0, 0, 1, 1, 1 };
void dfs(int i, int j, int id) {
    ids[i][j] = id;
    rep(k, 8) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni<0 || ni>=h || nj<0 || nj>=w) continue;
        if (c[ni][nj]==0 || ids[ni][nj]==id) continue;
        dfs(ni, nj, id);
    }
}

int main(){
    while (1) {
        cin >> w >> h;
        if (w==0 && h==0) break;
        c = vector<vi>(h, vi(w));
        rep(i, h) rep(j, w) cin >> c[i][j];
        ids = vector<vi>(h, vi(w, -1));
        int ans = 0;
        rep(i, h) rep(j, w) {
            if (c[i][j]==0 || ids[i][j]!=-1) continue;
            dfs(i, j, ans);
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}

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
    int n, k;
    cin >> n >> k;
    vector<vi> g(n, vi(n, INF));
    rep(i, n) g[i][i] = 0;
    rep(i, k) {
        int op;
        cin >> op;
        if (op == 0) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            cout << ((g[a][b]!=INF)?g[a][b]:-1) << endl;
        }
        else {
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            g[c][d] = min(g[c][d], e);
            g[d][c] = min(g[d][c], e);
            rep(k2, n) rep(i2, n) rep(j2, n) {
                g[i2][j2] = min(g[i2][j2], g[i2][k2]+g[k2][j2]);
            }
        }
    }
    return 0;
}

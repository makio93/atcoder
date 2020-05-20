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
    int n, q;
    cin >> n >> q;
    vector<vector<bool>> g(n, vector<bool>(n));
    rep(i, q) {
        int r;
        cin >> r;
        if (r==1) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            g[a][b] = true;
        }
        else if (r==2) {
            int a;
            cin >> a;
            --a;
            rep(j, n) {
                if (g[j][a]) g[a][j] = true;
            }
        }
        else {
            int a;
            cin >> a;
            --a;
            vi fs;
            rep(j, n) {
                if (g[a][j]) fs.pb(j);
            }
            for (int x : fs) {
                rep(j, n) {
                    if (j==a) continue;
                    if (g[x][j]) g[a][j] = true;
                }
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if (g[i][j]) cout << 'Y';
            else cout << 'N';
        }
        cout << endl;
    }
    return 0;
}

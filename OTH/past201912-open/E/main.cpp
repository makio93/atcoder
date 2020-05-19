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
    vector<vi> s(q);
    rep(i, q) {
        int j1, j2;
        cin >> j1 >> j2;
        s[i].pb(j1); s[i].pb(j2);
        if (s[i][0] == 1) {
            cin >> j1;
            s[i].pb(j1);
        }
    }
    vector<vector<bool>> g(n, vector<bool>(n));
    rep(i, q) {
        int a = s[i][1]-1;
        if (s[i][0]==1) {
            int b = s[i][2]-1;
            g[a][b] = true;
        }
        else if (s[i][0]==2) {
            rep(j, n) {
                if (g[j][a]) g[a][j] = true;
            }
        }
        else {
            vector<bool> tmp(n);
            rep(j, n) {
                if (g[a][j]) {
                    rep(k, n) {
                        if (k==a) continue;
                        if (g[j][k]) tmp[k] = true;
                    }
                }
            }
            rep(j, n) {
                if (tmp[j]) g[a][j] = true;
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

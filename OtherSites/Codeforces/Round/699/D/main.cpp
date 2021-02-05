#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

v(int) path;
v(bool) visited;
void dfs(int vi, int val=-1, int p=-1) {
    if (visited[vi])
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        v(v(int)) g(n, v(int)(n));
        rep(i, n) {
            string s;
            cin >> s;
            rep(j, n) {
                if (j == i) continue;
                g[i][j] = (int)(s[j]-'a');
            }
        }
        if (m == 1) {
            cout << "YES" << endl;
            cout << "1 2" << endl;
            continue;
        }
        p(int) same = { -1, -1 };
        rep(i, n) {
            rep(j, n) {
                if (i == j) continue;
                if (g[i][j] == g[j][i]) {
                    same = { i+1, j+1 };
                    break;
                }
            }
            if (same.first != -1) break;
        }
        if (same.first != -1) {
            cout << "YES" << endl;
            cout << same.second << ' ';
            rep(i, m) {
                if (i%2==0) printf("%d%c", same.first, (i<m-1?' ':'\n'));
                else printf("%d%c", same.second, (i<m-1?' ':'\n'));
            }
            continue;
        }
        if (m%2 == 1) {
            cout << "YES" << endl;
            cout << "2 ";
            rep(i, m) {
                if (i%2==0) printf("%d%c", (i%2)+1, (i<m-1?' ':'\n'));
                else printf("%d%c", (i%2)+1, (i<m-1?' ':'\n'));
            }
            continue;
        }
        if (n == 2) {
            cout << "NO" << endl;
            continue;
        }
        visited = v(bool)(n);
        dfs(0);
    }
    return 0;
}

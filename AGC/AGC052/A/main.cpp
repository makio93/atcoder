#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(string) s(3);
        rep(i, 3) {
            string si;
            cin >> si;
            s[i] = si + si;
        }
        v(v(p2(char,int))) runs(3);
        rep(i, 3) {
            runs[i].eb(s[i].front(), 1);
            rep2(j, 1, sz(s[i])-1) {
                if (s[i][j] == runs[i].back().first) runs[i].back().second++;
                else runs[i].eb(s[i][j], 1);
            }
        }
        rep(i2, 3) {
            string ans;
            v(int) id(3);
            bool ok = true;
            rep(i, 2*n+1) {
                char nval = s[i2][id[i2]];
                rep(j, 3) {
                    if (j == i2) continue;
                    while (id[j]<sz(s[j]) && s[j][id[j]]!=nval) id[j]++;
                    if (id[j] >= sz(s[j])) {
                        ok = false;
                        continue;
                    }
                }
                if (!ok) break;
                ans += nval;
                rep(j, 3) id[j]++;
            }
            if (ok) {
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}

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
        string ans;
        rep(i, 2) {
            v(int) id(3);
            int cnt = 0;
            bool ok = false;
            while (1) {
                bool brk = false;
                rep(j, 3) if (id[j] >= sz(s[j])) brk = true;
                if (brk) break;
                rep(j, 3) {
                    while (id[j]<sz(s[j]) && s[j][id[j]]!=(char)(i+'0')) id[j]++;
                    if (id[j] >= sz(s[j])) brk = true;
                }
                if (brk) break;
                ++cnt;
                bool ok2 = true;
                rep(j, 3) if (id[j]+1<sz(s[j]) && s[j][id[j]+1]!=(char)((1-i)+'0')) ok2 = false;
                if (ok2) {
                    ok = true;
                    break;
                }
                rep(j, 3) id[j]++;
            }
            if (!ok) continue;
            ans = string(cnt, (char)(i+'0')) + (char)((1-i)+'0') + string(2*n-cnt, (char)(i+'0'));
            break;
        }
        if (ans == "") ans = string(n, s[0][0]) + (char)(1-(s[0][0]-'0')+'0') + string(n, s[0][0]) ;
        cout << ans << endl;
    }
    return 0;
}

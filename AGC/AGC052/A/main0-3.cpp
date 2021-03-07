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
        v(string) s2(2);
        rep(i, 2) {
            v(int) id(2);
            while (id[0]<sz(s[0]) && id[1]<sz(s[1])) {
                bool brk = false;
                rep(j, 2) if (j != i) {
                    while (id[j]<sz(s[j]) && s[j][id[j]]!=s[i][id[i]]) id[j]++;
                    if (id[j] >= sz(s[j])) brk = true;
                }
                if (brk) {

                    break;
                }
                s2[i] += s[i][id[i]];
                rep(j, 2) id[j]++;
            }
        }
        v(string) s3(2);
        rep(i, 2) {
            v(int) id(2);
            while (id[0]<sz(s2[i]) && id[1]<sz(s[2])) {
                while (id[0]<sz(s2[i]) && s2[i][id[0]]!=s[2][id[1]]) id[0]++;
                if (id[0] >= sz(s2[i])) break;
                s3[i] += s[2][id[1]];
                rep(j, 2) id[j]++;
            }
        }
        if (sz(s3[0]) >= 2*n+1) cout << s3[0].substr(0, 2*n+1) << endl;
        else if (sz(s3[1]) >= 2*n+1) cout << s3[1].substr(0, 2*n+1) << endl;
        else {
            int f2 = s[2].front() - '0';
            string tmp = string(n, (char)(f2+'0')) + (char)(1-f2+'0') + string(n, (char)(f2+'0'));
            cout << tmp << endl;
        }
    }
    return 0;
}

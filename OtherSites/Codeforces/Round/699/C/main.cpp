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

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        v(int) a(n), b(n), c(m);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        rep(i, m) cin >> c[i];
        map<int, int> pcolor, acolor;
        map<int, v(int)> scolor;
        repr(i, n) {
            if (a[i] == b[i]) {
                pcolor[a[i]] = i+1;
                acolor[a[i]] = i+1;
            }
            else {
                scolor[b[i]].pb(i+1);
                acolor[b[i]] = i+1;
            }
        }
        bool painted = false, res = true;
        int fpaint = -1;
        v(int) ans(m);
        repr(i, m) {
            if (scolor.find(c[i]) != scolor.end()) {
                ans[i] = scolor[c[i]].back();
                if (!painted) {
                    painted = true;
                    fpaint = scolor[c[i]].back();
                }
                scolor[c[i]].pop_back();
                if (scolor[c[i]].empty()) scolor.erase(c[i]);
            }
            else {
                if (acolor.find(c[i]) != acolor.end()) {
                    ans[i] = acolor[c[i]];
                    if (!painted) {
                        painted = true;
                        fpaint = acolor[c[i]];
                    }
                }
                else {
                    if (painted) ans[i] = fpaint;
                    else {
                        res = false;
                        break;
                    }
                }
            }
            if (!res) break;
        }
        if (!scolor.empty()) res = false;
        if (res) {
            cout << "YES" << endl;
            rep(i, m) printf("%d%c", ans[i], (i<m-1?' ':'\n'));
        }
        else cout << "NO" << endl;
    }
    return 0;
}

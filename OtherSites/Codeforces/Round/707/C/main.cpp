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
    int n;
    cin >> n;
    vp(int) a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    VSORT(a);
    map<int, p(int)> difl, difr;
    v(int) ans(4);
    bool ok = false;
    rep2(i, 1, n-1) {
        for (int j=0; j+i<n; ++j) {
            int d = a[j+i].first - a[j].first;
            if (difl.find(d) != difl.end()) {
                if (difl[d].first > j+i) {
                    ans = { j, difl[d].second, difl[d].first, j+i };
                    ok = true;
                    break;
                }
                else if (difr[d].first < j) {
                    ans = { j, difr[d].first, difr[d].second, j+i };
                    ok = true;
                    break;
                }
                else {
                    difl[d].second *= -1;
                    difl[d] = max(difl[d], {j,-(j+i)});
                    difl[d].second *= -1;
                    difr[d].second *= -1;
                    difr[d] = min(difr[d], {j+i,-j});
                    difr[d].second *= -1;
                }
            }
            else {
                difl[d] = {j,j+i};
                difr[d] = {j+i,j};
            }
        }
        if (ok) break;
    }
    if (ok) {
        cout << "YES" << endl;
        rep(i, 4) printf("%d%c", a[ans[i]].second+1, (i<3?' ':'\n'));
    }
    else cout << "NO" << endl;
    return 0;
}

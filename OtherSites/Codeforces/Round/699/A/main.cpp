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
        int px, py;
        cin >> px >> py;
        string s;
        cin >> s;
        int tx = 0, ty = 0;
        v(int) dcnt(4);
        int n = sz(s);
        rep(i, n) {
            const string dir = "URDL";
            const v(int) dx = { 0, 1, 0, -1 }, dy = { 1, 0, -1, 0 };
            rep(i2, 4) {
                if (s[i] == dir[i2]) {
                    tx += dx[i2];
                    ty += dy[i2];
                    dcnt[i2]++;
                }
            }
        }
        bool ok = true;
        if (tx-px > 0) {
            if (dcnt[1] < abs(tx-px)) ok = false;
        }
        else if (tx-px < 0) {
            if (dcnt[3] < abs(tx-px)) ok = false;
        }
        if (ty-py > 0) {
            if (dcnt[0] < abs(ty-py)) ok = false;
        }
        else if (ty-py < 0) {
            if (dcnt[2] < abs(ty-py)) ok = false;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

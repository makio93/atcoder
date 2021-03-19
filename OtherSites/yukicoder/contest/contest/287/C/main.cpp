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
    int h, w, x;
    cin >> h >> w >> x;
    if (x%2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    if (x < h+w-2) {
        cout << -1 << endl;
        return 0;
    }
    if ((h+1)/2%2!=0 || (w+1)/2%2!=0) {
        int mxval = ((h+1)/2*(w+1)/2-1);
        if (x > mxval*2) {
            cout << -1 << endl;
            return 0;
        }
        bool r = false;
        if ((h+1)/2%2!=0 && (w+1)/2%2!=0) r = (h>=w);
        else r = ((w+1)/2%2 == 0);
        int h2 = (h+1)/2, w2 = (w+1)/2, x2 = x/2 + 1;
        int add = x2 - (h2+w2-1);
        if (add%2 != 0) {
            cout << -1 << endl;
            return 0;
        }
        if (!r) swap(h, w);
        v(string) ans(h, string(w, '.'));
        rep(i, h) rep(j, w) if (i%2!=0&&j%2!=0) ans[i][j] = '#';
        int len1 = add / ((h2-1)*2), len2 = add % ((h2-1)*2) / 2;
        for (int i=0; i<h-2; i+=2) ans[i][1] = '#';
        for (int i=0; i<len1; ++i) {
            int i2 = 2 + 4*i;
            for (int j=h-1; j>=2; j-=2) ans[j][i2+1] = '#';
            for (int j=0; j<h-2; j+=2) ans[j][i2+3] = '#';
        }
        int i3 = 2 + 4*len1;
        for (int i=h-1; i>h-2*len2-1; i-=2) ans[i][i3+1] = '#';
        for (int i=h-1-2*len2; i<h-2; i+=2) ans[i][i3+3] = '#';
        if (len2 > 0) {
            ans[h-1-2*len2-2][i3] = ans[h-1-2*len2-2][i3+2] = '#';
        }
        for (int i=h-1-2*len2-2; i>=0; i-=2) ans[i][i3+1] = ans[i][i3+3] = '#';
        for (int i=i3; i<w; i+=2) {
            ans[i][h-2] = '#';
            if (i+1>=w) continue;
            for (int j=0; j<h-2; ++j) ans[j][i+1] = '#';
        }
        if (r) rep(i, h) cout << ans[i] << endl;
        else {
            rep(i, w) {
                string tmp;
                rep(j, h) tmp += ans[j][i];
                cout << tmp << endl;
            }
        }
    }
    else cout << -1 << endl;
    return 0;
}

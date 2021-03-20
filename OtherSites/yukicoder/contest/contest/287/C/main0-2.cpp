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

// 終了後、自主研究、WA

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
    int h2 = (h+1)/2, w2 = (w+1)/2, x2 = x / 2, mxval = (h2*w2-1);
    if (h2%2==0 && w2%2==0 && x2>(h2-1)*(w2-1)+(w2-2)) {
        if (x2 > mxval-1) {
            cout << -1 << endl;
            return 0;
        }
        int add = x2 - (h2+w2-2), add2 = (add - (w2-2) * (h2-1)) / 2;
        v(string) ans(h, string(w, '.'));
        rep(i, h) rep(j, w) if (i%2!=0&&j%2!=0) ans[i][j] = '#';
        if ((add-(w2-2)*(h2-1))%2 != 0) {
            cout << -1 << endl;
            return 0;
        }
        int len1 = (w2-2) / 2;
        for (int i=0; i<h-1; i+=2) ans[i][1] = '#';
        for (int i=0; i<len1; ++i) {
            int i2 = 2 + 4*i;
            for (int j=h-1; j>=1; j-=2) ans[j][i2+1] = '#';
            if (i+1<len1) for (int j=0; j<h-1; j+=2) ans[j][i2+3] = '#';
        }
        if (add2 > 0) {
            for (int i=0; i<add2; ++i) {
                int i2 = i*4;
                ans[i2+1][w-3] = '#';
                ans[i2+3][w-1] = '#';
            }
            for (int i=add2*4; i+1<=h-1; i+=2) ans[i+1][w-3] = '#';
        }
        rep(i, h) cout << ans[i] << endl;
    }
    else {
        if (x2 > mxval) {
            cout << -1 << endl;
            return 0;
        }
        bool r = false;
        if (h2%2!=0 && w2%2!=0) r = (h2>=w2);
        else if (h2%2==0 && w2%2==0) r = true;
        else r = (w2%2 != 0); // r==true : 上下方向にジグザグする、そうじゃなかったら縦横を後で交換
        int add = x2 - (h2+w2-2);
        if (add%2 != 0) {
            cout << -1 << endl;
            return 0;
        }
        if (!r) {
            swap(h2, w2);
            swap(h, w);
        }
        v(string) ans(h, string(w, '.'));
        rep(i, h) rep(j, w) if (i%2!=0&&j%2!=0) ans[i][j] = '#';
        int len1 = add / ((h2-1)*2), len2 = add % ((h2-1)*2) / 2;
        for (int i=0; i<h-1; i+=2) ans[i][1] = '#';
        for (int i=0; i<len1; ++i) {
            int i2 = 2 + 4*i;
            for (int j=h-1; j>=1; j-=2) ans[j][i2+1] = '#';
            for (int j=0; j<h-1; j+=2) ans[j][i2+3] = '#';
        }
        int i3 = 2 + 4*len1;
        if (len2 > 0) {
            for (int i=h-1; i>=0; i-=2) if (i!=(h-1)-2*len2) ans[i][i3+1] = '#';
            if (i3+3 < w) for (int i=0; i<=h-1; i+=2) ans[i][i3+3] = '#';
            i3 += 4;
        }
        for (int j=i3; j<w; j+=2) {
            if (j+1 < w) for (int i=h-3; i>=0; i-=2) ans[i][j+1] = '#';
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
    return 0;
}

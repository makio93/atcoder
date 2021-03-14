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
    int n;
    cin >> n;
    v(int) x(n), y(n), r(n);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];
    v(v(p2(p(int),int))) ad(2, v(p2(p(int),int))(n));
    rep(i, n) ad[0][i] = { (p(int)){y[i],x[i]}, i };
    rep(i, n) ad[1][i] = { (p(int)){x[i],y[i]}, i };
    v(v(int)) sum(10001, v(int)(10001));
    rep(i, n) sum[y[i]+1][x[i]+1] = 1;
    //rep2(i, 1, 10000) rep2(j, 1, 10000) sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
    auto pcnt = [&] (int yi1, int xi1, int yi2, int xi2) {
        return sum[yi2+1][xi2+1] - sum[yi2+1][xi1] - sum[yi1][xi2+1] + sum[yi1][xi1];
    };
    auto score = [&] (v(p2(p(int),int))& adi, v(v(int))& resi) {
        double sum = 0.0;
        rep(i2, n) {
            int si = (resi[i2][2]-resi[i2][0]+1)*(resi[i2][3]-resi[i2][1]+1), ri1 = r[adi[i2].second];
            double mnval = min(si, ri1), mxval = max(si, ri1);
            double sval = 1.0 - ((mxval-mnval)/mxval)*((mxval-mnval)/mxval);
            sum += sval;
        }
        return sum;
    };
    p2(double,v(v(int))) ans = { 0.0, v(v(int))(n,v(int)(4)) };
    rep(i1, 2) {
        VSORT(ad[i1]);
        v(v(bool)) board(10000, v(bool)(10000));
        v(v(int)) res(n, v(int)(4));
        int l1 = -1, l2 = -1;
        rep(i, n) {
            int yi, xi;
            if (i1 == 0) { yi = ad[i1][i].first.first; xi = ad[i1][i].first.second; }
            else if (i1 == 1) { yi = ad[i1][i].first.second; xi = ad[i1][i].first.first; }
            int idi = ad[i1][i].second, ri = r[idi];
            v(int) yi2(2), xi2(2);
            {
                yi2[0] = yi, xi2[0] = xi;
                while (xi2[0]-1>l2 && pcnt(yi2[0],xi2[0]-1,yi2[0],xi2[0]-1)==0 && xi-xi2[0]+1<ri) --xi2[0];
                while (yi2[0]-1>l1 && pcnt(yi2[0]-1,xi2[0],yi2[0]-1,xi)==0 && (xi-xi2[0]+1)*(yi-yi2[0]+1)<ri) --yi2[0];
                while ((xi-xi2[0])*(yi-yi2[0]+1)>=ri) ++xi2[0];
            }
            {
                yi2[1] = yi, xi2[1] = xi;
                while (yi2[1]-1>l1 && pcnt(yi2[1]-1,xi2[1],yi2[1]-1,xi2[1])==0 && yi-yi2[1]+1<ri) --yi2[1];
                while (xi2[1]-1>l2 && pcnt(yi2[1],xi2[1]-1,yi,xi2[1]-1)==0 && (xi-xi2[1]+1)*(yi-yi2[1]+1)<ri) --xi2[1];
                while ((xi-xi2[1]+1)*(yi-yi2[1])>=ri) ++yi2[1];
            }
            if (abs(ri-(xi-xi2[0]+1)*(yi-yi2[0]+1))<=abs(ri-(xi-xi2[1]+1)*(yi-yi2[1]+1))) res[i] = { yi2[0], xi2[0], yi, xi };
            else res[i] = { yi2[1], xi2[1], yi, xi };
            for (int i2=res[i][0]; i2<=yi; ++i2) for (int j2=res[i][1]; j2<=xi; ++j2) board[i2][j2] = true;
            if (i+1<n) {
                if (i1==0) {
                    if (ad[i1][i+1].first.first > ad[i1][i].first.first) l1 = yi;
                    l2 = xi;
                }
                else if (i1 == 1) {
                    if (ad[i1][i+1].first.first > ad[i1][i].first.first) l2 = xi;
                    l1 = yi;
                }
            }
        }
        ans = max(ans, {score(ad[i1],res),res});
    }
    rep(i, n) cout << ans.second[i][1] << ' ' << ans.second[i][0] << ' ' << (ans.second[i][3]+1) << ' ' << (ans.second[i][2]+1) << endl;
    return 0;
}

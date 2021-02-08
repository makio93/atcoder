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
#define DEPS (1e-11)

int main(){
    ll x, y, z, w;
    cin >> x >> y >> z >> w;
    double low = y, high = x;
    while (fabs(low-high)>DEPS) {
        double cent = (low+high) / 2;
        double cval = ((cent+w)*(cent+w) - (double)z*z) * (cent*cent - (double)y*y);
        if (cval >= (double)x*x) high = cent;
        else low = cent;
    }
    double weight = sqrt(low*low-(double)y*y), height = sqrt((low+w)*(low+w)-(double)z*z);
    double area = (double)x - ((double)z*height/2.0) - ((double)y*weight/2.0) - ((weight-z)*(height-y)/2.0);
    printf("%.10f\n", area);
    return 0;
}

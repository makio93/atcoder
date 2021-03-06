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

void add(int h, int m, int& hh, int& mm) {
    if (mm < m) ++mm;
    else if (hh < h) {
        ++hh;
        mm = 0;
        if (hh >= h) {
            hh = 0;
            mm = 0;
        }
    }
    else {
        hh = 0;
        mm = 0;
    }
}

bool isok(int h, int m, int hh, int mm) {
    const v(int) mirror = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };
    int hh1 = mirror[mm/10], hh0 = mirror[mm%10], mm1 = mirror[hh/10], mm0 = mirror[hh%10];
    if (hh1<0 || hh0<0 || mm1<0 || mm0<0) return false;
    if (hh0*10+hh1>=h || mm0*10+mm1>=m) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int h, m;
        cin >> h >> m;
        string s;
        cin >> s;
        int hh = stoi(s.substr(0,2)), mm = stoi(s.substr(3,2));
        while (!isok(h,m,hh,mm)) add(h,m,hh,mm);
        string ans = (string)"" + (char)(hh/10+'0') + (char)(hh%10+'0') + ':' + (char)(mm/10+'0') + (char)(mm%10+'0');
        cout << ans << endl;
    }
    return 0;
}

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
        int n, k;
        cin >> n >> k;
        v(int) a(n);
        rep(i, n) cin >> a[i];
        map<int, int> s, l;
        int cnt = 1;
        rep(i, n) {
            map<int, int> s2 = s;
            int tval = a[i];
            for (int j=2; j*j<=tval; ++j) {
                while (tval%j==0) {
                    tval /= j;
                    s2[j]++;
                }
            }
            if (tval > 1) s2[tval]++;
            bool ok = false;
            if (a[i] != 1) {
                repi(itr, s2) {
                    if ((s2[itr->first]-l[itr->first])%2 != 0) ok = true; 
                }
            }
            if (!ok) {
                l = s;
                ++cnt;
            }
            swap(s, s2);
        }
        cout << cnt << endl;
    }
    return 0;
}
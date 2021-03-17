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
        v(int) a(n);
        rep(i, n) cin >> a[i];
        map<int, int> mcnt;
        rep(i, n) mcnt[a[i]%m]++;
        int cnt = 0;
        if (mcnt.find(0) != mcnt.end()) ++cnt;
        if (m%2==0 && mcnt.find(m/2)!=mcnt.end()) ++cnt;
        rep2(i, 1, (m-1)/2) {
            int lval = (mcnt.find(i)!=mcnt.end()) ? mcnt[i] : 0;
            int rval = (mcnt.find(m-i)!=mcnt.end()) ? mcnt[m-i] : 0;
            if (lval==0 && rval==0) continue;
            ++cnt;
            if (lval > rval) swap(lval, rval);
            int mval = min(lval, rval);
            lval -= mval; rval -= mval;
            if (rval > 0) --rval;
            cnt += rval;
        }
        cout << cnt << endl;
    }
    return 0;
}

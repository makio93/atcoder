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
    int n, k;
    cin >> n >> k;
    v(int) a(n);
    rep(i, n) cin >> a[i];
    multiset<int> lst;
    rep(i, k) lst.insert(a[i]);
    auto titr = next(lst.begin(), (k+1)/2-1);
    int mval = *titr, nval = *titr;
    rep2(i, k, n-1) {
        int j = i-k, sub = 0;
        if (a[j] < nval) {
            lst.erase(lst.find(a[j]));
            ++sub;
        }
        else if (a[j] > nval) {
            lst.erase(lst.find(a[j]));
            --sub;
        }
        else {
            titr = lst.erase(titr);
            if ((k-1)%2==0) --sub;
        }
        if (a[i] < nval) {
            lst.insert(a[i]);
            --sub;
        }
        else if (a[i] > nval) {
            lst.insert(a[i]);
            ++sub;
        }
        else {
            lst.insert(titr, a[i]);
            --sub;
        }
        if (sub > 0) titr = next(titr, sub);
        else if (sub < 0) titr = prev(titr, abs(sub));
        nval = *titr;
        mval = max(mval, nval);
    }
    cout << mval << endl;
    return 0;
}

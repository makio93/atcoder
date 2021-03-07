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
    int n, m;
    cin >> n >> m;
    v(int) a(n);
    rep(i, n) cin >> a[i];
    map<int, int> nval;
    set<int> mex;
    rep(i, m) nval[a[i]]++;
    rep(i, n+1) if (nval.find(i) == nval.end()) mex.insert(i);
    int ans = *mex.begin(), nmex = *mex.begin();
    rep2(i, 1, n-m) {
        nval[a[i-1]]--;
        if (nval[a[i-1]] <= 0) {
            mex.insert(a[i-1]);
            nval.erase(a[i-1]);
        }
        nval[a[i+m-1]]++;
        if (nval[a[i+m-1]] == 1) mex.erase(a[i+m-1]);
        nmex = *mex.begin();
        ans = min(ans, nmex);
    } 
    cout << ans << endl;
    return 0;
}

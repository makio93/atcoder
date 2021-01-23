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

// きまぐれ精進、自力AC

int main(){
    int n, q;
    cin >> n >> q;
    v(int) a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    v(int) garden(n);
    rep(i, n) garden[i] = b[i];
    map<int, set<p(int)>> infant;
    rep(i, n) infant[b[i]].emplace(a[i], i);
    set<p(int)> leader;
    repi(itr, infant) leader.emplace(itr->second.rbegin()->first, itr->first);
    rep(i, q) {
        int c, d;
        cin >> c >> d;
        --c;
        int gi = garden[c], ai = a[c];
        garden[c] = d;
        if (infant[gi].rbegin()->second == c) {
            infant[gi].erase({ai,c});
            leader.erase({ai,gi});
            if (!infant[gi].empty()) leader.emplace(infant[gi].rbegin()->first, gi);
        }
        else infant[gi].erase({ai,c});
        if (!infant[d].empty() && *(infant[d].rbegin()) < make_pair(ai,c)) {
            auto plead = make_pair(infant[d].rbegin()->first, d);
            infant[d].emplace(ai,c);
            leader.erase(plead);
            leader.emplace(ai,d);
        }
        else if (infant[d].empty()) {
            infant[d].emplace(ai,c);
            leader.emplace(ai,d);
        }
        else infant[d].emplace(ai,c);
        cout << (leader.begin()->first) << endl;
    }
    return 0;
}

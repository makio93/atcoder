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
    v(int) a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    map<int, int> id, cnt;
    rep(i, n) {
        cnt[a[i]]++; cnt[b[i]]++;
        id[a[i]] = i; id[b[i]] = i;
    }
    int sub = 0;
    set<int> used;
    for (auto p : cnt) {
        if (p.second == 1) {
            if (used.find(id[p.first]) == used.end()) {
                used.insert(id[p.first]);
                /*
                if (a[id[p.first]] != p.second) {
                    if (cnt[a[id[p.first]]] == 1) ++sub;
                }
                else if (b[id[p.first]] != p.second) {
                    if (cnt[b[id[p.first]]] == 1) ++sub;
                }
                */
            }
            else ++sub;
        }
    }
    cout << (sz(cnt)-sub) << endl;
    return 0;
}

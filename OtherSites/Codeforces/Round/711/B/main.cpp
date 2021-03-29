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
        int n;
        ll w;
        cin >> n >> w;
        v(ll) wi(n);
        rep(i, n) cin >> wi[i];
        map<ll, int> wcnt;
        rep(i, n) wcnt[wi[i]]++;
        if (sz(wcnt) == 1) {
            int dub = (w / wcnt.begin()->first);
            int ans = (wcnt.begin()->second + (dub-1)) / (ll)dub;
            cout << ans << endl;
            continue;
        }
        auto itr = prev(wcnt.end());
        int ans = 0;
        while (!wcnt.empty()) {
            ll sum = itr->first;
            itr->second--;
            if (itr->second == 0) itr = prev(wcnt.erase(itr));
            while (!wcnt.empty()) {
                auto titr = wcnt.upper_bound(w-sum);
                if (titr == wcnt.begin()) break;
                titr = prev(titr);
                sum += titr->first;
                titr->second--;
                if (titr->second == 0) wcnt.erase(titr);
            }
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}

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

// 本番終了後、？？？？

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
        set<ll> blst;
        rep(i, 30) if ((w>>i)&1LL) blst.insert(1LL<<i);
        int pbit = 0;
        rep(i, 30) {
            if (blst.find(1LL<<i) != blst.end()) {
                rep2(j, pbit, i-1) {
                    if (wcnt.find(1LL<<j) != wcnt.end()) {
                        ll mul = 1LL<<(i-j);
                        wcnt[1LL<<i] += ((wcnt[1LL<<j]+(mul-1))/mul);
                        wcnt.erase(1LL<<j);
                    }
                }
                pbit = i + 1;
            }
        }
        int ans = 0;
        if (sz(wcnt) == 1) {
            ll dcnt = (w / wcnt.begin()->first);
            ans = (wcnt.begin()->second + (dcnt-1)) / dcnt / 2;
            cout << ans << endl;
            continue;
        }
        auto itr = prev(wcnt.end()), itr2 = wcnt.begin();
        while (!wcnt.empty()) {
            ll sum = itr->first;
            itr->second--;
            if (itr->second == 0) itr = prev(wcnt.erase(itr));
            while (!wcnt.empty() && sum+itr2->first<=w) {
                sum += itr2->first;
                itr2->second--;
                while (!wcnt.empty() && itr2->second==0) itr2 = wcnt.erase(itr2);
            }
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}

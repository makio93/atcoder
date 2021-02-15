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
    v(int) ni(4);
    rep(i, 4) cin >> ni[i];
    v(v(ll)) cost(4);
    rep(i, 4) rep(j, ni[i]) {
        ll ci;
        cin >> ci;
        cost[i].pb(ci);
    }
    rep(i, 4) { VSORT(cost[i]); }
    v(int) mi(3);
    v(v(set<int>)) nto(3);
    rep(i, 3) {
        cin >> mi[i];
        nto[i] = v(set<int>)(mi[i]);
        rep(j, mi[i]) {
            int xi, yi;
            cin >> xi >> yi;
            --xi; --yi;
            nto[i][xi].insert(yi);
        }
    }
    priority_queue<p2(ll,p(int)), v(p2(ll,p(int))), greater<p2(ll,p(int))>> que;
    int vsum = 0;
    rep(i, 4) vsum += ni[i];
    v(v(ll)) dist(6);
    dist[0] = v(ll)(1, (ll)(LINF));
    rep2(i, 1, 4) dist[i] = v(ll)(ni[i-1], (ll)(LINF));
    dist[5] = v(ll)(1, (ll)(LINF));
    rep(i, ni[0]) {
        que.emplace(cost[0][i],make_pair(1,i));
        dist[1][i] = cost[0][i];
    }
    ll ans = (ll)(LINF);
    while (!que.empty()) {
        auto pi = que.top(); que.pop();
        ll vc = pi.first;
        int vi1 = pi.second.first, vi2 = pi.second.second;
        if (vc != dist[vi1][vi2]) continue;
        if (vi1 == 4) {
            ans = min(ans, vc);
            continue;
        }
        rep(i, ni[vi1]) {
            
        }
    }
    return 0;
}

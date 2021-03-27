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

int query(int l) {
    rep(i, 3) printf("%d%c", l+i, (i<2?' ':'\n'));
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

int query(v(int) lst) {
    rep(i, 3) printf("%d%c", lst[i], (i<2?' ':'\n'));
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

v(int) merge(int l, int r) {
    int ni = r - l + 1;
    v(int) resi;
    if (ni < 3) {
        rep2(i, l, r) resi.pb(i);
        return resi;
    }
    else if (ni == 3) {
        int c = query(v(int){l,l+1,l+2});
        resi = v(int)(3);
        resi[1] = c;
        int cnt = 0;
        rep2(i, l, r) if (i != c) {
            if (cnt == 1) resi[2] = i;
            else resi[0] = i;
            ++cnt;
        }
        return resi;
    }
    else {
        bool rev = false;
        p(v(int)) resi2 = { merge(l,(l+r)/2), merge((l+r)/2+1,r) };
        int c = query((v(int)){resi2.first[0],resi2.first[1],resi2.second.front()});
        if (c==resi2.second.front()) {
            int c2 = query((v(int)){resi2.first.front(),resi2.second.front(),resi2.second.back()});
            if (c2 != resi2.second.front()) rev = true;
        }
        else {
            if (c == resi2.first[0]) {
                int c2 = query((v(int)){resi2.first[0],resi2.second.front(),resi2.second.back()});
                if (c2 == resi2.second.front()) rev = true;
            }
            else {
                int c2 = query((v(int)){resi2.first[1],resi2.second.front(),resi2.second.back()});
                if (c2 != resi2.second.front()) rev = true;
            }
        }
        if (rev) reverse(all(resi2.second));
        int id1 = 0, id2 = 0;
        while (id1+1<(int)(resi2.first.size()) && id2<(int)(resi2.second.size())) {
            int c2 = query((v(int)){resi2.first[id1],resi2.first[id1+1],resi2.second[id2]});
            if (c2 == resi2.first[id1]) {
                resi.pb(resi2.second[id2]);
                ++id2;
            }
            else if (c2 == resi2.second[id2]) {
                resi.pb(resi2.first[id1]);
                ++id1;
            }
            else {
                resi.pb(resi2.first[id1]);
                resi.pb(resi2.first[id1+1]);
                id1 += 2;
            }
        }
        if (id2 >= (int)(resi2.second.size())) {
            while (id1 < (int)(resi2.first.size())) {
                resi.pb(resi2.first[id1]);
                ++id1;
            }
        }
        if (id1==(int)(resi2.first.size())-1 && id2<(int)(resi2.second.size())) {
            while (id2<(int)(resi2.second.size())) {
                int c2 = query((v(int)){resi2.first[id1-1],resi2.first[id1],resi2.second[id2]});
                if (c2 == resi2.second[id2]) {
                    resi.pb(resi2.second[id2]);
                    ++id2;
                }
                else {
                    resi.pb(resi2.first[id1]);
                    ++id1;
                    break;
                }
            }
        }
        while (id1<(int)(resi2.first.size())) {
            resi.pb(resi2.first[id1]);
            ++id1;
        }
        while (id2<(int)(resi2.second.size())) {
            resi.pb(resi2.second[id2]);
            ++id2;
        }
        return resi;
    }
}

int main(){
    int t, n, q;
    cin >> t >> n >> q;
    rep2(i1, 1, t) {
        // int qi = q / t;
        v(int) ans = merge(1, n);
        rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
        cout.flush();
        int res;
        cin >> res;
        if (res != 1) exit(0);
    }
    return 0;
}

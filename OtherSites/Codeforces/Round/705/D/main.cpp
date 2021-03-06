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

const ll mod = (ll)(1e9)+7;

// auto mod int
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main(){
    int n, q;
    cin >> n >> q;
    v(ll) a(n), xi(q);
    rep(i, n) cin >> a[i];
    v(int) ii(q);
    rep(i, q) {
        cin >> ii[i] >> xi[i];
        ii[i]--;
    }
    vector<map<int,int>> ps(n), xps(q);
    rep(i, n) {
        int ai = a[i];
        for (int j=2; j*j<=ai; ++j) {
            while (ai%j == 0) {
                ai /= j;
                ps[i][j]++;
            }
        }
        if (ai > 1) ps[i][ai]++;
    }
    rep(i, q) {
        int txi = xi[i];
        for (int j=2; j*j<=txi; ++j) {
            while (txi%j == 0) {
                txi /= j;
                xps[i][j]++;
            }
        }
        if (txi > 1) xps[i][txi]++;
        for (auto itr=xps[i].begin(); itr!=xps[i].end(); ++itr) ps[ii[i]][itr->first] += itr->second;
    }
    map<int,int> gcdi = ps.front();
    rep2(j, 1, n-1) {
        auto ngcdi = gcdi;
        for (auto itr=ps[j].begin(); itr!=ps[j].end(); ++itr) {
            if (gcdi.find(itr->first) != gcdi.end()) {
                ngcdi[itr->first] = min(itr->second, gcdi[itr->first]);
            }
        }
        swap(gcdi, ngcdi);
    }
    v(mint) ans(q);
    repr(i, q) {
        ans[i] = 1;
        for (auto itr=gcdi.begin(); itr!=gcdi.end(); ++itr) {
            ans[i] *= mint(itr->first).pow(itr->second);
        }
        for (auto itr=xps[i].begin(); itr!=xps[i].end(); ++itr) {
            ps[ii[i]][itr->first] -= itr->second;
        }
        auto ngcdi = gcdi;
        for (auto itr=ps[ii[i]].begin(); itr!=ps[ii[i]].end(); ++itr) {
            ngcdi[itr->first] = min(itr->second, gcdi[itr->first]);
        }
        swap(gcdi, ngcdi);
    }
    rep(i, q) cout << ans[i] << endl;
    return 0;
}

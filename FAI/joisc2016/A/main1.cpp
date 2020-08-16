#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct SEG {
    int n;
    vi dat;
    SEG(int n_=1) { init(n_); }
    void init(int nt) {
        n = 1;
        while (n < nt) n *= 2;
        dat = vi(2*n-1, 0);
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[2*k+1], dat[2*k+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        if (r<=a || b<=l) return -INF;
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vpii hr(n);
    rep(i, n) cin >> hr[i].second >> hr[i].first;
    rep(i, n) hr[i].second *= -1;
    VSORT(hr);
    vector<pair<pii, int>> ba(q);
    rep(i, q) {
        cin >> ba[i].first.second >> ba[i].first.first;
        ba[i].second = i;
    }
    rep(i, q) ba[i].first.second *= -1;
    VSORT(ba);
    vi ord(q);
    rep(i, q) ord[i] = ba[i].second;
    vector<pair<pii, bool>> lis(n+q);
    rep(i, n) lis[i] = { hr[i], false };
    rep(i, q) lis[n+i] = { ba[i].first, true };
    VSORT(lis);
    vi comp;
    rep(i, n+q) comp.pb(lis[i].first.second);
    VSORT(comp);
    comp.erase(unique(all(comp)), comp.end());
    rep(i, n+q) lis[i].first.second = (lower_bound(all(comp), lis[i].first.second) - comp.begin());
    vi dp(n, INF);
    SEG sg(sz(comp));
    vi ans(q);
    int qcnt = 0;
    rep(i, n+q) {
        if (!lis[i].second) {
            int it = upper_bound(all(dp), lis[i].first.second) - dp.begin();
            dp[it] = lis[i].first.second;
            sg.update(dp[it], it+1);
        }
        else {
            ans[ord[qcnt]] = sg.query(0, lis[i].first.second+1);
            ++qcnt;
        }
    }
    rep(i, q) cout << ans[i] << endl;
    return 0;
}

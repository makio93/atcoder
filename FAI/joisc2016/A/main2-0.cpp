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

struct BIT {
    int n;
    vi bit;
    BIT(int n_=2) { init(n_); }
    void init(int tn) {
        n = 2;
        while (n < tn+1) n *= 2;
        bit = vi(n+1, 0);
    }
    int sum(int i) {
        ++i;
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        ++i;
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vpii rh(n);
    rep(i, n) cin >> rh[i].first >> rh[i].second;
    vpii ab(q);
    rep(i, q) cin >> ab[i].first >> ab[i].second;
    vpii rh2(n);
    rep(i, n) rh2[i] = rh[i];
    rep(i, n) rh2[i].second *= -1;
    VSORT(rh2);
    rep(i, n) rh2[i].second *= -1;
    set<pii> st;
    vpii np;
    rep(i, n) {
        if (rh2[i] == pii(-1, -1)) continue;
        if (st.empty()) st.emplace(rh2[i].second, i);
        else {
            auto itr = st.lower_bound({rh2[i].second, -1});
            if (itr!=st.begin()) {
                --itr;
                bool isj = false;
                int j = i;
                while (rh2[j+1].first==rh2[j].first) {
                    if ((itr->first)<rh2[j+1].second) {
                        isj = true;
                        ++j;
                    }
                    else break;
                }
                if (isj) {
                    np.emplace_back(rh2[itr->second].first, rh2[j].second);
                    itr = st.erase(itr);
                    st.emplace(rh2[j].second, j);
                    rh2[j] = {-1, -1};
                    --i;
                    continue;
                }
                np.emplace_back(rh2[itr->second].first, rh2[i].second);
                itr = st.erase(itr);
                st.emplace(rh2[i].second, i);
            }
            else st.emplace(rh2[i].second, i);
        }
    }
    vector<pair<pii, int>> b(n+q+sz(np));
    rep(i, n) b[i] = { {rh[i].first, 1}, rh[i].second };
    vector<pair<pii, int>> ab2(q);
    rep(i, q) ab2[i] = { ab[i], i };
    RSORT(ab2);
    vi ord(q);
    rep(i, q) ord[i] = ab2[i].second;
    rep(i, q) b[n+i] = { {ab[i].first, -2}, ab[i].second };
    rep(i, sz(np)) b[n+q+i] = { {np[i].first, -1}, np[i].second };
    RSORT(b);
    vi comp;
    rep(i, sz(b)) comp.pb(b[i].second);
    VSORT(comp);
    comp.erase(unique(all(comp)), comp.end());
    rep(i, sz(b)) b[i].second = lower_bound(all(comp), b[i].second) - comp.begin();
    BIT bt(sz(comp));
    vi ans(q);
    int qcnt = 0;
    rep(i, sz(b)) {
        //printf("%d %d %d\n", b[i].first.first, b[i].second, b[i].first.second);
        if (b[i].first.second == 1) bt.add(b[i].second, 1);
        else if (b[i].first.second == -1) bt.add(b[i].second, -1);
        else {
            ans[ord[qcnt]] = bt.sum(b[i].second);
            ++qcnt;
        }
    }
    rep(i, q) cout << ans[i] << endl;
    return 0;
}

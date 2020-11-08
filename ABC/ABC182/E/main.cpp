#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vi a(n), b(n), c(m), d(m);
    rep(i, n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    rep(i, m) {
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
    }
    vector<set<pii>> hs(h), ws(w);
    rep(i, h) {
        hs[i].emplace(0, 0);
        hs[i].emplace(w+1, 0);
    }
    rep(i, w) {
        ws[i].emplace(0, 0);
        ws[i].emplace(h+1, 0);
    }
    rep(i, n) {
        hs[a[i]].emplace(b[i]+1, 1);
        ws[b[i]].emplace(a[i]+1, 1);
    }
    rep(i, m) {
        hs[c[i]].emplace(d[i]+1, 0);
        ws[d[i]].emplace(c[i]+1, 0);
    }
    int cnt = 0;
    rep(i, h) rep(j, w) {
        bool hok = false;
        auto hitr = hs[i].lower_bound({j+1, 0});
        if (hitr->first == j+1) {
            if (hitr->second == 1) {
                ++cnt;
                hok = true;
            }
        }
        else {
            if (hitr->second == 1) {
                ++cnt;
                hok = true;
            }
            else {
                --hitr;
                if (hitr->second == 1) {
                    ++cnt;
                    hok = true;
                }
            }
        }
        if (hok) continue;
        auto witr = ws[j].lower_bound({i+1, 0});
        if (witr->first == i+1) {
            if (witr->second == 1) {
                ++cnt;
            }
        }
        else {
            if (witr->second == 1) {
                ++cnt;
            }
            else {
                --witr;
                if (witr->second == 1) {
                    ++cnt;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

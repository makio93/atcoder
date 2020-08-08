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

int main(){
    int n, m, sn;
    cin >> n >> m >> sn;
    vs s(n);
    rep(i, n) cin >> s[i];
    vector<vi> a(n, vi(n));
    rep(i, n) rep(j, n) {
        if (s[i][j] == '.') a[i][j] = 0;
        else a[i][j] = s[i][j] - '0';
    }
    int tcol = -1, ty = -1, tx = -1;
    bool brk = false;
    rep(i, n-m+1) rep(j, n-m+1) if (!brk) {
        if (a[i][j] == 0) continue;
        int col = a[i][j];
        bool ok = true;
        rep(i2, m) rep(j2, m) {
            if (a[i+i2][j+j2] != col) ok = false;
        }
        if (ok) {
            tcol = col, ty = i, tx = j;
            brk = true;
        }
    }
    vector<vi> area(sn+1, vi(4, -1));
    rep1(i, sn) {
        area[i][0] = INF;
        area[i][2] = INF;
    }
    vpii emp;
    rep(i, n) rep(j, n) {
        if (a[i][j] == 0) emp.emplace_back(i, j);
        else if (a[i][j] == tcol) continue;
        else {
            int ncol = a[i][j];
            area[ncol][0] = min(area[ncol][0], j);
            area[ncol][2] = min(area[ncol][2], i);
            area[ncol][1] = max(area[ncol][1], j);
            area[ncol][3] = max(area[ncol][3], i);
        }
    }
    vi cord;
    rep1(i, sn) if (i != tcol) cord.pb(i);
    vector<vpii> cpos(sn+1);
    rep(i, sz(cord)) {
        int l = area[cord[i]][0], u = area[cord[i]][2];
        int wi = m - (area[cord[i]][1] - area[cord[i]][0]);
        int hi = m - (area[cord[i]][3] - area[cord[i]][2]);
        wi = min(wi, n-m-l), hi = min(hi, n-m-u);
        rep(i2, hi+1) rep(j2, wi+1) {
            bool ok = true;
            rep(k, sz(emp)) {
                if (!(emp[k].first>=u+i2&&emp[k].first<u+i2+m)) continue;
                if (!(emp[k].second>=l+j2&&emp[k].second<l+j2+m)) continue;
                ok = false;
            }
            if (ok) cpos[cord[i]].emplace_back(u+i2, l+j2);
        }
    }
    for (int i : cord) {
        printf("%d\n", i);
    }
        cout << "er" << endl;
        return 0;
    vi oans;
    vpii pans;
    do {
        bool res = false;
        vi ks(sz(cord), -1);
        vs tmp;
        int d;
        auto paint = [&,tmp,d] () {
            if (res) return;
            if (d == sz(cord)) {
                rep(i, m) rep(j, m) tmp[ty+i][tx+j] = (char)(tcol + '0');
                if (tmp == s) {
                    rep(i, sz(cord)) {
                        oans.pb(cord[i]);
                        pans.emplace_back(cpos[cord[i]][ks[i]].second, cpos[cord[i]][ks[i]].first);
                    }
                    oans.pb(tcol);
                    pans.emplace_back(tx, ty);
                    res = true;
                }
                return;
            }
            while (ks[d] < sz(cpos[cord[d]])) {
                ks[d]++;
                int hi = cpos[d][ks[d]].first, wi = cpos[cord[d]][ks[d]].second;
                rep(i, m) rep(j, m) tmp[hi+i][wi+i] = (char)(cord[d] + '0');
                paint(tmp, d+1);
            }
            return;
        };
        vs tmp(n, string(n, '.'));
        rep(i, sz(cord)) {
            char tc = (char)(cord[i]) + '0';
            int u = cpos[cord[i]].first, l = cpos[cord[i]].second;
            rep(i2, m) rep(j2, m) tmp[u+i2][l+j2] = tc;
        }
        rep(i2, m) rep(j2, m) tmp[ty+i2][tx+j2] = tcol;
        if (tmp == s) {
            rep(i, sz(cord)) {
                oans.pb(cord[i]);
                pans.emplace_back(cpos[cord[i]].second, cpos[cord[i]].first);
            }
            oans.pb(tcol);
            pans.emplace_back(tx, ty);
            break;
        }
    } while (next_permutation(all(cord)));
    rep(i, sz(oans)) printf("%d %d %d\n", oans[i], pans[i].first+1, pans[i].second+1);
    return 0;
}

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
        string s;
        cin >> s;
        int n = s.length();
        v(p2(char,int)) run;
        run.eb(s.front(), 1);
        rep2(i, 1, n-1) {
            if (s[i] == run.back().first) run.back().second++;
            else run.eb(s[i],1);
        }
        if (sz(run) <= 1) {
            cout << "YES" << endl;
            continue;
        }
        int l = -1, r = -1;
        rep(i, sz(run)) if (run[i].first == '1') {
            l = i;
            break;
        }
        repr(i, sz(run)) if (run[i].first == '0') {
            r = i;
            break;
        }
        if (r<l) {
            cout << "YES" << endl;
            continue;
        }
        bool ans = true, tmp = false;
        rep2(i, l, r) {
            if (run[i].second > 1) {
                if (!tmp) {
                    if (run[i].first == '1') tmp = true;
                }
                else {
                    if (run[i].first == '0') {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (!ans) {
            cout << "NO" << endl;
            continue;
        }
        tmp = false;
        rep2r(i, l, r) {
            if (run[i].second > 1) {
                if (!tmp) {
                    if (run[i].first == '0') tmp = true;
                }
                else {
                    if (run[i].first == '1') {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (!ans) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}

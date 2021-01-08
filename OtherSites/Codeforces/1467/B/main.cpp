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
        cin >> n;
        v(ll) a(n);
        rep(i, n) cin >> a[i];
        v(p2(int,ll)) lst;
        rep2(i, 1, n-2) {
            if ((a[i]<a[i-1]&&a[i]<a[i+1]) || (a[i]>a[i-1]&&a[i]>a[i+1])) lst.eb(i, a[i]);
        }
        int sub = 0;
        rep(i, sz(lst)) {
            int cnt = 1;
            if (i-1>=0 && i+1<=n-1) {
                if ((lst[i-1].first==lst[i].first-1)&&(lst[i+1].first==lst[i].first+1)) cnt = 3;
                else {
                    bool ok = false;
                    if (lst[i-1].first==lst[i].first-1) {
                        if (lst[i-1].first-2 >= 0) {
                            if (!((a[lst[i-1].first-1]<a[lst[i-1].first-2]&&a[lst[i-1].first-1]<lst[i].second) || (a[lst[i-1].first-1]>a[lst[i-1].first-2]&&a[lst[i-1].first-1]>lst[i].second))) ok = true;
                        }
                        if (lst[i].first+2 <= n-1) {
                            if (!((a[lst[i].first+1]<a[lst[i].first+2]&&a[lst[i].first+1]<lst[i-1].second) || (a[lst[i].first+1]>a[lst[i].first+2]&&a[lst[i].first+1]>lst[i-1].second))) ok = true;
                        }
                    }
                    if (lst[i+1].first==lst[i].first+1) {
                        if (lst[i].first-2 >= 0) {
                            if (!((a[lst[i].first-1]<a[lst[i].first-2]&&a[lst[i].first-1]<lst[i+1].second) || (a[lst[i].first-1]>a[lst[i].first-2]&&a[lst[i].first-1]>lst[i+1].second))) ok = true;
                        }
                        if (lst[i+1].first+2 <= n-1) {
                            if (!((a[lst[i+1].first+1]<a[lst[i+1].first+2]&&a[lst[i+1].first+1]<lst[i].second) || (a[lst[i+1].first+1]>a[lst[i+1].first+2]&&a[lst[i+1].first+1]>lst[i].second))) ok = true;
                        }
                    }
                    if (ok) cnt = 2;
                }
            }
            else if (i-1>=0) {
                if (lst[i-1].first==lst[i].first-1) {
                    bool ok = false;
                    if (lst[i-1].first-2 >= 0) {
                        if (!((a[lst[i-1].first-1]<a[lst[i-1].first-2]&&a[lst[i-1].first-1]<lst[i].second) || (a[lst[i-1].first-1]>a[lst[i-1].first-2]&&a[lst[i-1].first-1]>lst[i].second))) ok = true;
                    }
                    if (lst[i].first+2 <= n-1) {
                        if (!((a[lst[i].first+1]<a[lst[i].first+2]&&a[lst[i].first+1]<lst[i-1].second) || (a[lst[i].first+1]>a[lst[i].first+2]&&a[lst[i].first+1]>lst[i-1].second))) ok = true;
                    }
                    if (ok) cnt = 2;
                }
            }
            else if (i+1<=n-1) {
                if (lst[i+1].first==lst[i].first+1) {
                    bool ok = false;
                    if (lst[i].first-2 >= 0) {
                        if (!((a[lst[i].first-1]<a[lst[i].first-2]&&a[lst[i].first-1]<lst[i+1].second) || (a[lst[i].first-1]>a[lst[i].first-2]&&a[lst[i].first-1]>lst[i+1].second))) ok = true;
                    }
                    if (lst[i+1].first+2 <= n-1) {
                        if (!((a[lst[i+1].first+1]<a[lst[i+1].first+2]&&a[lst[i+1].first+1]<lst[i].second) || (a[lst[i+1].first+1]>a[lst[i+1].first+2]&&a[lst[i+1].first+1]>lst[i].second))) ok = true;
                    }
                    if (ok) cnt = 2;
                }
            }
            sub = max(sub, cnt);
        }
        cout << max(0, (sz(lst)-sub)) << endl;
    }
    return 0;
}

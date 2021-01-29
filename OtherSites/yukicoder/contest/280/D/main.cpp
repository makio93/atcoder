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

// わからない

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) a(n);
        bool ans = false;
        rep(h, 2) {
            set<int> pick;
            map<int, int> high, low;
            rep(i, n) {
                if (i==0) {
                    if (h==0) high[i] = a[i+1] + 1;
                    else low[i] = a[i+1] - 1;
                    if (a[i] == a[i+1]) pick.insert(i);
                }
                else if (i==n-1) {
                    if ((h==0&&n%2==0) || (h==1&&n%2==1)) low[i] = a[i-1] - 1;
                    else high[i] = a[i-1] + 1;
                    if (a[i] == a[i-1]) pick.insert(i);
                }
                else {
                    if ((h==0&&i%2==0) || (h==1&&i%2==1)) high[i] = max(a[i-1],a[i+1])+1;
                    else low[i] = min(a[i-1],a[i+1])-1;
                    if (a[i]==a[i-1]) { pick.insert(i); pick.insert(i-1); }
                    if (a[i]==a[i+1]) { pick.insert(i); pick.insert(i+1); }
                    if (a[i-1]==a[i+1]) { pick.insert(i-1); pick.insert(i+1); }
                    if ((h==0&&i%2==0) || (h==1&&i%2==1)) {
                        if (a[i-1]>a[i]) { pick.insert(i-1); pick.insert(i); }
                        if (a[i+1]>a[i]) { pick.insert(i+1); pick.insert(i); }
                    }
                    else {
                        if (a[i-1]<a[i]) { pick.insert(i-1); pick.insert(i); }
                        if (a[i+1]<a[i]) { pick.insert(i+1); pick.insert(i); }
                    }
                }
            }
            if (sz(pick) > 6) continue;
            else if (sz(pick) <= 3) {
                if (sz(pick) == 3) {

                }
                repi(itr, pick) {

                }
            }
            else {
                repi(itr, pick) for (auto itr2=next(itr); itr2!=pick.end(); ++itr) {

                }
            }
        }

    }
    return 0;
}

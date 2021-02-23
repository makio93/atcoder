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
    int a, b, k;
    cin >> a >> b >> k;
    int n = a + b;
    if (b-1==0) {
        if (k == 0) {
            string x(n, '0'), y(n, '0');
            x[0] = '1'; y[0] = '1';
            cout << "Yes" << endl;
            cout << x << endl;
            cout << y << endl;
        }
        else cout << "No" << endl;
    }
    else if (k > (n-1)-(b-1)) cout << "No" << endl;
    else {
        string x(n, '0'), y(n, '0');
        x[0] = '1';
        y[0] = '1';
        if (b-1 > 0) {
            int wid = max(1, (n-1) / (b-1)), add = (n-1) % (b-1), bcnt = b-1, pid = 1;
            while (pid<n && bcnt>0) {
                if (bcnt > add) {
                    x[pid] = '1';
                    if (k > 0) {
                        int tbi = min(k, wid-1);
                        y[pid+tbi] = '1';
                        k -= tbi;
                    }
                    else y[pid] = '1';
                    pid += wid;
                }
                else {
                    x[pid] = '1';
                    if (k > 0) {
                        int tbi = min(k, wid);
                        y[pid+tbi] = '1';
                        k -= tbi;
                    }
                    else y[pid] = '1';
                    pid += wid+1;
                }
                --bcnt;
            }
        }
        cout << "Yes" << endl;
        cout << x << endl;
        cout << y << endl;
    }
    return 0;
}

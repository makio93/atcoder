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
    int n;
    cin >> n;
    p(int) l = { 0, n+1 }, r = { n+1, n+1 };
    while (r.first-l.first > 2) {
        int c = (l.first+r.first)/2;
        cout << "? " << c << '\n';
        cout.flush();
        int cval;
        cin >> cval;
        if (cval<l.second && cval<r.second) {
            int cl, cr;
            if (c-1!=l.first) {
                cout << "? " << (c-1) << '\n';
                cout.flush();
                cin >> cl;
                if (cl > cval) {
                    l.first = c-1;
                    l.second = cl;
                    continue;
                }
            }
            else {
                cout << "? " << (c+1) << '\n';
                cout.flush();
                cin >> cr;
                if (cval < cr) {
                    r.first = c+1;
                    r.second = cr;
                    break;
                }
                else {
                    l.first = c;
                    l.second = cval;
                    break;
                }
            }
            if (c+1!=r.first) {
                cout << "? " << (c+1) << '\n';
                cout.flush();
                cin >> cr;
                if (cr > cval) {
                    r.first = c+1;
                    r.second = cr;
                    continue;
                }
            }
            else {
                cout << "? " << (c-1) << '\n';
                cout.flush();
                cin >> cl;
                if (cval < cl) {
                    l.first = c-1;
                    l.second = cl;
                    break;
                }
                else {
                    r.first = c;
                    r.second = cval;
                    break;
                }
            }
        }
        else if (cval<l.second && cval>r.second) {
            l.first = c;
            l.second = cval;
        }
        else {
            r.first = c;
            r.second = cval;
        }
    }
    cout << "! " << ((l.first+r.first)/2) << endl;
    cout.flush();
    return 0;
}

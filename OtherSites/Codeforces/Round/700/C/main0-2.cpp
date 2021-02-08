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
    if (n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    else if (n == 2) {
        int lval = -1;
        cout << "? " << 1 << '\n';
        cout.flush();
        cin >> lval;
        if (lval == 1) cout << "! " << 1 << endl;
        else cout << "! " << 2 << endl;
        return 0;
    }
    else if (n == 3) {
        int lval, rval;
        cout << "? " << 1 << '\n';
        cout.flush();
        cin >> lval;
        if (lval == 1) {
            cout << "! " << 1 << endl;
            return 0;
        }
        cout << "? " << 3 << '\n';
        cout.flush();
        cin >> rval;
        if (rval == 1) {
            cout << "! " << 3 << endl;
            return 0;
        }
        cout << "! " << 2 << endl;
        return 0;
    }
    else {
        int lval1, lval2;
        cout << "? " << 1 << '\n';
        cout.flush();
        cin >> lval1;
        cout << "? " << 2 << '\n';
        cout.flush();
        cin >> lval2;
        if (lval1 < lval2) {
            cout << "! " << 1 << endl;
            return 0;
        }
        else if (lval2 == 1) {
            cout << "! " << 2 << endl;
            return 0;
        }
        int rval1, rval2;
        cout << "? " << n << '\n';
        cout.flush();
        cin >> rval1;
        cout << "? " << (n-1) << '\n';
        cout.flush();
        cin >> rval2;
        if (rval1 < rval2) {
            cout << "! " << n << endl;
            return 0;
        }
        else if (rval2 == 1) {
            cout << "! " << (n-1) << endl;
            return 0;
        }
        int lid = 1, rid = n-1;
        int cnt = 0;
        while (rid-lid>2&&cnt<95) {
            int cid = (lid+rid) / 2;
            cout << "? " << cid << '\n';
            cout.flush();
            int cval;
            cin >> cval;
            if (cval>min(lval2,rval2)) {
                if (lval2 < rval2) {
                    rid = cid;
                    rval2 = cval;
                }
                else {
                    lid = cid;
                    lval2 = cval;
                }
            }
            else {
                int cl, cr;
                cout << "? " << (cid-1) << '\n';
                cout.flush();
                cin >> cl;
                cout << "? " << (cid+1) << '\n';
                cout.flush();
                cin >> cr;
                if (cval<cl && cval<cr) {
                    cout << cid << endl;
                    return 0;
                }
                if (cl > cr) {
                    if (lid == cid-1) {
                        cout << "! " << (cid+1) << endl;
                        return 0;
                    }
                    lid = cid-1;
                    lval2 = cl;
                }
                else {
                    if (rid == cid+1) {
                        cout << "! " << (cid-1) << endl;
                        return 0;
                    }
                    rid = cid+1;
                    rval2 = cr;
                }
            }
        }
        cout << "! " << ((lid+rid)/2) << endl;
    }
    return 0;
}

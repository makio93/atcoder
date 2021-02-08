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
    map<int, int> que;
    if (n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    else if (n == 2) {
        int lval = -1;
        cout << "? " << 1 << '\n';
        cout.flush();
        cin >> lval;
        que[1] = lval;
        if (lval == 1) cout << "! " << 1 << endl;
        else cout << "! " << 2 << endl;
        return 0;
    }
    else if (n == 3) {
        int lval, rval;
        cout << "? " << 1 << '\n';
        cout.flush();
        cin >> lval;
        que[1] = lval;
        if (lval == 1) {
            cout << "! " << 1 << endl;
            return 0;
        }
        cout << "? " << 3 << '\n';
        cout.flush();
        cin >> rval;
        que[3] = rval;
        if (rval == 1) {
            cout << "! " << 3 << endl;
            return 0;
        }
        cout << "! " << 2 << endl;
        return 0;
    }
    else {
        int lval1, lval2, cnt = 0;
        cout << "? " << 1 << '\n';
        cout.flush();
        ++cnt;
        cin >> lval1;
        que[1] = lval1;
        cout << "? " << 2 << '\n';
        cout.flush();
        ++cnt;
        cin >> lval2;
        que[2] = lval2;
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
        ++cnt;
        cin >> rval1;
        que[n] = rval1;
        cout << "? " << (n-1) << '\n';
        cout.flush();
        ++cnt;
        cin >> rval2;
        que[n-1] = rval2;
        if (rval1 < rval2) {
            cout << "! " << n << endl;
            return 0;
        }
        else if (rval2 == 1) {
            cout << "! " << (n-1) << endl;
            return 0;
        }
        int lid = 1, rid = n;
        while (rid-lid>3) {
            lid = min(lid, n);
            lid = max(lid, 1);
            rid = min(rid, n);
            rid = max(rid, 1);
            int cid = (lid+rid) / 2;
            cid = max({cid,lid+1,1});
            cid = min({cid,rid-1,n});
            int cval;
            if (que.find(cid)!=que.end()) cval = que[cid];
            else {
                if (cnt >= 100) break;
                cout << "? " << cid << '\n';
                cout.flush();
                ++cnt;
                cin >> cval;
                que[cid] = cval;
            }
            if (cval>min(lval2,rval2)) {
                if (lval2 < rval2) {
                    rid = cid;
                    rval2 = cval-1;
                }
                else {
                    lid = cid;
                    lval2 = cval-1;
                }
            }
            else {
                if (rid-lid<=4) {
                    if (cval<min(lval2,rval2)) {
                        cout << "! " << cid << endl;
                        return 0;
                    }
                    else if (lval2 < rval2) {
                        cout << "! " << (lid+1) << endl;
                        return 0;
                    }
                    else {
                        cout << "! " << (rid-1) << endl;
                        return 0;
                    }
                }
                int cl, cr;
                if (cid-1 >= lid+1) {
                    cl = lval2;
                }
                else {
                    if (que.find(cid-1)!=que.end()) cl = que[cid-1];
                    else {
                        if (cnt >= 100) break;
                        cout << "? " << (cid-1) << '\n';
                        cout.flush();
                        ++cnt;
                        cin >> cl;
                        que[cid-1] = cl;
                    }
                }
                if (cid+1 <= rid-1) {
                    cr = rval2;
                }
                else {
                    if (que.find(cid+1)!=que.end()) cr = que[cid+1];
                    else {
                        if (cnt >= 100) break;
                        cout << "? " << (cid+1) << '\n';
                        cout.flush();
                        ++cnt;
                        cin >> cr;
                        que[cid+1] = cr;
                    }
                }
                if (cval<cl && cval<cr) {
                    cout << cid << endl;
                    return 0;
                }
                if (cl > cr) {
                    if (lid+1 == cid-1) {
                        cout << "! " << (cid+1) << endl;
                        return 0;
                    }
                    lid = cid-2;
                    lval2 = cl;
                }
                else {
                    if (rid-1 == cid+1) {
                        cout << "! " << (cid-1) << endl;
                        return 0;
                    }
                    rid = cid+2;
                    rval2 = cr;
                }
            }
        }
        cout << "! " << ((lid+rid)/2) << endl;
    }
    return 0;
}

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
        map<int, int> a;
        rep(i, 2*n) {
            int ai;
            cin >> ai;
            a[ai]++;
        }
        if (a.rbegin()->second > 1) {
            cout << "NO" << endl;
            continue;
        }
        bool isyes = false;
        vp(int) alst;
        repir(itr, a) {
            if (itr == a.rbegin()) continue;
            auto ta = a;
            vp(int) alst2;
            alst2.eb(a.rbegin()->first, itr->first);
            ta.erase(a.rbegin()->first);
            ta[itr->first]--;
            if (ta[itr->first] == 0) ta.erase(itr->first);
            auto itr2 = ta.rbegin();
            int nval = a.rbegin()->first;
            bool ok = true;
            while (!ta.empty()) {
                if (ta.find(nval-(itr2->first))==ta.end()) {
                    ok = false;
                    break;
                }
                else if (itr2->first==nval-(itr2->first) && itr2->second==1) {
                    ok = false;
                    break;
                }
                alst2.eb(itr2->first, nval-(itr2->first));
                int pval1 = itr2->first, pval2 = nval-(itr2->first);
                nval = itr2->first;
                ta[pval1]--;
                if (ta[pval1]==0) ta.erase(pval1);
                ta[pval2]--;
                if (ta[pval2]==0) ta.erase(pval2);
                itr2 = ta.rbegin();
            }
            if (ok) {
                alst = alst2;
                isyes = true;
                break;
            }
        }
        if (isyes) {
            cout << "YES" << endl;
            cout << (alst[0].first+alst[0].second) << endl;
            rep(i, sz(alst)) cout << alst[i].first << ' ' << alst[i].second << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}

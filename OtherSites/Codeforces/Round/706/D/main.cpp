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
    v(int) pi(n);
    rep(i, n) cin >> pi[i];
    int mlen = 0, pre = 0;
    rep2(i, 1, n-1) {
        if (i==n-1 || (pi[i]-pi[i-1])*(pi[i+1]-pi[i])<0) {
            mlen = max(mlen, i-pre);
            pre = i;
        }
    }
    map<int, int> scnt;
    v(p(int)) slen;
    if (pi[0] > pi[1]) {
        slen.eb(0,0);
        int id = 0;
        while (id+1<n && pi[id+1]<pi[id]) {
            slen[0].second++;
            ++id;
        }
    }
    rep2(i, 1, n-2) {
        if (pi[i]-pi[i-1]>0 && pi[i]-pi[i+1]>0) {
            int llen = 0, rlen = 0, j = i;
            while (j-1>=0 && pi[j-1]<pi[j]) {
                ++llen;
                --j;
            }
            j = i;
            while (j+1<=n-1 && pi[j+1]<pi[j]) {
                ++rlen;
                ++j;
            }
            if (llen==rlen) scnt[llen]++;
            slen.eb(llen,rlen);
        }
    }
    if (pi[n-2]<pi[n-1]) {
        slen.eb(0,0);
        int id = n-1;
        while (id-1>=0 && pi[id-1]<pi[id]) {
            slen.back().first++;
            --id;
        }
    }
    if (!scnt.empty() && mlen<=scnt.rbegin()->first && scnt.rbegin()->first%2==0) {
        int acnt = 0, amax = scnt.rbegin()->first;
        rep(i, sz(slen)) {
            if (slen[i] == (p(int)){amax,amax}) {
                if ((i-1<0||slen[i-1].second<amax) && (i+1>=sz(slen)||slen[i+1].first<amax)) ++acnt;
            }
        }
        cout << acnt << endl;
    }
    else cout << 0 << endl;
    return 0;
}

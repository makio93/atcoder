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

// あらためて自力で作成、解けない

int main(){
    int n, q;
    cin >> n >> q;
    v(string) s(q);
    rep(i, q) cin >> s[i];
    rep(i, q) {
        v(p2(char,int)) len;
        len.eb(s[i][0],1);
        rep2(j, 1, n-1) {
            if (s[i][j] == len.back().first) len.back().second++;
            else len.eb(s[i][j],1);
        }
        int cnt = 0;
        while (sz(len) > 3) {
            v(p2(char,int)) nlen, nlen2, rlen = len;
            int l = 0, r = sz(len)-1, tcnt = 0, tcnt2 = 1;
            while (l < r) {
                if (len[l].first == len[r].first) {
                    nlen.eb(len[l].first,1);
                    ++l; --r;
                }
                else {
                    nlen.eb(len[r].first,1);
                    --r;
                    if (r == l) nlen.eb(len[l].first,1);
                }
                ++tcnt;
            }
            reverse(all(rlen));
            l = 0, r = sz(len)-1;
            while (l < r) {
                if (rlen[l].first == rlen[r].first) {
                    nlen2.eb(rlen[l].first,1);
                    ++l; --r;
                }
                else {
                    nlen2.eb(rlen[r].first,1);
                    --r;
                    if (r == l) nlen2.eb(rlen[l].first,1);
                }
                ++tcnt2;
            }
            if (tcnt < tcnt2) {
                cnt += tcnt;
                len = nlen;
            }
            else {
                cnt += tcnt2;
                len = nlen2;
            }
        }
        if (sz(len) == 3) {
            const v(string) tar = { "ABC", "BAC", "CBA", "BCA", "CAB", "ACB" };
            string lstr;
            rep(j, 3) lstr += len[j].first;
            rep(j, sz(tar)) if (lstr == tar[j]) cnt += (j+1)/2;
        }
        else if (sz(len) == 2) {
            if (len[0].first > len[1].first) ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}

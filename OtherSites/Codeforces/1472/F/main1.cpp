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

// 解説AC

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        map<int, int> board;
        board[n+1] = 3;
        rep(i, m) {
            int ri, ci;
            cin >> ri >> ci;
            --ri;
            board[ci] |= (1<<ri);
        }
        int pstatus = 0;
        bool pwall = true, ans = true;
        for (auto [x, val] : board) {
            if (pwall) {
                if (val != 3) {
                    pwall = false;
                    pstatus = (x + val) % 2;
                }
            }
            else {
                if (val == 3) ans = false;
                else {
                    int nstatus = (x + val) % 2;
                    if (pstatus == nstatus) ans = false;
                    else pwall = true;
                }
            }
            if (!ans) break;
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

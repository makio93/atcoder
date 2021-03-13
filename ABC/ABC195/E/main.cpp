#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int n;
string x;
v(int) seven;
v(v(int)) memo;
int dfs(int d, int m) {
    if (memo[d][m] != -1) return memo[d][m];
    if (d == n) return (memo[d][m] = (m==0?1:0));
    int tar = (x[d]=='T'?1:0);
    int res = -1;
    if (dfs(d+1,(m+seven[d])%7)==tar || dfs(d+1,m)==tar) res = tar;
    else res = (1-tar);
    return (memo[d][m] = res);
}

int main(){
    cin >> n;
    string s;
    cin >> s >> x;
    seven = v(int)(n);
    int ten = 1;
    repr(i, n) {
        seven[i] = (ten * (int)(s[i]-'0')) % 7;
        ten = ten * 10 % 7;
    }
    memo = v(v(int))(n+1, v(int)(7, -1));
    if (dfs(0, 0) == 1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n,-1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool replace(int x, int y) {
        if (find(x) == find(y)) return false;
        d[y] = d[x];
        d[x] = -1;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
};

int main(){
    int n, q;
    cin >> n >> q;
    vpii rh(n);
    rep(i, n) cin >> rh[i].first >> rh[i].second;
    rep(i, n) rh[i].second *= -1;
    VSORT(rh);
    rep(i, n) rh[i].second *= -1;
    vi h(n);
    rep(i, n) h[i] = rh[i].second;
    vi dp(n, INF), dpi(n, -1);
    UnionFind uf(n);
    int cnt = 0;
    rep(i, n) {
        int j = lower_bound(all(dp), h[i]) - dp.begin();
        if (dp[j]==INF && j-1>=0) uf.unite(dpi[j-1], i);
        else if (j-1 >= 0) uf.replace(dpi[j], i);
        dp[j] = h[i];
        dpi[j] = i;
    }
    
    return 0;
}

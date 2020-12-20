#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// UnionFind
struct UnionFind {
    vector<int> par;
    UnionFind(int n=0): par(n,-1) {}
    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -par[find(x)];}
};

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        set<int> st;
        vector<vi> tel(n);
        vpii xy(m);
        int ans = 0;
        rep(i, m) {
            cin >> xy[i].first >> xy[i].second;
            xy[i].first--; xy[i].second--;
            if (xy[i].first == xy[i].second) continue;
            st.insert(i);
            tel[xy[i].first].pb(i);
            tel[xy[i].second].pb(i);
            ++ans;
        }
        rep(i, m) if (sz(tel[i]) == 1) {
            st.erase(tel[i].back());
        }
        vector<vi> tel2(m);
        snuke(st, itr) {
            tel[xy[*itr].first].pb(*itr);
            tel[xy[*itr].second].pb(*itr);
        }
        UnionFind uf(m);
        rep(i, m) if (sz(tel2[i]) >= 2) {
            rep(j, sz(tel2[i])-1) uf.unite(tel2[i][j], tel2[i][j+1]);
        }
        set<pii> cnt;
        rep(i, m) if (uf.size(i) >= 1) {
            cnt.emplace(uf.find(i), uf.size(i));
        }
        snuke(cnt, itr) ans += ((itr->second)>=2?2:(st.find(itr->first)!=st.end()?1:0));
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int n;
vpii ab;
int gl, gr;
void dfs(int v, int s) {
    if (ab[v] != pii(-1, -1)) return;
    if (s <= 1) ab[v] = { gl, gr };
    else if (s==2) {
        ab[v] = { v, v+1 };
        dfs(v, 1);
        dfs(v+1, 1);
    }
    else {
        if (s%2 == 1) {
            int llen = max(1, (s-1)/2), rlen = max(1, (s-1)/2);
            int nl = v - llen + (llen-1)/2, nr = v + 1 + (rlen-1)/2;
            ab[v] = { nl, nr };
            dfs(nl, llen);
            dfs(nr, rlen);
        }
        else {
            int llen = max(1, s/2-1), rlen = max(1, s/2);
            int nl = v - llen + (llen-1)/2, nr = v + 1 + (rlen-1)/2;
            ab[v] = { nl, nr };
            dfs(nl, llen);
            dfs(nr, rlen);
        }
    }
}

int main(){
    cin >> n;
    ab = vpii(n, { -1, -1 });
    if (n == 1) ab[0] = { 0, 0 };
    else {
        int llen = n/2, rlen = n/2;
        if (n%2 == 1) {
            llen = n/2;
            rlen = n/2+1;
        }
        int nl = (llen-1)/2, nr = llen + (rlen-1)/2;
        gl = nl; gr = nr;
        dfs(nl, llen);
        dfs(nr, rlen);
    }
    rep(i, n) cout << (ab[i].first+1) << ' ' << (ab[i].second+1) << endl;
    return 0;
}

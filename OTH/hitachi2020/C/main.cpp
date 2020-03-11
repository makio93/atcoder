#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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

vi g[200005];
int d[200005];

void dfs(int c, int s=0, int p=-1) {
    d[c] = s;
    for (int a : g[c]) {
        if (a == p) continue;
        dfs(a, s^1, c);
    }
}

int main(){
    int n;
    cin >> n;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    vi e, o;
    rep(i, n) {
        if (d[i]) e.push_back(i);
        else o.push_back(i);
    }
    vector<vi> st(3);
    rep1(i, n) st[i%3].push_back(i);
    if (e.size() > o.size()) swap(e, o);
    vi ans(n);
    if (e.size() <= st[0].size()) {
        for (int a : e) {
            ans[a] = st[0].back();
            st[0].pop_back();
        }
        for (int a : o) {
            rep(i, 3) {
                if (st[i].empty()) continue;
                ans[a] = st[i].back();
                st[i].pop_back();
                break;
            }
        }
    } 
    else {
        for (int a : e) {
            repr(i, 2) {
                if (st[i].empty()) continue;
                ans[a] = st[i].back();
                st[i].pop_back();
                break;
            }
        }
        for (int a : o) {
            repr(i, 3) {
                if (st[i].empty()) continue;
                ans[a] = st[i].back();
                st[i].pop_back();
                break;
            }
        }
    }
    rep(i, n) {
        cout << ans[i];
        printf("%c", i<n-1?' ':'\n');
    }
    return 0;
}

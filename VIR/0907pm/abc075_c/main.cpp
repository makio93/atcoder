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

int n;
vector<vi> g;
set<pii> st;
vi visited, finished;
void dfs(int v, int p) {
    visited.pb(v);
    for (int t : g[v]) {
        if (t == p) continue;
        if (find(all(finished),t) != finished.end()) continue;
        if (find(all(visited),t)!=visited.end() && find(all(finished),t)==finished.end()) {
            st.emplace(v, t);
            st.emplace(t, v);
            repr(i, sz(visited)-1) {
                st.emplace(visited[i], visited[i+1]);
                st.emplace(visited[i+1], visited[i]);
                if (visited[i] == t) break;
            }
            continue;
        }
        dfs(t, v);
    }
    visited.pop_back();
    finished.pb(v);
}

int main(){
    int m;
    cin >> n >> m;
    g = vector<vi>(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, 0);
    int ans = m - sz(st) / 2;
    cout << ans << endl;
    return 0;
}

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

int main(){
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n==0 && m==0) break;
        vector<vi> tr(3);
        rep(i, 3) {
            int n2;
            cin >> n2;
            rep(i2, n2) {
                int t;
                cin >> t;
                --t;
                tr[i].pb(t);
            }
        }
        auto ip3 = [] (int e) {
            int res = 1;
            rep(i, e) res *= 3;
            return res;
        };
        int ans1 = 0, ans2 = 0;
        rep(i, n) ans2 += 2 * ip3(i);
        int ans = INF;
        vector<bool> d(ip3(n));
        queue<pair<vector<vi>, int>> q;
        auto ps = [&] (vector<vi> tr, int cnt) {
            int res = 0;
            rep(i, 3) {
                for (int j : tr[i]) res += i * ip3(j);
            }
            if (cnt>m || d[res] || ans!=INF) return;
            if (res==ans1 || res==ans2) ans = cnt;
            d[res] = true;
            q.push({tr, cnt});
        };
        const int from[] = {0, 1, 1, 2}, to[] = {1, 0, 2, 1};
        ps(tr, 0);
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            rep(i, 4) {
                if (p.first[from[i]].empty()) continue;
                int f = p.first[from[i]].back();
                int t = -1;
                if (!p.first[to[i]].empty()) t = p.first[to[i]].back();
                if (t > f) continue;
                p.first[from[i]].pop_back();
                p.first[to[i]].pb(f);
                ps(p.first, p.second+1);
                p.first[to[i]].pop_back();
                p.first[from[i]].pb(f);
            }
        }
        cout << (ans!=INF?ans:-1) << endl;
    }
    return 0;
}

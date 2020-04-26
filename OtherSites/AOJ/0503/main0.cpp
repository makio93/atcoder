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
                tr[i].pb(t);
            }
        }
        int ans = INF;
        queue<pair<vector<vi>, int>> q;
        auto ps = [&] (vector<vi> tr, int cnt) {
            if (cnt > m) return;
            if (int(tr[0].size())==n || int(tr[2].size())==n) {
                ans = min(ans, cnt);
            }
            q.push({tr, cnt});
        };
        const int from[] = {0, 1, 1, 2}, to[] = {1, 0, 2, 1};
        ps(tr, 0);
        while (!q.empty()&&ans==INF) {
            auto p = q.front(); q.pop();
            int pc = p.second;
            rep(i, 4) {
                vector<vi> ptr = p.first;
                if (ptr[from[i]].empty()) continue;
                int f = ptr[from[i]].back();
                int t = 0;
                if (!ptr[to[i]].empty()) t = ptr[to[i]].back();
                if (t > f) continue;
                ptr[from[i]].pop_back();
                ptr[to[i]].pb(f);
                ps(ptr, pc+1);
            }
        }
        cout << (ans!=INF?ans:-1) << endl;
    }
    return 0;
}

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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

using pull = pair<ull, ull>;

int main(){
    int t;
    cin >> t;
    rep(i, t) {
        ull n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        priority_queue<pull, vector<pull>, greater<pull>> q;
        ull ans = INF;
        map<ull, bool> app;
        app[0] = true;
        q.emplace(d, 1);
        while (1) {
            auto p = q.top(); q.pop();
            app[p.second] = true;
            if (p.second == n) {
                ans = min(ans, p.first);
                break;
            }
            if (p.second < n) {
                if (!app[p.second*2]) {
                    q.emplace(p.first+a, p.second*2);
                }
                if (!app[p.second*3]) {
                    q.emplace(p.first+b, p.second*3);
                }
                if (!app[p.second*5]) {
                    q.emplace(p.first+c, p.second*5);
                }
            }
            if (!app[p.second+1]) q.emplace(p.first+d, p.second+1);
            if (!app[p.second-1]) q.emplace(p.first+d, p.second-1);
        }
        cout << ans << endl;
    }
    return 0;
}

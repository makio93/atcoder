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
    int n, m, s;
    cin >> n >> m >> s;
    vector<vi> u, v;
    vector<vi> a(n, vi(n, INF)), b(n, vi(n, INF));
    rep(i, m) {
        int uin, vin, ain, bin;
        cin >> uin >> vin >> ain >> bin;
        --uin; --vin;
        u[uin].push_back(vin);
        u[vin].push_back(uin);
        a[uin][vin] = ain;
        a[vin][uin] = ain;
        b[uin][vin] = bin;
        b[vin][uin] = bin;
    }
    vi c(n), d(n);
    rep(i, n) {
        cin >> c[i] >> d[i];
    }
    vll d(n, INT64_MAX);
    queue<pair<int, ll>> q;
    auto ps = [&] (int i, int t) {
        if (d[i] <= t) return;
        q.push({i, t});
        d[i] = t;
    };
    ps(0, 0);
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int p1 = p.first, p2 = p.second;
        for (int i : u[p1]) {
            
        }
    }
    return 0;
}

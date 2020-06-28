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
    int d;
    cin >> d;
    vi c(26);
    rep(i, 26) cin >> c[i];
    vector<vi> s(d, vi(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vi t(d);
    rep(i, d) {
        cin >> t[i];
        t[i]--;
    }
    int m;
    cin >> m;
    vpii dq(m);
    rep(i, m) {
        cin >> dq[i].first >> dq[i].second;
        dq[i].first--; dq[i].second--;
    }
    vi last(26);
    vector<set<int>> holds(26, set<int>({0}));
    ll sum = 0;
    rep1(i, d) {
        sum += s[i-1][t[i-1]];
        last[t[i-1]] = i;
        rep(j, 26) sum -= c[j] * (i - last[j]);
        holds[t[i-1]].insert(i);
    }
    rep(i, 26) holds[i].insert(d+1);
    rep(i, m) {
        int sub = 0;
        int p = t[dq[i].first], q = dq[i].second;
        auto pi = find(all(holds[p]), dq[i].first);
        auto qi = upper_bound(all(holds[q]), dq[i].first);
        pi = holds[p].erase(pi);
        sub += (*pi - dq[i].first) * (*pi - dq[i].first + 1) / 2;
        pi--;
        sub += (dq[i].first - *pi) * (dq[i].first - *pi + 1) / 2;
        auto qti = qi;
        qi--;
        sub += (*qti - *qi) * (*qti - *qi + 1) / 2;
        int add = 0;
        auto pfi = pi;
        pi++;
        add += (*pi - *pfi) * (*pi - *pfi + 1) / 2;
        add += (*qti - dq[i].first) * (*qti - dq[i].first + 1) / 2;
        add += (dq[i].first - *qi) * (dq[i].first - *qi + 1) / 2;
        holds[q].insert(dq[i].first);
        sum = sum - sub + add;
        cout << sum << endl;
    }
    return 0;
}

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

const string YES = "YES";
const string NO = "NO";

int main(){
    vs a(10), b;
    rep(i, 10) cin >> a[i];
    bool ans = false;
    rep(i, 10) rep(j, 10) {
        b = a;
        b[i][j] = 'o';
        int n = 0;
        rep(i2, 10) rep(j2, 10) {
            if (b[i2][j2]=='o') ++n;
        }
        queue<pii> q;
        auto ps = [&] (int i, int j) {
            if (i<0||i>=10||j<0||j>=10) return;
            if (b[i][j]!='o') return;
            q.push({i, j});
            b[i][j] = ' ';
        };
        int cnt = 0;
        ps(i, j);
        while (!q.empty()) {
            pii p = q.front(); q.pop();
            ++cnt;
            int i2 = p.first, j2 = p.second;
            ps(i2+1, j2);
            ps(i2-1, j2);
            ps(i2, j2+1);
            ps(i2, j2-1);
        }
        if (cnt == n) ans = true;
    }
    cout << (ans?YES:NO) << endl;
    return 0;
}

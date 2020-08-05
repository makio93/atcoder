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

struct P {
    int y, x;
    P(int y, int x) : y(y), x(x) {}
};

int h, w;
vs am;
vector<vector<vector<vi>>> dp;
int search(P a, P b) {
    if (dp[a.y][a.x][b.y][b.x] != -1) return dp[a.y][a.x][b.y][b.x];
    if (a.y==b.y&&a.x==b.x) return dp[a.y][a.x][b.y][b.x] = 0;
    int res = INF;
    for (int hor=a.y+1; hor<=b.y; ++hor) {
        int r1 = search({a.y,a.x}, {hor-1,b.x});
        int r2 = search({hor,a.x}, {b.y,b.x});
        int val = 0;
        if (r1==0&&r2==0) {
            if (am[a.y][a.x] == am[b.y][b.x]) val = 0;
            else val = 1;
        }
        else val = max(r1, r2) + 1;
        res = min(res, val);
    }
    for (int ver=a.x+1; ver<=b.x; ++ver) {
        int r1 = search({a.y,a.x}, {b.y,ver-1});
        int r2 = search({a.y,ver}, {b.y,b.x});
        int val = 0;
        if (r1==0&&r2==0) {
            if (am[a.y][a.x] == am[b.y][b.x]) val = 0;
            else val = 1;
        }
        else val = max(r1, r2) + 1;
        res = min(res, val);
    }
    return (dp[a.y][a.x][b.y][b.x] = res);
}

int main(){
    cin >> h >> w;
    am = vs(h);
    rep(i, h) cin >> am[i];
    dp = vector<vector<vector<vi>>>(h, vector<vector<vi>>(w, vector<vi>(h, vi(w, -1))));
    cout << search({0,0}, {h-1,w-1}) << endl;
    return 0;
}

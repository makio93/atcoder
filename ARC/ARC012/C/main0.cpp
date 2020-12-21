#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

// きまぐれでこの問題だけ自力AC

const string YES = "YES";
const string NO = "NO";

vs t;
pair<bool, bool> check() {
    pair<bool, bool> res = { false, false };
    const vi dy = { -1, 0, 1, 1 }, dx = { 1, 1, 1, 0 };
    rep(i, 19) rep(j, 19) {
        if (t[i][j] == '.') continue;
        bool exist = false;
        rep(k, 4) {
            int ny = i+dy[k]*4, nx = j+dx[k]*4;
            if (ny<0 || ny>=19 || nx<0 || nx>=19) continue;
            bool exist2 = true;
            rep1(k2, 4) {
                int ny2 = i+dy[k]*k2, nx2 = j+dx[k]*k2;
                if (t[i][j] != t[ny2][nx2]) exist2 = false;
            }
            if (exist2) {
                exist = true;
                break;
            }
        }
        if (exist) {
            if (t[i][j] == 'o') res.first = true;
            else if (t[i][j] == 'x') res.second = true;
        }
    }
    return res;
}

int main(){
    vs b(19);
    rep(i, 19) cin >> b[i];
    pii cnt = { 0, 0 };
    rep(i, 19) rep(j, 19) {
        if (b[i][j] == 'o') cnt.first++;
        else if (b[i][j] == 'x') cnt.second++;
    }
    bool ans = false;
    t = b;
    auto status = check();
    if (status == pair<bool, bool>({ false, false })) {
        if (cnt.first==cnt.second || cnt.first-1==cnt.second) ans = true;
    }
    else if (status == pair<bool, bool>({ true, false })) {
        if (cnt.first-1==cnt.second) {
            bool ok = false;
            rep(i, 19) rep(j, 19) {
                if (b[i][j] != 'o') continue;
                t = b;
                t[i][j] = '.';
                auto status2 = check();
                if (status2 == pair<bool, bool>({ false, false })) ok = true;
            }
            ans = ok;
        }
    }
    else if (status == pair<bool, bool>({ false, true })) {
        if (cnt.first==cnt.second) {
            bool ok = false;
            rep(i, 19) rep(j, 19) {
                if (b[i][j] != 'x') continue;
                t = b;
                t[i][j] = '.';
                auto status2 = check();
                if (status2 == pair<bool, bool>({ false, false })) ok = true;
            }
            ans = ok;
        }
    }
    if (ans) cout << YES << endl;
    else cout << NO << endl;
    return 0;
}

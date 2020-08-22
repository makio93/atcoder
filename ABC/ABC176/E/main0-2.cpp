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

int main(){
    int h, w, m;
    cin >> h >> w >> m;
    map<pii, bool> bomb;
    vi hcnt(h), wcnt(w);
    rep(i, m) {
        int hi, wi;
        cin >> hi >> wi;
        --hi; --wi;
        bomb[{hi,wi}] = true;
        hcnt[hi]++;
        wcnt[wi]++;
    }
    int hmx = 0, wmx = 0;
    vi hlis, wlis;
    rep(i, h) hmx = max(hmx, hcnt[i]);
    rep(i, h) if (hcnt[i] == hmx) hlis.pb(i);
    rep(i, w) wmx = max(wmx, wcnt[i]);
    rep(i, w) if (wcnt[i] == wmx) wlis.pb(i);
    bool exist = true;
    int cnt = 0;
    rep(i, sz(hlis)) rep(j, sz(wlis)) {
        if (!bomb[{hlis[i],wlis[j]}]) exist = false;
        if (cnt>3e5) {
            cout << (hmx+wmx) << endl;
            return 0;
        }
        ++cnt;
    }
    if (exist) cout << (hmx+wmx-1) << endl;
    else cout << (hmx+wmx) << endl;
    return 0;
}

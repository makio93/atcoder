#include <bits/stdc++.h>
using namespace std;

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

int f(int n) {
    if (n == 0) return 0;
    else return f(n%__builtin_popcount(n))+1;
}

int main(){
    int n;
    cin >> n;
    string x;
    cin >> x;
    vi xi(n);
    rep(i, n) xi[i] = x[i] - '0';
    int pc = 0;
    rep(i, n) if (xi[i] == 1) ++pc;
    vi ans(n);
    rep(b, 2) {
        int npc = (b==0?pc+1:pc-1);
        if (npc <= 0) continue;
        int pfx = 0;
        rep(i, n) {
            pfx = (pfx*2)%npc;
            pfx = (pfx+xi[i])%npc;
        }
        int k = 1;
        repr(i, n) {
            if (xi[i] == b) ans[i] = (b==0?f((pfx+k)%npc):f((pfx-k+npc)%npc))+1;
            k = (k*2)%npc;
        }
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}

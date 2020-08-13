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
    int res = 0;
    while (n != 0) {
        n = n % __builtin_popcount(n);
        ++res;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    string x;
    cin >> x;
    int popx = 0;
    rep(i, n) if (x[i] == '1') ++popx;
    vi popa(n), popb(n);
    int xi = 1;
    rep(i, n) {
        popa[i] = xi % (popx+1);
        xi = (xi * 2) % (popx+1);
    }
    if (popx-1>0) {
        xi = 1;
        rep(i, n) {
            popb[i] = xi % (popx-1);
            xi = (xi * 2) % (popx-1);
        }
    }
    int xmoda = 0, xmodb = 0;
    rep(i, n) if (x[n-i-1] == '1') {
        xmoda = (xmoda + popa[i]) % (popx+1);
        if (popx-1>0) xmodb = (xmodb + popb[i]) % (popx-1);
    }
    rep(i, n) {
        int fxi = 0;
        if (x[i] == '1') {
            if (popx-1>0) fxi = (xmodb - popb[n-i-1] + (popx-1)) % (popx-1);
            else {
                cout << 0 << endl;
                continue;
            }
        }
        else {
            fxi = (xmoda + popa[n-i-1]) % (popx+1);
        }
        cout << (1+f(fxi)) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int main(){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1==r2 && c1==c2) cout << 0 << endl;
    else if (r1+c1==r2+c2 || r1-c1==r2-c2 || abs(r1-r2)+abs(c1-c2)<=3) {
        cout << 1 << endl;
    }
    else if ((r1+c1)%2 == (r2+c2)%2) cout << 2 << endl;
    else {
        bool ok = false;
        for (int d=-3; d<=3; ++d) {
            int rt = r2+d, ct = c2+d;
            if (r1+c1==rt+c2 || r1-c1==rt-c2 || abs(r1-rt)+abs(c1-c2)<=3) ok = true;
            if (r1+c1==r2+ct || r1-c1==r2-ct || abs(r1-r2)+abs(c1-ct)<=3) ok = true;
        }
        if (ok) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}

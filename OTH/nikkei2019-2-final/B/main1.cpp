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

const int smax = 500;
bool dub[smax][smax];

int calc(string s)
{
    int ans = 0, n;
    n = s.size();
    rep(i, n) {
        rep1(j, n) {
            if (i+j*2>=n) continue;
            bool same = true;
            rep(k, j) {
                if (s[i+k]!=s[i+j+k]) {
                    same = false;
                    break;
                }
            }
            if (same) dub[i][i+j*2-1] = true;
        }
    }
    for (int i=1; i<n; i++) {
        for (int j1=i,j2=n-1; j1>=1; --j1,--j2) {
            if (s[j1]!=s[j2]) break;
            for (int k=i+1; k<j2-1; k++) {
                if (dub[i+1][k]) ++ans;
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << calc(s) << endl;
    return 0;
}

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

const string NO = "NO";

int main(){
    string c;
    cin >> c;
    int score = 0;
    int n = sz(c);
    rep(i, n) {
        score += c[i] - 'a' + 1;
    }
    string ans;
    if (n>1 && c!=string(n,'z')) {
        rep(i, 20) {
            if (score >= 26) {
                ans.pb((char)(26 + 'a' - 1));
                score -= 26;
            }
            else {
                ans.pb((char)(score + 'a' - 1));
                score = 0;
            }
            if (score <= 0) break;
        }
    }
    else if (n<20 && c!="a") {
        char t = c.front() - 1;
        int code = t - 'a' + 1;
        rep(i, 20) {
            if (i == 1) code = 26;
            if (score >= code) {
                ans.pb((char)(code + 'a' - 1));
                score -= code;
            }
            else {
                ans.pb((char)(score+'a'-1));
                score = 0;
            }
            if (score <= 0) break;
        }
    }
    else ans = c;
    if (ans == c) cout << NO << endl;
    else cout << ans << endl;
    return 0;
}

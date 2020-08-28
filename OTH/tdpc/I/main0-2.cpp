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

string s;
int n;
vector<vi> dp;
int search(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int len = r-l;
    if (len < 3) return (dp[l][r] = 0);
    if (len==3 && s.substr(l, 3)=="iwi") return (dp[l][r] = 1);
    int res = 0;
    for (int k=l+1; k<r; ++k) res = max(res, search(l, k)+search(k, r));
    if (len >= 6) {
        int slen = (len-3)/3*3;
        for (int j=l+1; j+slen-1<r; ++j) if (search(j, j+slen)==slen/3) {
            for (int j2=max(l,j-2); j2<j; ++j2) {
                string t = s.substr(j2, j-j2) + s.substr(j+slen, (j2+3)-j);
                if (t == "iwi") res = max(res, search(l,j2)+slen/3+1+search(j2+slen+3,r));
            }
        }
    }
    if (len >= 9) {
        for (int j1=l; j1<r; ++j1) for (int j2=j1+4; j2<r; j2+=3) for (int j3=j2+4; j3<r; j3+=3) {
            string t = { s[j1], s[j2], s[j3] };
            if (t == "iwi") {
                if (search(j1+1,j2)==(j2-j1-1)/3 && search(j2+1,j3)==(j3-j2-1)/3) {
                    res = max(res, search(l,j1)+(j2-j1-1)/3+(j3-j2-1)/3+search(j3+1,r)+1);
                }
            }
        }
    }
    return (dp[l][r] = res);
}

int main(){
    cin >> s;
    n = sz(s);
    dp = vector<vi>(n+1, vi(n+1, -1));
    cout << search(0, n) << endl;
    return 0;
}
